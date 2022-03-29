//Baekjoon > 15650 > N�� M(2)
//https://www.acmicpc.net/problem/15650

	//dfs�� ������ ���ϸ� �ȴ�.
	//������ �־��� ���ڸ� ���� ���� dfs�� ������ ���ڰ� ���� Ŀ������ ó���Ѵ�.

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> combination, int x, int step, int N, int M)
{
	if (step == M)
	{
		for (auto p : combination)
			cout << p << " ";
		cout << "\n";
		return;
	}

	for (int i = x + 1; i <= N; i++)
	{
		combination.push_back(i);
		dfs(combination, i, step + 1, N, M);
		combination.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	dfs(vector<int>(), 0, 0, N, M);

	return 0;
}
