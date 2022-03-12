//Baekjoon > 2206 > 벽 부수고 이동하기
//https://www.acmicpc.net/problem/2206

	//벽을 부술지 안부술지를 따로 저장해야한다.
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

	vector<string> wall(N); //맵을 저장
	vector<vector<vector<bool>>> visit(N, vector<vector<bool>>(M, vector<bool>(2, false))); //visit[N][M][2]로 만들어서 이미 벽을 부순 길인지 안부순 길인지 따로 visit값을 저장해준다.
	queue<pair<Pos, pair<int, bool>>> route; //좌표, count, 벽을 부쉈는지 안부웠는지 저장한다.
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
		flag = route.front().second.second; //벽을 부쉈는가 여부.
		
		route.pop();

		if (pos.r == N - 1 && pos.c == M - 1)
			break;

		for (int i = 0; i < 4; i++)
		{
			Pos n_pos;
			n_pos.r = pos.r + dir_r[i];
			n_pos.c = pos.c + dir_c[i];

			if (n_pos.r >= N || n_pos.c >= M || n_pos.r < 0 || n_pos.c < 0 || visit[n_pos.r][n_pos.c][flag]) //맵보다 좌표가 크거나, 이미 방문했다면
				continue;

			if (wall[n_pos.r][n_pos.c] == '0') //0이라면 길을 가고,
			{
				route.push(make_pair(n_pos, make_pair(count + 1, flag)));
				visit[n_pos.r][n_pos.c][flag] = true; 
			}
			else if (flag) //1이라면, 이전에 벽을 안부쉈어야지 들어갈 수 있다.
			{
				route.push(make_pair(n_pos, make_pair(count + 1, !flag))); //flag를 저장할 자리에 !flag로 기존과 다른 값을 저장해준다.
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