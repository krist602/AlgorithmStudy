//Baekjoon > 2206 > �� �μ��� �̵��ϱ�
//https://www.acmicpc.net/problem/2206

	//���� �μ��� �Ⱥμ����� ���� �����ؾ��Ѵ�.
	//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pos {
	int r;
	int c;
};

int main()
{
	int N, M;
	int count = 0;
	bool flag;
	cin >> N >> M;
	int dir_r[4] = { 0, 1, 0, -1 };
	int dir_c[4] = { 1, 0, -1, 0 };

	vector<string> wall(N); //���� ����
	vector<vector<vector<bool>>> visit(N, vector<vector<bool>>(M, vector<bool>(2, false))); //visit[N][M][2]�� ���� �̹� ���� �μ� ������ �Ⱥμ� ������ ���� visit���� �������ش�.
	queue<pair<Pos, pair<int, bool>>> route; //��ǥ, count, ���� �ν����� �Ⱥο����� �����Ѵ�.
	Pos pos;

	for (int i = 0; i < N; i++)
		cin >> wall[i];

	pos.r = 0;
	pos.c = 0;
	route.push(make_pair(pos, make_pair(1, true)));
	visit[0][0][1] = true;

	while (!route.empty())
	{
		pos.r = route.front().first.r;
		pos.c = route.front().first.c;
		count = route.front().second.first;
		flag = route.front().second.second; //���� �ν��°� ����.
		
		route.pop();

		if (pos.r == N - 1 && pos.c == M - 1)
			break;

		for (int i = 0; i < 4; i++)
		{
			Pos n_pos;
			n_pos.r = pos.r + dir_r[i];
			n_pos.c = pos.c + dir_c[i];

			if (n_pos.r >= N || n_pos.c >= M || n_pos.r < 0 || n_pos.c < 0 || visit[n_pos.r][n_pos.c][flag]) //�ʺ��� ��ǥ�� ũ�ų�, �̹� �湮�ߴٸ�
				continue;

			if (wall[n_pos.r][n_pos.c] == '0') //0�̶�� ���� ����,
			{
				route.push(make_pair(n_pos, make_pair(count + 1, flag)));
				visit[n_pos.r][n_pos.c][flag] = true; 
			}
			else if (flag) //1�̶��, ������ ���� �Ⱥν������ �� �� �ִ�.
			{
				route.push(make_pair(n_pos, make_pair(count + 1, !flag))); //flag�� ������ �ڸ��� !flag�� ������ �ٸ� ���� �������ش�.
				visit[n_pos.r][n_pos.c][!flag] = true;
			}
		}
	}

	if (visit[N - 1][M - 1][0] || visit[N - 1][M - 1][1])
	{
		cout << count << endl;
		return 0;
	}

	cout << "-1" << endl;
	return 0;
}