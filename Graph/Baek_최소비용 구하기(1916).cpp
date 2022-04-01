//Baekjoon > 1916 > �ּҺ�� ���ϱ�
//https://www.acmicpc.net/problem/1916

	//�÷��̵�-�ͼ��� ó�� ������ Ǯ�����µ�, �� ������ ���ͽ�Ʈ�� ���°� �´�.
	//�÷��̵�-�ͼ��� ��� �������� ��� ���������� �Ÿ��� ����������, ������ start������ end�������� ��븸 ���ϸ� �Ǳ� ����.
	//���ͽ�Ʈ�� ��� ������ �� ����ص���.

#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& distance, int start, int N)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	distance[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (distance[cur] < cost)
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int ncost = cost + graph[cur][i].second;

			if (distance[next] > ncost)
			{
				distance[next] = ncost;
				pq.push(make_pair(ncost, next));
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	int start = 0, end = 0, cost = 0;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);
	vector<int> distance(N + 1, INF);

	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> cost;
		graph[start].push_back(make_pair(end, cost));
	}
	cin >> start >> end;
	dijkstra(graph, distance, start, N);
	cout << distance[end];

	return 0;
}
