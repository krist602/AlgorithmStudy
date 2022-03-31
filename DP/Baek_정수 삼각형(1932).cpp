//Baekjoon > 1932 > 정수 삼각형
//https://www.acmicpc.net/problem/1932

	//DP문제이다
	//특이사항은 생각나는게 없다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	int max_sum = 0;

	vector<vector<int>> tri(N, vector<int>());
	vector<vector<int>> DP(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int tmp;
			cin >> tmp;
			tri[i].push_back(tmp);
		}
	}

	DP[0][0] = tri[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				DP[i][j] = DP[i - 1][j] + tri[i][j];
			else
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + tri[i][j];
		}
	}

	for (int i = 0; i < N; i++)
		max_sum = max(DP[N - 1][i], max_sum);

	cout << max_sum << "\n";

	return 0;
}
