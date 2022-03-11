//Baekjoon > 7562 > 나이트의 이동
//https://www.acmicpc.net/problem/7562

	//백준식 답안제출때문에 틀림.

#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int bfs(int l, int row, int col, int dst_row, int dst_col)
{
	vector<vector<int>> m(l, vector<int>(l));
	vector<vector<bool>> visit(l, vector<bool>(l, false));
	queue<pair<pair<int, int>, int>> route;
	int count = 0;
	int cur_row, cur_col, nxt_row, nxt_col;
	int night_row[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int night_col[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	route.push(make_pair(make_pair(row, col), 0));
	visit[row][col] = true;

	while (!route.empty())
	{
		cur_row = route.front().first.first;
		cur_col = route.front().first.second;
		count = route.front().second;

		route.pop();

		if (cur_row == dst_row && cur_col == dst_col)
		{
			return count;
		}

		for (int i = 0; i < 8; i++)
		{
			nxt_row = cur_row + night_row[i];
			nxt_col = cur_col + night_col[i];

			if (nxt_row >= l || nxt_row < 0 || nxt_col >= l || nxt_col < 0)
				continue;

			if (!visit[nxt_row][nxt_col])
			{
				route.push(make_pair(make_pair(nxt_row, nxt_col), count + 1));
				visit[nxt_row][nxt_col] = true;
			}
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;
	vector<int> answer;

	for (int i = 0; i < N; i++)
	{
		int l;
		int now_row, now_col;
		int dst_row, dst_col;
		cin >> l;
		cin >> now_row >> now_col;
		cin >> dst_row >> dst_col;

		answer.push_back(bfs(l, now_row, now_col, dst_row, dst_col));
	}

	for (auto a : answer)
		cout << a << endl;

	return 0;
}