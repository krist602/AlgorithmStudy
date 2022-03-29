//Baekjoon > 15650 > N과 M(2)
//https://www.acmicpc.net/problem/15650

	//dfs로 조합을 구하면 된다.
	//이전에 넣어준 숫자를 같이 다음 dfs로 보내서 숫자가 점점 커지도록 처리한다.

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
