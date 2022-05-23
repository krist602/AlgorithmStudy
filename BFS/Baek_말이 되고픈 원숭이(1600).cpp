//baekjoon > 1600 > ���� �ǰ��� ������
//https://www.acmicpc.net/problem/1600

/*
	����� BFS�����ε� �� ����ߴ°�
		1. visit�� ó���� row, col�θ� ����ؼ� '��ó�� ������ ī��Ʈ'�� �޶��� ���� �̹� �湮������ �� ������ �Ȱ���.
		2. �ɷ��� ������� ��, visit[row][col][use + 1]�� �ؾ��ϴµ�, [use]�� �߾��⿡ ��� Ʋ�ȴ�.

		��û�� !
*/

#include <iostream>
#include <vector>
#include <queue>
#define IMP 1000000000

using namespace std;

void bfs(vector<vector<bool>>& maps, int K, int W, int H)
{
	int horse_c[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int horse_r[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int non_c[] = { 0, 1, 0, -1 };
	int non_r[] = { -1, 0, 1, 0 };

	priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> route;
	vector<vector<vector<bool>>> visit(H, vector<vector<bool>>(W, vector<bool>(K + 1, false)));

	int MIN = IMP;

	route.push(make_pair(make_pair(0, K), make_pair(0, 0)));
	visit[0][0][K] = true;

	while (!route.empty())
	{
		int count = route.top().first.first;
		int can_horse = route.top().first.second;
		int row = route.top().second.first;
		int col = route.top().second.second;

		route.pop();

		if (row == H - 1 && col == W - 1)
		{
			cout << count << endl;
			return;
		}

		if (can_horse)
		{
			for (int i = 0; i < 8; i++)
			{
				int next_r = row + horse_r[i];
				int next_c = col + horse_c[i];

				if (next_r < 0 || next_c < 0 || next_r >= H || next_c >= W)
					continue;

				if (visit[next_r][next_c][can_horse - 1] || maps[next_r][next_c])
					continue;

				route.push(make_pair(make_pair(count + 1, can_horse - 1), make_pair(next_r, next_c)));
				visit[next_r][next_c][can_horse - 1] = true;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int next_r = row + non_r[i];
			int next_c = col + non_c[i];

			if (next_r < 0 || next_c < 0 || next_r >= H || next_c >= W)
				continue;

			if (visit[next_r][next_c][can_horse] || maps[next_r][next_c])
				continue;

			route.push(make_pair(make_pair(count + 1, can_horse), make_pair(next_r, next_c)));
			visit[next_r][next_c][can_horse] = true;
		}
	}

	cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K = 0, W = 0, H = 0, temp = 0;
	cin >> K >> W >> H;
	vector<vector<bool>> maps(H, vector<bool>(W, false));

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> temp;
			maps[i][j] = temp;
		}

	bfs(maps, K, W, H);

	return 0;
}