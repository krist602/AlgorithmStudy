//Baekjoon > 2579 > ��� ������
//https://www.acmicpc.net/problem/2579

	//ó���� dfs�� Ǯ����. �ٵ� �ð� �ʰ� ����
	//�׷��� dfs�� ������ �����ϵ��� �ٲ��. �׷��� �ð� �ʰ� ����
	//DP������� ���� �� ���Ŀ� �˾Ҵ�. 
	//DP[i] ������ �˻��ߴ�. DP[i - 3] + stair[i - 1] + stair[i]

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