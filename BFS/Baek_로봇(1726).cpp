//Baekjoon > 1726 > �κ�
//https://www.acmicpc.net/problem/1726

	//���� ��ȭ�� ��ã�⹮��
	//���� ����ߴµ�, ������ ������ �״�� ������ �����̾���.
	//ù ��°�� �߸������� ���� 1~3ĭ���� �̵��� ���������� 1�̳� 2���� ���� ������ 3�� �����ٴ� ���̾���.
	//�� ��°��, ������ 90���� ����ȴٴ� ���̾���. ��, �� <-> ��, ��
	//�׸��� �� �� ��°�� ������ �߸��߾��⿡ ��� �߸��Ǿ����� ã�� ���ϰ� ����ߴ�.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos
{
	int r;
	int c;
	int d;

	bool operator== (Pos pos)
	{
		if (r == pos.r && c == pos.c && d == pos.d)
			return true;
		return false;
	}
};

int main()
{
	int M, N;
	int count = 0;
	cin >> M >> N;
	vector<vector<int>> world(M, vector<int>(N, 0)); //��
	vector<vector<vector<bool>>> visit(M, vector<vector<bool>>(N, vector<bool>(4, false))); //�湮 Ȯ��
	queue<pair<Pos, int>> route; //��ǥ�� count ����
	Pos pos;
	int dir_r[4] = { 0,0,1,-1 }; //�� �� �� ��
	int dir_c[4] = { 1,-1,0,0 }; //�� �� �� ��


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> world[i][j];
			if (world[i][j])
				for (int d = 0; d < 4; d++)
					visit[i][j][d] = true;
		}
	}
	cin >> pos.r >> pos.c >> pos.d;
	pos.r -= 1;
	pos.c -= 1;
	pos.d -= 1;
	route.push(make_pair(pos, 0));
	visit[pos.r][pos.c][pos.d] = true;

	cin >> pos.r >> pos.c >> pos.d;
	pos.r -= 1;
	pos.c -= 1;
	pos.d -= 1;

	while (!route.empty())
	{
		Pos cur_p = route.front().first;
		count = route.front().second;

		if (cur_p == pos)
			break;

		route.pop();

		for (int i = 1; i < 4; i++)
		{
			Pos next_p;
			next_p.r = cur_p.r + i * dir_r[cur_p.d];
			next_p.c = cur_p.c + i * dir_c[cur_p.d];
			next_p.d = cur_p.d;
			if (next_p.r < 0 || next_p.r >= M || next_p.c < 0 || next_p.c >= N)
				continue;

			if (visit[next_p.r][next_p.c][next_p.d])
			{
				if (world[next_p.r][next_p.c]) //���� ������
					break; //�� �̻� �������� �ʴ´�.
				continue; //����ִ� ���������� �̹� �湮�� ����� ��ĭ���� �ٽ� ����
			}
			
			route.push(make_pair(next_p, count + 1));
			visit[next_p.r][next_p.c][next_p.d] = true;
		}

		for (int i = 0; i < 2; i++) //Turn_dir. 0-> 2, 3. 1-> 2, 3. 2, 3-> 0, 1. 
		{
			Pos next_p;
			next_p.r = cur_p.r;
			next_p.c = cur_p.c;
			if (cur_p.d < 2) //0�̳� 1�̶�� 2 + 0, 2 + 1��
				next_p.d = 2 + i;
			else
				next_p.d = i;

			if (visit[next_p.r][next_p.c][next_p.d])
				continue;

			route.push(make_pair(next_p, count + 1));
			visit[next_p.r][next_p.c][next_p.d] = true;
		}
	}

	cout << count << endl;

	return 0;
}