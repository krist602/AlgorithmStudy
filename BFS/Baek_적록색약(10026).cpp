//Baekjoon > 10026 > ���ϻ���
//https://www.acmicpc.net/problem/10026

	//���ϻ���� BFS�� ���� ���� ���̳�, �ƴϸ� drawing�� G || B�� �Ѱ����� ���Ͻ��Ѽ� ����� ���̳� 2���� ����� �ִ�.
	//���� ���� �������. ���������� �ٲٱ� �Ⱦ� !

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { 1, 0, -1, 0 };

int common(vector<string>& drawing, int size) //�Ϲ����� BFS
{
	int answer = 0;
	queue<pair<int, int>> route;
	vector<vector<bool>> visit(size, vector<bool>(size, false));

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (!visit[r][c])
			{
				route.push(make_pair(r, c));
				visit[r][c] = true;
				answer++;
			}
			while (!route.empty())
			{
				int cur_row = 0, cur_col = 0;
				cur_row = route.front().first;
				cur_col = route.front().second;
				char color = drawing[cur_row][cur_col];
				route.pop();

				for (int i = 0; i < 4; i++)
				{
					int next_row = cur_row + dir_r[i];
					int next_col = cur_col + dir_c[i];

					if (next_row < 0 || next_row >= size || next_col < 0 || next_col >= size)
						continue;

					if (!visit[next_row][next_col] && (drawing[next_row][next_col] == color))
					{
						route.push(make_pair(next_row, next_col));
						visit[next_row][next_col] = true;
					}
				}
			}
		}
	}

	return answer;
}

int weakness(vector<string>& drawing, int size) //���ϻ���� BFS
{
	int answer = 0;
	queue<pair<int, int>> route;
	vector<vector<bool>> visit(size, vector<bool>(size, false));
	
	for (int r = 0; r < size; r++) //��� ��带 Ž���Ѵ�.
	{
		for (int c = 0; c < size; c++)
		{
			if (!visit[r][c])
			{
				route.push(make_pair(r, c));
				visit[r][c] = true;
				answer++;
			}
			while (!route.empty())
			{
				int cur_row = 0, cur_col = 0;
				cur_row = route.front().first;
				cur_col = route.front().second;
				char color = drawing[cur_row][cur_col];
				route.pop();

				for (int i = 0; i < 4; i++)
				{
					int next_row = cur_row + dir_r[i];
					int next_col = cur_col + dir_c[i];

					if (next_row < 0 || next_row >= size || next_col < 0 || next_col >= size)
						continue;

					if (color == 'B')
					{
						if (!visit[next_row][next_col] && (drawing[next_row][next_col] == color))
						{
							route.push(make_pair(next_row, next_col));
							visit[next_row][next_col] = true;
						}
					}
					else //color�� B�� �ƴ϶�� R�̳� G �� �� ���� ����Ѵ�.
					{
						if (!visit[next_row][next_col] && (drawing[next_row][next_col] == 'R' || drawing[next_row][next_col] == 'G'))
						{
							route.push(make_pair(next_row, next_col));
							visit[next_row][next_col] = true;
						}
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<string> drawing(N, "");

	for (int i = 0; i < N; i++)
		cin >> drawing[i];

	cout << common(drawing, N) << " " << weakness(drawing, N);

	return 0;
}
