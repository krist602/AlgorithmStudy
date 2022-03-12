//Baekjoon > 7569 > �丶��
//https://www.acmicpc.net/problem/7569

	//7576�� ������ ���������� 1������ �� �þ���.
	//�׷��� struct�� �߰��Ͽ� �ذ��ߴ�. (���ϰ� pair�� �ϳ� �� ������ ����ϴٰ�)
	//������ struct�� Ȱ�� ����� �ʱ�ȭ, vector<struct>�� queue<struct>�� ���� ��� ���� Ȯ���ϸ� ���ڴ�.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
	int h;
	int r;
	int c;
};

int main()
{
	int M, N, H;
	int count = 0;
	cin >> M >> N >> H;
	int dir_r[6] = { 0, 1, 0, -1, 0, 0 }; //�� �� �� �� �� ��
	int dir_c[6] = { 1, 0, -1, 0, 0, 0 };
	int dir_h[6] = { 0, 0, 0, 0, -1, 1 };

	vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M, 0)));
	vector<vector<vector<bool>>> visit(H, vector<vector<bool>>(N, vector<bool>(M, false)));
	queue<pair<Pos, int>> route;

	for (int z = 0; z < H; z++)
		for (int x = 0; x < N; x++)
			for (int y = 0; y < M; y++)
			{
				cin >> tomato[z][x][y];
				if (tomato[z][x][y] == -1)
					visit[z][x][y] = true;
				else if (tomato[z][x][y] == 1)
				{
					Pos pos;
					pos.h = z;
					pos.r = x;
					pos.c = y;
					route.push(make_pair(pos, 0));
					visit[z][x][y] = true;
				}
			}

	while (!route.empty())
	{
		int cur_height = route.front().first.h;
		int cur_row = route.front().first.r;
		int cur_col = route.front().first.c;
		count = route.front().second;

		route.pop();
		for (int i = 0; i < 6; i++)
		{
			Pos pos;
			pos.h = cur_height + dir_h[i];
			pos.r = cur_row + dir_r[i];
			pos.c = cur_col + dir_c[i];
			if (pos.r < 0 || pos.r >= N || pos.c < 0 || pos.c >= M || pos.h < 0 || pos.h >= H || visit[pos.h][pos.r][pos.c])
				continue;

			route.push(make_pair(pos, count + 1));
			visit[pos.h][pos.r][pos.c] = true;
		}
	}
	for (int z = 0; z < H; z++)
		for (int x = 0; x < N; x++)
			for (int y = 0; y < M; y++)
				if (!visit[z][x][y])
				{
					cout << "-1" << endl;
					return 0;
				}

	cout << count << endl;
	return 0;
}