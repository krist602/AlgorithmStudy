//Baekjoon > 11660 > ���� �� ���ϱ� 5
//https://www.acmicpc.net/problem/11660

	//DP�����̴�
	//DP[i][j]���� graph[i][j]������ ���� ���� �����ָ� �ǰ�, ���� �ʿ��� �κи� ����ϴ� ���� �̲��� ���� Ǯ �� �ִ�.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	int row1, col1, row2, col2, sum = 0;

	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1));
	vector<vector<int>> DP(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> graph[i][j];
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + graph[i][j];
		}

	for (int i = 0; i < M; i++)
	{
		cin >> row1 >> col1 >> row2 >> col2;
		cout << DP[row2][col2] - DP[row1 - 1][col2] - DP[row2][col1 - 1] + DP[row1 - 1][col1 - 1] << "\n";
	}



	return 0;
}
