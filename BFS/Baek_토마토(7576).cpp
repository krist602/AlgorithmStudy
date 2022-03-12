//Baekjoon > 7576 > �丶��
//https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	int count = 0;
	cin >> M >> N;
	int dir_r[4] = { 0, 1, 0, -1 }; //�� �� �� ��
	int dir_c[4] = { 1, 0, -1, 0 };
	vector<vector<int>> tomato(N, vector<int>(M, 0));
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	queue<pair<pair<int, int>, int>> route;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == -1) //-1�̶�� �丶�䰡 ���� ������ �� �ʿ䰡 ���� �����̴�.
				visit[i][j] = true;
			else if (tomato[i][j] == 1) //1�̶�� ���� �丶�䰡 �ֱ� ������ ó������ queue�� push���ش�.
			{
				route.push(make_pair(make_pair(i, j), 0)); 
				visit[i][j] = true;
			}
		}

	while (!route.empty())
	{
		int cur_row = route.front().first.first;
		int cur_col = route.front().first.second;
		count = route.front().second;

		route.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_row = cur_row + dir_r[i];
			int next_col = cur_col + dir_c[i];
			if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M || visit[next_row][next_col])
				continue;

			route.push(make_pair(make_pair(next_row, next_col), count + 1));
			visit[next_row][next_col] = true;
		}
	}

	for (int i = 0; i < N; i++) //�湮 ���� ��尡 �ִٸ� ���� ���� �� ���� �׷����̴�.
		for (int j = 0; j < M; j++)
			if (!visit[i][j])
			{
				cout << "-1" << endl;
				return 0;
			}

	cout << count << endl;
	return 0;
}