//Baekjoon > 11053 > ���� �� �����ϴ� �κ� ����
//https://www.acmicpc.net/problem/11053

	//DP����
	//i��° ĭ �������� 0������ Ž���ϸ鼭 DP�� �����Ѵ�.
	//ó���� DFS�� Ǫ�ϱ� �ð��ʰ� ���Ծ���.
	//DP������ ����ü�� ��� �ƴ� �ɱ�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, MAX = 0;
	cin >> N;
	vector<int> Arr(N);
	vector<int> DP(N);

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	DP[0] = 1;

	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (Arr[i] > Arr[j])
				DP[i] = max(DP[i], DP[j] + 1);

		MAX = max(DP[i], MAX);
	}

	cout << MAX << "\n";

	return 0;
}
