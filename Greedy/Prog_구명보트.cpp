//Programmers > 탐욕법(Greedy) > 구명보트
//https://programmers.co.kr/learn/courses/30/lessons/42885


	//내가 풀었던 방식은 아래에 주석처리 해놨다.
	//효율성 0점.
	//일단 내 코드는 for문이 2개가 필요하다.
	//내가 푼 방식은 내림차순으로 정렬한 이후, 완전탐색을 했다.
	//큰 수들부터 넣어준다면 당연히 최대한의 수를 더해주니 답은 맞게 나오지만, 효율성이 떨어진다.
	//또한 사람이 추가될 때마다 첫 배부터 다시 확인해야해서 반복문이 길어진다. 
	//
	//일단 내가 잘못 생각한 부분은, 무거운 사람 중에 가벼운 사람과 가벼운 사람 중에 무거운 사람을 더해줘야 최적이 나온다고 생각한 것이다.
	//반대로 생각해보면 가장 무거운 사람과 가장 가벼운 사람만 더해주면 된다. 왜냐하면 구명보트의 최대 인원은 2명이기 때문. 
	//만약 2명 제한이 없었다면 내가 푼 코드가 맞았을 것. 
	// 
	//모범 답안을 보면, 가장 무거운 사람과 가장 가벼운 사람을 더해준다. 또한 탐색을 양쪽에서 동시에 하기 때문에 end변수와 begin변수를 사용.
	// 
	//답안의 자세한 설명은 아래에 주석으로.
	//



#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0, cnt = 0, end = 1, begin = 0; //cnt는 현재까지 담은 사람의 수, end는 가장 무거운 사람의 위치, begin은 가장 가벼운 사람의 위치
	sort(people.begin(), people.end()); //오름차순으로 정렬해준다. (무조건 오름차순일 필요는 없이 내림차순으로 해줘도 된다. 아래 코드만 바꾸면.)

	while (true)
	{
		cnt++; //가장 무거운 사람은 언제나 싣는 것으로 계산.
		if (limit - people[people.size() - end++] >= people[begin]) 
			//if문을 실행하면서 end++를 올리기 때문에 가장 무거운 사람이 실린다. 
			//limit에서 그 사람의 무게를 뺀 값에 가장 가벼운 사람이 들어가는지 검사
		{
			begin++; //들어왔다면, 가장 무거운 사람과 가장 가벼운 사람을 실었기 때문에 begin을 올려준다.
			cnt++; //사람수 ++
		}
		answer++; //보트 한개의 계산이 끝났기 때문에 answer를 올려준다.
		if (cnt >= people.size()) //모든 사람을 실었다면 break
			break;
	}
	return answer;
}

/*
bool cmp(int a, int b)
{
	return a > b;
}

int solution(vector<int> people, int limit) {
	int answer = 0,ship = 0, cnt=people.size();
	sort(people.begin(), people.end(),cmp);

	vector<pair<int, int>> boat(people.size());

	for (int i = 0; i < people.size(); i)
	{
		if (boat[ship].first + people[i] <= limit && boat[ship].second < 2)
		{
			boat[ship].first += people[i];
			boat[ship].second++;
			cnt--;
			i++;
			if (cnt == 0)
				break;
			ship = 0;
		}
		else
			ship++;
	}

	for (int i = 0; i < boat.size(); i++)
		if (boat[i].second != 0)
			answer++;

	return answer;
}
*/
