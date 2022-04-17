//baekjoon > 1167 > 트리의 지름
//https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>

using namespace std;

int diameter = 0;
int start = 0;
void dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& visit, int S, int d)
{
	visit[S] = true;
	if (diameter < d)
	{
		diameter = d;
		start = S;
	}
	for (auto t : tree[S])
		if (visit[t.second] == false)
			dfs(tree, visit, t.second, t.first + d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V = 0;
	cin >> V;
	vector<vector<pair<int, int>>> tree(V + 1);

	for (int i = 0; i < V; i++)
	{
		int s = 0, e = 0, h = 0;
		cin >> s;
		while (true)
		{
			cin >> e;
			if (e == -1)
				break;
			else
			{
				cin >> h;
				tree[s].push_back(make_pair(h, e));
			}
		}
	}

	vector<bool> visit(V + 1, false);
	dfs(tree, visit, 1, 0);
	for (auto v : visit)
		v = false;
	diameter = 0;
	dfs(tree, visit, start, 0);

	cout << diameter << "\n";

	return 0;
}