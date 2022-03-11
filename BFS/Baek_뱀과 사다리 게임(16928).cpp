//Baekjoon > 16928 > ��� ��ٸ� ����
//https://www.acmicpc.net/problem/16928

	//BFS����
	//��Ÿ ������ �˰����� �����ϳ�, ���� ��ü�� ������ �� �־��� ����
	//������ ����� ������������ �� ����ߴ�.

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int bfs(map<int, int>& move)
{
	queue<pair<int, int>> game;
	bool visit[110] = { false };
	int cur_location = 0;
	int nxt_location;
	int count = 0;

	game.push(make_pair(1, 0));
	visit[1] = true;

	while (!game.empty())
	{
		cur_location = game.front().first;
		count = game.front().second;

		game.pop();

		if (cur_location == 100)
			return count;

		for (int nxt : {1, 2, 3, 4, 5, 6})
		{
			nxt_location = nxt + cur_location;
			if (!visit[nxt_location] && nxt_location <= 100)
			{
				if (move[nxt_location])
				{
					if (!visit[move[nxt_location]]) //���� ���̳� ��ٸ��� �ִٸ� ������ �����Ѵ�.
					{
						game.push(make_pair(move[nxt_location], count + 1));
						visit[move[nxt_location]] = true;
					}
				}
				else //���̳� ��ٸ��� ���� ���� �� ĭ���� ����ϴ� ���� �� �� �ִ�.
				{
					game.push(make_pair(nxt_location, count + 1));
					visit[nxt_location] = true;
				}
			}
		}
	}
}

int main()
{
	map<int, int> move; //���� map�� �ƴ϶� int �迭 ���� ���� �̿��ص� �Ǳ� �Ѵ�.
	int N, M;
	int tmp1, tmp2;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp1 >> tmp2;
		move[tmp1] = tmp2;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;
		move[tmp1] = tmp2;
	}

	cout << bfs(move) << endl;

	return 0;
}