//Baekjoon > 9465 > 스티커
//https://www.acmicpc.net/problem/9465

	//드디어 DP문제 처음부터 DP로 푼 것 같다
	//점화식 세우는게 좀 어려웠다. 하지만 DP는 원래 식만 세우면 문제 해결이라...
	//DP도 많이 풀면 좀 쉬워지려나 싶다

#include <iostream>
#include <vector>

using namespace std;

int main()

{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0, n = 0;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n + 1, 0));
		vector<vector<int>> DP(2, vector<int>(n + 1, 0));

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> sticker[i][j];

		DP[0][1] = sticker[0][1];
		DP[1][1] = sticker[1][1];

		for (int c = 2; c <= n; c++)
		{
			for (int r = 0; r < 2; r++)
			{
				DP[0][c] = max(DP[1][c - 1] + sticker[0][c], DP[1][c - 2] + sticker[0][c]);
				DP[1][c] = max(DP[0][c - 1] + sticker[1][c], DP[0][c - 2] + sticker[1][c]);
			}
		}

		cout << max(DP[0][n], DP[1][n]) << "\n";
	}

	return 0;
}
