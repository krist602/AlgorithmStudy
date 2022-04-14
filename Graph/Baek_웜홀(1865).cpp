//Baekjoon > 1865 > 웜홀
//https://www.acmicpc.net/problem/1865

	//플로이드 와샬을 사용해서 풀었는데, 검색해보니 벨만포드로 푸는 사람도 많아서 벨만포드를 공부.
	//역시나 조건문에서 틀렸기에 틀린 이유를 적어둔다.

	/*
	1. 도로는 방향이 없는 길이다. 
	2. 도로는 여러 개일 수 있다.
	*/

#include <iostream>
#include <vector>
#define INF 1000000000

using namespace std;

void floyd(vector<vector<int>>& City, int N)
{
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (City[i][j] > City[i][k] + City[k][j])
					City[i][j] = City[i][k] + City[k][j];
			}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC = 0;
	cin >> TC;

	for (int i = 0; i < TC; i++)
	{
		int N = 0, M = 0, W = 0;
		cin >> N >> M >> W;
		vector<vector<int>> City(N + 1, vector<int>(N + 1, INF));
		for (int m = 0; m < M; m++)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			if (City[S][E] > T)
			{
				City[S][E] = T;
				City[E][S] = T;
			}
		}
		for (int w = 0; w < W; w++)
		{
			int S = 0, E = 0, T = 0;
			cin >> S >> E >> T;
			City[S][E] = -T;
		}
		floyd(City, N);

		for(int i = 1; i <= N; i++)
		{
			if (City[i][i] < 0)
			{
				cout << "YES\n";
				break;
			}
			else if(i == N)
				cout << "NO\n";
		}
		
	}

	return 0;
}
