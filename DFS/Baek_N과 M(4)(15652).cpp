//Baekjoon > 15652 > N�� M(4)
//https://www.acmicpc.net/problem/15652

	//N�� M(2)�� ������ �ٸ��� ����.

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& combination, int index, int stage, int N, int M)
{
	if (stage == M)
	{
		for (auto C : combination)
			cout << C << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i <= N; i++)
	{
		combination.push_back(i);
		dfs(combination, i, stage + 1, N, M);
		combination.pop_back();
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	vector<int>combination;

	dfs(combination, 1, 0, N, M);

	return 0;
}
