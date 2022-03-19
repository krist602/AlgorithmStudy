//Baekjoon > 11724 > 연결 요소의 개수
//https://www.acmicpc.net/problem/11724

	//연결 요소가 무엇을 말하는지 이해하면 쉽게 풀 수 있는 문제
	//DFS나 BFS로 푸는데 나는 BFS를 이용해 풀었다. 
	//연결 요소란 그래프 상에서 이어져 있는 모든 정점들의 집합을 의미.

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