//Baekjoon > 1260 > DFS와 BFS
//https://www.acmicpc.net/problem/1260

	//DFS와 BFS만들기 복습.
	//DFS를 재귀가 아닌 stack를 이용해 구현하려고 노력했음.	
	//재귀를 통해 구현하는게 더 쉽고 깔끔하지만, stack의 구현 방법을 기억해두면 좋을 것 같다. 은근 복잡함.

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& node, vector<bool> visit, int start)
{
	stack<int> route;

	route.push(start);
	visit[start] = true;

	cout << start << " ";

	while (!route.empty())
	{
		int cur_node = route.top();
		route.pop();

		for (int i = 1; i < node.size(); i++)
		{
			if (node[cur_node][i] && !visit[i])
			{
				cout << i << " ";
				route.push(cur_node); //이 부분이 핵심이다. i를 탐색하고, 다시 cur_node로 돌아와야하기 때문
				route.push(i);
				visit[i] = true;
				break;
			}
		}
	}
	return;
}

void bfs(vector<vector<int>>& node, vector<bool> visit, int start)
{
	queue<int> route;
	route.push(start);
	visit[start] = true;

	while (!route.empty())
	{
		int cur_node = route.front();
		route.pop();
		cout << cur_node << " ";

		for (int i = 0; i < node.size(); i++)
		{
			if (node[cur_node][i] && !visit[i])
			{
				route.push(i);
				visit[i] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0, V = 0;
	cin >> N >> M >> V;
	vector<vector<int>> node(N + 1, vector<int>(N + 1, 0));
	vector<bool> visit(N + 1, false);


	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		node[tmp1][tmp2] = 1;
		node[tmp2][tmp1] = 1;
	}

	dfs(node, visit, V);
	cout << "\n";

	bfs(node, visit, V);
	cout << "\n";

	return 0;
}