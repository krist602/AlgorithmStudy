//Baekjoon > 2579 > 계단 오르기
//https://www.acmicpc.net/problem/2579

	//처음엔 dfs로 풀었다. 근데 시간 초과 나옴
	//그래서 dfs를 역으로 추적하도록 바꿨다. 그래도 시간 초과 나옴
	//DP문제라는 것을 그 이후에 알았다. 
	//DP[i] 못만들어서 검색했다. DP[i - 3] + stair[i - 1] + stair[i]

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int stair[310] = { 0 };
	int DP[310] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> stair[i];

	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= N; i++)
		DP[i] = max(DP[i - 2] + stair[i], DP[i - 3] + stair[i - 1] + stair[i]);
	cout << DP[N] << "\n";

	return 0;
}