//Baekjoon > 11053 > 가장 긴 증가하는 부분 수열
//https://www.acmicpc.net/problem/11053

	//DP문제
	//i번째 칸 기준으로 0번까지 탐색하면서 DP를 갱신한다.
	//처음엔 DFS로 푸니까 시간초과 나왔었다.
	//DP인지는 도대체들 어떻게 아는 걸까

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, MAX = 0;
	cin >> N;
	vector<int> Arr(N);
	vector<int> DP(N);

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	DP[0] = 1;

	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (Arr[i] > Arr[j])
				DP[i] = max(DP[i], DP[j] + 1);

		MAX = max(DP[i], MAX);
	}

	cout << MAX << "\n";

	return 0;
}
