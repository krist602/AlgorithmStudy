//Baekjoon > 11403 > ��� ã��
//https://www.acmicpc.net/problem/11403

	//���� BFS�� �̿��� Ǯ����.
	//�ٵ� �÷��̵带 �̿��� Ǫ�°� �� ����غ����� BFS�� Ǭ ����� �Ʒ��� ������ �÷��̵带 ÷���Ѵ�.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void floyd(vector<vector<int>>& graph)
{
	for (int i = 0; i < graph.size(); i++)
		for (int j = 0; j < graph.size(); j++)
			for (int k = 0; k < graph.size(); k++)
				if (graph[j][i] && graph[i][k])
					graph[j][k] = 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<vector<int>> graph(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	floyd(graph);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}

	return 0;
}

//====================================================================================

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<vector<int>> graph(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	for (int i = 0; i < N; i++)
	{
		queue<int> route;
		vector<bool> visit(N, false);
		route.push(i);

		while (!route.empty())
		{
			int cur = route.front();
			route.pop();

			for (int j = 0; j < N; j++)
			{
				if (graph[cur][j] == 1 && !visit[j])
				{
					route.push(j);
					graph[i][j] = 1;
					visit[j] = true;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}

	return 0;
}