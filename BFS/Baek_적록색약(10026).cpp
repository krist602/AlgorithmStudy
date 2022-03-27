//Baekjoon > 10026 > 적록색약
//https://www.acmicpc.net/problem/10026

	//적록색약용 BFS를 따로 만들 것이냐, 아니면 drawing의 G || B를 한가지로 통일시켜서 계산할 것이냐 2가지 방법이 있다.
	//나는 따로 만들었다. 원본데이터 바꾸기 싫어 !

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { 1, 0, -1, 0 };

int common(vector<string>& drawing, int size) //일반적인 BFS
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

int weakness(vector<string>& drawing, int size) //적록색약용 BFS
{
	int answer = 0;
	queue<pair<int, int>> route;
	vector<vector<bool>> visit(size, vector<bool>(size, false));
	
	for (int r = 0; r < size; r++) //모든 노드를 탐색한다.
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
					else //color가 B가 아니라면 R이나 G 둘 다 같이 취급한다.
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
