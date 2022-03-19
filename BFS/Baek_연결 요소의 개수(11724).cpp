//Baekjoon > 11724 > ���� ����� ����
//https://www.acmicpc.net/problem/11724

	//���� ��Ұ� ������ ���ϴ��� �����ϸ� ���� Ǯ �� �ִ� ����
	//DFS�� BFS�� Ǫ�µ� ���� BFS�� �̿��� Ǯ����. 
	//���� ��Ҷ� �׷��� �󿡼� �̾��� �ִ� ��� �������� ������ �ǹ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
void graph_search(vector<vector<int>>& graph, vector<int>& visit, queue<int>& node, int count)
{
	while (!node.empty())
	{
		int cur = node.front();
		node.pop();

		for (int i = 0; i < N; i++)
		{
			if (graph[cur][i] == 1 && visit[i] == 0)
			{
				node.push(i);
				visit[i] = count;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M = 0, u = 0, v = 0, count = 0;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(N, 0));
	vector<int> visit(N, 0);
	queue<int> node;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0)
		{
			node.push(i);
			visit[i] = ++count;
			graph_search(graph, visit, node, count);
		}
	}

	cout << count;

	return 0;
}