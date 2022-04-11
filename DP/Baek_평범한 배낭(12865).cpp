//Baekjoon > 12865 > 평범한 배낭
//https://www.acmicpc.net/problem/12865

	//역시나 DP문제.
	//유명한 DP유형이라고 한다.

	/*
	배낭 문제는 짐을 쪼갤 수 있는 경우(무게가 소수일 수 있는 경우)와 짐을 쪼갤 수 없는 경우(이 경우 짐의 무게는 0 이상의 정수만 가능) 두 가지로 나눌 수 있는데, 
	짐을 쪼갤 수 있는 경우의 배낭 문제를 분할 가능 배낭 문제(Fractional), 
	짐을 쪼갤 수 없는 경우의 배낭 문제를 0-1 배낭 문제(0-1 Knapsack)라 부른다. - 위키백과
	*/

	//점화식은 
	//DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);   
	//(i는 넣는 짐, j는 배낭이 수용 가능한 무게)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	cin >> N >> K;
	vector<pair<int, int>> Backpack(N + 1);
	vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		int W = 0, V = 0;
		cin >> W >> V;
		Backpack[i] = make_pair(W, V);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
		{
			if (j - Backpack[i].first >= 0)
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Backpack[i].first] + Backpack[i].second);
			else
				DP[i][j] = DP[i - 1][j];
		}

	cout << DP[N][K] << "\n";

	return 0;
}
