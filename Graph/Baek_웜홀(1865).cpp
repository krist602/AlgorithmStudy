//Baekjoon > 1865 > ��Ȧ
//https://www.acmicpc.net/problem/1865

	//�÷��̵� �ͼ��� ����ؼ� Ǯ���µ�, �˻��غ��� ��������� Ǫ�� ����� ���Ƽ� �������带 ����.
	//���ó� ���ǹ����� Ʋ�ȱ⿡ Ʋ�� ������ ����д�.

	/*
	1. ���δ� ������ ���� ���̴�. 
	2. ���δ� ���� ���� �� �ִ�.
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
