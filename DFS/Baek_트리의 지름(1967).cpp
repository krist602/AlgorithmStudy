//Baekjoon > 1967 > 트리의 지름
//https://www.acmicpc.net/problem/1967

	//1167번 문제와 비슷한 문제.

#include <iostream>
#include <vector>

using namespace std;

int start = 0;
int diameter = 0;
void dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& visit, int x, int d)
{
	visit[x] = true;
	if (diameter < d)
	{
		diameter = d;
		start = x;
	}

	for (int i = 0; i < tree[x].size(); i++)
	{
		int next = tree[x][i].second;
		int dis = tree[x][i].first;

		if (!visit[next])
			dfs(tree, visit, next, d + dis);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N = 0;
	cin >> N;
	vector<vector<pair<int, int>>> tree(N + 1);
	vector<bool> visit(N + 1);
	for (int i = 1; i < N; i++)
	{
		int p, c, v;
		cin >> p >> c >> v;

		tree[p].push_back(make_pair(v, c));
		tree[c].push_back(make_pair(v, p));
		start = c;
	}

	dfs(tree, visit, start, 0);
	for (auto v : visit)
		v = false;
	diameter = 0;
	dfs(tree, visit, start, 0);
	cout << diameter << endl;

	return 0;
}