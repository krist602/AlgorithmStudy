//Bekjoon > 1697 > ���ٲ���
//https://www.acmicpc.net/problem/1697

	//BFS����
	//Ư���� ������ ������ �� ����.
	//�Ʒ��� for���� �ٸ� Ȱ������ �־������ ����

#include <iostream>
#include <queue>

using namespace std;

bool visit[100003];

int bfs(int n, int k)
{
	queue<pair<int, int>> route;
	int time = 0;
	int current_node = 0;

	route.emplace(n, 0);
	visit[n] = true;

	while (!route.empty())
	{
		current_node = route.front().first;
		time = route.front().second;
		route.pop();

		if (current_node == k)
			return time;

		if (current_node != 100000)
			if (!visit[current_node + 1])
			{
				route.push(make_pair(current_node + 1, time + 1));
				visit[current_node + 1] = true;
			}
		if (current_node != 0)
			if (!visit[current_node - 1])
			{
				route.push(make_pair(current_node - 1, time + 1));
				visit[current_node - 1] = true;
			}
		if (current_node <= 50000)
			if (!visit[current_node * 2])
			{
				route.push(make_pair(current_node * 2, time + 1));
				visit[current_node * 2] = true;
			}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << bfs(N, K);

	return 0;
}

//=============================================================================================

#include <iostream>
#include <queue>

using namespace std;

bool visit[100003];

int bfs(int n, int k)
{
	queue<pair<int, int>> route;
	int time = 0;
	int current_node = 0;

	route.emplace(n, 0);
	visit[n] = true;

	while (!route.empty())
	{
		current_node = route.front().first;
		time = route.front().second;
		route.pop();

		if (current_node == k)
			return time;

		for (int next_node : {current_node + 1, current_node - 1, 2 * current_node}) //for���� Ȱ���� �� ����صθ� ���� �� ����.
		{
			if (next_node < 0 || next_node > 100000) continue;
			if (!visit[next_node])
			{
				route.push(make_pair(next_node, time + 1));
				visit[next_node] = true;
			}
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << bfs(N, K);

	return 0;
}