//Baekjoon > 1753 > 최단경로
//https://www.acmicpc.net/problem/1753

	//다익스트라 알고리즘 구현하는거 잘 기억하자. 또 컨닝함
	//INF의 값을 너무 작게 설정해서 계속 틀림

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& distance, int K)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_edge;
	pq_edge.push(make_pair(0, K));
	distance[K] = 0;

	while (!pq_edge.empty())
	{
		int cost = pq_edge.top().first;
		int cur_loc = pq_edge.top().second;
		pq_edge.pop();
		if (distance[cur_loc] < cost)
			continue;

		for (int i = 0; i < graph[cur_loc].size(); i++)
		{
			int n_cost = graph[cur_loc][i].first + cost;
			int n_loc = graph[cur_loc][i].second;

			if (distance[n_loc] > n_cost)
			{
				distance[n_loc] = n_cost;
				pq_edge.push(make_pair(n_cost, n_loc));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V = 0, E = 0, K = 0;

	cin >> V >> E >> K;
	vector<vector<pair<int, int>>> graph(V + 1);
	vector<int> distance(V + 1, INF);

	for (int e = 0; e < E; e++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}

	dijkstra(graph, distance, K);

	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF)
			cout << "INF\n";
		else
			cout << distance[i] << "\n";
	}


	return 0;
}
