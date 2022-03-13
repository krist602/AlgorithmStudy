//Baekjoon > 1726 > 로봇
//https://www.acmicpc.net/problem/1726

	//조금 심화된 길찾기문제
	//은근 고생했는데, 문제의 함정에 그대로 빠졌기 때문이엇다.
	//첫 번째로 잘못생각한 것은 1~3칸까지 이동이 가능하지만 1이나 2에서 벽을 만나면 3은 못간다는 것이었다.
	//두 번째는, 방향은 90도만 변경된다는 것이었다. 동, 서 <-> 남, 북
	//그리고 이 두 번째의 적용을 잘못했었기에 어디서 잘못되었는지 찾지 못하고 고생했다.

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
	vector<vector<int>> world(M, vector<int>(N, 0)); //맵
	vector<vector<vector<bool>>> visit(M, vector<vector<bool>>(N, vector<bool>(4, false))); //방문 확인
	queue<pair<Pos, int>> route; //좌표와 count 저장
	Pos pos;
	int dir_r[4] = { 0,0,1,-1 }; //동 서 남 북
	int dir_c[4] = { 1,-1,0,0 }; //동 서 남 북


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
				if (world[next_p.r][next_p.c]) //벽을 만나면
					break; //더 이상 전진하지 않는다.
				continue; //비어있는 공간이지만 이미 방문한 노드라면 앞칸으로 다시 전진
			}
			
			route.push(make_pair(next_p, count + 1));
			visit[next_p.r][next_p.c][next_p.d] = true;
		}

		for (int i = 0; i < 2; i++) //Turn_dir. 0-> 2, 3. 1-> 2, 3. 2, 3-> 0, 1. 
		{
			Pos next_p;
			next_p.r = cur_p.r;
			next_p.c = cur_p.c;
			if (cur_p.d < 2) //0이나 1이라면 2 + 0, 2 + 1로
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