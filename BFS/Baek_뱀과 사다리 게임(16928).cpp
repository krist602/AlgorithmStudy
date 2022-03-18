//Baekjoon > 16928 > 뱀과 사다리 게임
//https://www.acmicpc.net/problem/16928

	//BFS문제
	//여타 문제와 알고리즘은 동일하나, 문제 자체에 함정이 좀 있었던 문제
	//문제를 제대로 이해하지못해 좀 고생했다.

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
					if (!visit[move[nxt_location]]) //만약 뱀이나 사다리가 있다면 무조건 들어가야한다.
					{
						game.push(make_pair(move[nxt_location], count + 1));
						visit[move[nxt_location]] = true;
					}
				}
				else //뱀이나 사다리가 없을 때만 그 칸에서 출발하는 일을 할 수 있다.
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
	map<int, int> move; //굳이 map이 아니라 int 배열 같은 것을 이용해도 되긴 한다.
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