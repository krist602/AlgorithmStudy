//Programmers > 이분탐색 > 징검다리
//https://programmers.co.kr/learn/courses/30/lessons/43236

	//거리를 하나로 정한 이후, 그 거리에 바위를 끼워넣어보고 결과값을 비교해본다.

#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0, min = 1, max = distance, mid; //바위 사이의 거리가 최소일 경우는 1, 최대일 경우는 distance-1이다. (바위가 1개인 경우) 하지만 BinarySearch를 이용할 것이기에 그냥 distance로 넣었다.

	sort(rocks.begin(), rocks.end()); //바위 사이의 거리를 보기 위해 정렬해줬다.

	while (min <= max) //min값이 max보다 작을 때만 반복하도록 반복문 선언.
	{
		int count = 0, cur_loc = 0; //count는 제거한 바위의 수, cur_loc는 현재 위치이다.
		mid = (min + max) / 2; //mid에는 min과 max의 중간값을 넣어준다.

		for (int i = 0; i < rocks.size(); i++) //끝 바위까지 탐색을 반복한다.
			if (rocks[i] - cur_loc < mid) //현재 위치와 다음 바위까지의 거리가 mid보다 작은 경우 바위를 제거한다.
				count++;
			else //현재 위치와 다음 바위까지의 거리가 mid보다 큰 경우 현재 위치를 다음 바위로 설정한다.
				cur_loc = rocks[i];

		if (count <= n) //제거한 바위 수가 n보다 적다면
		{
			if (answer < mid) //answer와 mid값을 비교하고 mid값이 더 크다면 answer에 mid값을 넣어준다.
				answer = mid;
			min = mid + 1; //더 큰 경우가 있는지 탐색하기 위해 min값을 mid보다 뒤로 보낸다.
		}
		else //제거한 바위 수가 n보다 많다면 거리가 너무 긴 것이기 때문에
			max = mid - 1; //max값을 mid보다 앞으로 보낸다.
	}

	return answer;
}