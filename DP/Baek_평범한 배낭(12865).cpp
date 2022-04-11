//Baekjoon > 12865 > ����� �賶
//https://www.acmicpc.net/problem/12865

	//���ó� DP����.
	//������ DP�����̶�� �Ѵ�.

	/*
	�賶 ������ ���� �ɰ� �� �ִ� ���(���԰� �Ҽ��� �� �ִ� ���)�� ���� �ɰ� �� ���� ���(�� ��� ���� ���Դ� 0 �̻��� ������ ����) �� ������ ���� �� �ִµ�, 
	���� �ɰ� �� �ִ� ����� �賶 ������ ���� ���� �賶 ����(Fractional), 
	���� �ɰ� �� ���� ����� �賶 ������ 0-1 �賶 ����(0-1 Knapsack)�� �θ���. - ��Ű���
	*/

	//��ȭ���� 
	//DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);   
	//(i�� �ִ� ��, j�� �賶�� ���� ������ ����)

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
