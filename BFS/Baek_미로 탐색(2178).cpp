//Baekjoon > 2178 > 미로 탐색
//https://www.acmicpc.net/problem/2178

	//평범한 BFS문제
	//특이사항 없음

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { 1, 0, -1, 0 };

void bfs(vector<string>& maze, vector<vector<int>>& distance, int count, int N, int M)
{
	queue<pair<int, int>> route;
	route.push(make_pair(0, 0));
	distance[0][0] = 1;

	while (!route.empty())
	{
		int row = route.front().first;
		int col = route.front().second;
		route.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_r = row + dir_r[i];
			int next_c = col + dir_c[i];
			if (next_r < 0 || next_r > N || next_c < 0 || next_c > M)
				continue;
			if (maze[next_r][next_c] == '1' && !distance[next_r][next_c])
			{
				route.push(make_pair(next_r, next_c));
				distance[next_r][next_c] = distance[row][col] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<string> maze(N, "");
	vector<vector<int>> distance(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
		cin >> maze[i];

	bfs(maze, distance, 1, N - 1, M - 1);

	cout << distance[N - 1][M - 1] << "\n";

	return 0;
}