//Baekjoon > 16236 > �Ʊ���
//https://www.acmicpc.net/problem/16236

	//�ʹ� �������...
	//1. �ڱ⺸�� ū ����Ⱑ �ִ� ĭ���� �̵��� �� ����.
	//2. �ڱ⺸�� �۰ų� ���� ����Ⱑ �ִ� ĭ���� �̵��� �� �ִ�.
	//3. �ڱ⺸�� ���� ����⸸ ���� �� �ִ�.
	//4. �Ʊ� ����� ũ��� ���� ������ ����⸦ ������ �Ʊ� �� Ŀ����, ���� ����� ���ڴ� ���µȴ�.
	//5. ���� �� �ִ� ������ ���� ���ʺ���, ���� ���ʺ��� �Դ´�.
	//�ϴ�, ������ ��Ģ�� �ʹ� ���Ƽ� �ϳ��� ������Ѱ� ���� Ʋ�Ⱦ���.
	//���ķ� �Ϲ����� BFS�δ� 5�� ��Ģ�� �����ϱⰡ ���� ���� �� �ִ� ����� �� ���� ����� ������� ��ġ�� ��� ������ ���Ŀ� 5�� ��Ģ�� ������� �Ե��� �ߴ�.
	//����, �� ó�� ������� ���ڰ� 9�ε�, �̰� 0���� �ȹٲ��༭ ���Ŀ��� �ڵ������ �� ĭ�� �������� ���߾���.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dir_r[] = { -1, 0, 0, 1 }; //�� �� �� ��
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
		if (step != dist) //dist�� x�� ĭ�� ��� ���������� �� ������ ��������.
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
				can_go.clear(); //������� ������ �б� ���Ŀ� ���ƿͼ� �ٽ� �ٽ� ������.
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
				can_go.push_back(make_pair(dist + 1, make_pair(next_r, next_c))); //���� �� �ִ� ����Ⱑ �ִ� ĭ�� ������ �����Ѵ�.

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
				space[i][j] = 0; //0���� �ȹٲ��ָ� ���Ŀ� r, cĭ�� ����������.
			}
		}

	bfs(space, N, r, c);

	cout << timer << "\n";

	return 0;
}
