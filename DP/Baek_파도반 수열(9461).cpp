//Baekjoon > 9461 > �ĵ��� ����
//https://www.acmicpc.net/problem/9461

	//DP����.
	//��ȭ���� �� �����µ� �ڷ����� overflow�� ����.
	//�׻� ��� �׽�Ʈ �ϱ�.

#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long>& P, int N)
{
	if (N == 0)
		return 0;

	if (P[N] != 0)
		return P[N];

	P[N] = solve(P, N - 5) + solve(P, N - 1);
	return P[N];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> P(110, 0); //int������ �����ϸ� 100 �Է� �ÿ� overflow�� ����.
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N = 0;
		cin >> N;

		cout << solve(P, N) << endl;
	}

	return 0;
}