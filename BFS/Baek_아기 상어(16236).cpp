//Baekjoon > 16236 > 아기상어
//https://www.acmicpc.net/problem/16236

	//너무 힘들었어...
	//1. 자기보다 큰 물고기가 있는 칸으론 이동할 수 없다.
	//2. 자기보다 작거나 같은 물고기가 있는 칸으론 이동할 수 있다.
	//3. 자기보다 작은 물고기만 먹을 수 있다.
	//4. 아기 상어의 크기와 같은 숫자의 물고기를 먹으면 아기 상어가 커지고, 먹은 물고기 숫자는 리셋된다.
	//5. 먹을 수 있는 물고기는 가장 윗쪽부터, 가장 왼쪽부터 먹는다.
	//일단, 문제의 규칙이 너무 많아서 하나씩 적용안한게 많아 틀렸었다.
	//이후론 일반적인 BFS로는 5번 규칙을 적용하기가 힘들어서 먹을 수 있는 물고기 중 가장 가까운 물고기의 위치를 모두 저장한 이후에 5번 규칙의 순서대로 먹도록 했다.
	//또한, 맨 처음 출발점의 숫자가 9인데, 이걸 0으로 안바꿔줘서 이후에도 코드상으로 그 칸을 지나가지 못했었다.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dir_r[] = { -1, 0, 0, 1 }; //상 좌 우 하
int dir_c[] = { 0, -1, 1, 0 };

int level = 2;
int fish = 0;
int timer = 0;

void bfs(vector<vector<int>>& space, int N, int r, int c)
{
	queue<pair<int, pair<int, int>>> route;
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	vector<pair<int, pair<int, int>>> can_go;

	int step = 0;

	route.push(make_pair(0, make_pair(r, c)));
	visit[r][c] = false;

	while (!route.empty())
	{
		int dist = route.front().first;
		int cur_r = route.front().second.first;
		int cur_c = route.front().second.second;
		route.pop();
		if (step != dist) //dist가 x인 칸을 모두 조사했으면 이 곳으로 들어오도록.
		{
			step = dist;
			if (!can_go.empty())
			{
				sort(can_go.begin(), can_go.end());

				timer = timer + can_go.front().first;
				space[can_go.front().second.first][can_go.front().second.second] = 0;
				fish++;
				if (fish == level)
				{
					level++;
					fish = 0;
				}
				bfs(space, N, can_go.front().second.first, can_go.front().second.second);
				can_go.clear(); //비워주지 않으면 분기 이후에 돌아와서 다시 다시 들어가버림.
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int next_r = cur_r + dir_r[i];
			int next_c = cur_c + dir_c[i];

			if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N)
				continue;

			if (visit[next_r][next_c] || space[next_r][next_c] > level)
				continue;

			if (space[next_r][next_c] && space[next_r][next_c] < level)
				can_go.push_back(make_pair(dist + 1, make_pair(next_r, next_c))); //먹을 수 있는 물고기가 있는 칸의 정보를 저장한다.

			route.push(make_pair(dist + 1, make_pair(next_r, next_c)));
			visit[next_r][next_c] = true;
		}
	}
	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, r, c;
	cin >> N;
	vector<vector<int>> space(N, vector<int>(N, 0));
	vector<vector<int>> distance(N, vector<int>(N, 0));


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				r = i;
				c = j;
				space[i][j] = 0; //0으로 안바꿔주면 이후에 r, c칸을 못지나간다.
			}
		}

	bfs(space, N, r, c);

	cout << timer << "\n";

	return 0;
}
