//Baekjoon > 1149 > RGB�Ÿ�
//https://www.acmicpc.net/problem/1149

	//ó���� DFS�� Ǯ���µ� �ð� �ʰ� ���Դ�.
	//DP�� ������ �����ϸ� �ȴٴ� ������ ���ߴ�.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<int> RGB(3);
	vector<vector<int>> cost(N, vector<int>(3)); //cost[i][j]�� �ǹ� : i��°�� j�� ���� ���� ���� �ּҺ��

	cin >> cost[0][0] >> cost[0][1] >> cost[0][2];
	for (int i = 1; i < N; i++)
	{
		cin >> RGB[0] >> RGB[1] >> RGB[2];

		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + RGB[0]; 
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + RGB[1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + RGB[2];
	}

	cout << min(cost[N - 1][0], min(cost[N - 1][1], cost[N - 1][2])) << "\n";

	return 0;
}
