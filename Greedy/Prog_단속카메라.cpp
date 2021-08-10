//Programmers > 탐욕법(Greedy) > 단속카메라
//https://programmers.co.kr/learn/courses/30/lessons/42884

	//begin과 end를 비교해서 겹치는 위치에 카메라를 추가한다고 생각했다.
	//또한 진입 지점순으로, 같을 시에는 진출 지점순으로 정렬을 해주면, 비교가 쉬워진다.
	//

#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
	int answer = 0, begin, end, index = 0;
	sort(routes.begin(), routes.end(), cmp); //진입 지점이 더 낮을 수록, 같을 때는 진출 지점이 더 낮을 수록 앞으로 가도록.

	for (int i = 0; i < routes.size(); i)
	{
		begin = routes[i][0]; //가장 낮은 숫자라고 생각하면 된다.
		end = routes[i][1]; //그 차량의 진출 지점이다.
		answer++; //카메라++
		for (int j = i + 1; j < routes.size(); j++) //다음 차량부터 비교하도록 j=i+1을 넣어준다.
		{
			begin < routes[j][0] ? begin = routes[j][0] : begin; //현재 begin과 다음 차량들의 진입 지점을 비교해서 더 큰 값을 저장.
			end < routes[j][1] ? end : end = routes[j][1]; //현재 end와 다음 차량들의 진출 지점을 비교해서 더 작은 값을 저장.
			if (begin > end) //만약 begin과 end가 안겹친다면 break;
				break;
			index = j; //begin과 end 사이에 겹치는 부분이 있다면 index를 올려준다.
		}
		i = ++index; //일련의 검색이 끝나면 그 다음 탐색은 index보다 1이 더 높은 곳에서 시작해야한다.
					 //처음 오류는 i=index+1 로 해줘서 발생했는데, 그 이유는 index=j라고 짜여있는 곳에 가지 못한다면 계속 같은 곳을 반복하기 때문.
	}

	return answer;
}