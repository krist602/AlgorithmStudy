//Baekjoon > 1389 > 케빈 베이컨의 6단계 법칙
//https://www.acmicpc.net/problem/1389

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

void bfs(int num, vector<vector<int>>& relation, map<int, int>& kevin)
{
	queue<pair<int, int>> route;
	bool check[110] = { false };
	int current_node, step;

	route.emplace(num, 0);
	check[num] = true;

	while (!route.empty())
	{
		current_node = route.front().first;
		step = route.front().second;
		kevin[num] += step;

		route.pop();

		for (int i = 0; i < relation[current_node].size(); i++)
		{
			if (!check[relation[current_node][i]])
			{
				route.push(make_pair(relation[current_node][i], step + 1));
				check[relation[current_node][i]] = true;
			}
		}
	}

	return;
}

int main()
{
	map<int, int> kevin;
	int N, M;
	int tmp1, tmp2;
	cin >> N >> M;
	vector<vector<int>> relation(N + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;
		relation[tmp1].push_back(tmp2);
		relation[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= N; i++)
		bfs(i, relation, kevin);

	tmp1 = kevin[1];
	tmp2 = 1;

	for (int i = 2; i <= N; i++)
	{
		if (tmp1 > kevin[i])
		{
			tmp1 = kevin[i];
			tmp2 = i;
		}
	}

	cout << tmp2 << endl;

	return 0;
}