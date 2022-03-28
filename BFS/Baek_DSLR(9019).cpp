//Baekjoon > 9019 > DSLR
//https://www.acmicpc.net/problem/9019

	//평범한 BFS 문제를 약간 꼬았을 뿐인데
	//왜 혼자 이상하게 풀려고 했을까?
	//string형식으로 풀었떠니 메모리 초과 나와서 코드 다시 짬

#include <iostream>
#include <string>
#include <queue>

using namespace std;

void bfs(int l_int, int r_int)
{
	bool visit[10000] = { false };
	queue<pair<int, string>> route;
	route.push(make_pair(l_int, ""));
	visit[l_int] = true;

	while (!route.empty())
	{
		int cur_num = route.front().first;
		string oper = route.front().second;
		route.pop();
		if (cur_num == r_int)
		{
			cout << oper << "\n";
			return;
		}

		int temp_num = 0;

		//D
		temp_num = (cur_num * 2) % 10000;
		if (!visit[temp_num])
		{
			route.push(make_pair(temp_num, oper + 'D'));
			visit[temp_num] = true;
		}

		//S
		if (cur_num == 0)
			temp_num = 9999;
		else
			temp_num = cur_num - 1;
		if (!visit[temp_num])
		{
			route.push(make_pair(temp_num, oper + 'S'));
			visit[temp_num] = true;
		}

		//L
		temp_num = (cur_num * 10) % 10000 + (cur_num / 1000);
		if (!visit[temp_num])
		{
			route.push(make_pair(temp_num, oper + 'L'));
			visit[temp_num] = true;
		}

		//R
		temp_num = (cur_num / 10) + (cur_num % 10) * 1000;
		if (!visit[temp_num])
		{
			route.push(make_pair(temp_num, oper + 'R'));
			visit[temp_num] = true;
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int l_int, r_int;
		cin >> l_int >> r_int;

		bfs(l_int, r_int);
	}

	return 0;
}
