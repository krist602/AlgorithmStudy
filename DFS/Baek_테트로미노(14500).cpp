//Baekjoon > 14500 > 테트로미노
//https://www.acmicpc.net/problem/14500

	//하나씩 다 노가다로 구하려고(완전탐색) 했는데 실패함. 어디서 어떤 도형이 문젠지도 모르겠어서 검색해봄.
	//알고보니 DFS + 브루트포스.
	//전역변수 진짜 쓰기 싫었는데 ㅠ

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dir_r[] = { 0, 1, 0, -1 };
int dir_c[] = { 1, 0, -1, 0 };
int sum = 0;

void dfs(vector<vector<int>>& paper, vector<vector<bool>>& visit, int N, int M, int r, int c, int count, int value)
{
	if (count == 3)
	{
		sum = max(sum, value);
		return;
	}

	int next_r = 0;
	int next_c = 0;
	for (int i = 0; i < 4; i++)
	{
		next_r = r + dir_r[i];
		next_c = c + dir_c[i];

		if (next_r >= N || next_r < 0 || next_c >= M || next_c < 0)
			continue;

		if (visit[next_r][next_c])
			continue;

		visit[next_r][next_c] = true;
		dfs(paper, visit, N, M, next_r, next_c, count + 1, value + paper[next_r][next_c]);
		visit[next_r][next_c] = false;
	}
}

void T1(vector<vector<int>>& paper, int N, int M, int r, int c)
{
	int value = 0;
	int row[] = { r, r + 1, r + 2, r + 1 }; //ㅏ
	int col[] = { c, c, c, c + 1 };

	for (int i = 0; i < 4; i++)
	{

		if (row[i] < 0 || row[i] >= N || col[i] < 0 || col[i] >= M)
			return;
		value += paper[row[i]][col[i]];
	}
	sum = max(sum, value);
}

void T2(vector<vector<int>>& paper, int N, int M, int r, int c)
{
	int value = 0;
	int row[] = { r, r, r, r + 1 }; //ㅜ
	int col[] = { c, c + 1, c + 2, c + 1 };

	for (int i = 0; i < 4; i++)
	{

		if (row[i] < 0 || row[i] >= N || col[i] < 0 || col[i] >= M)
			return;
		value += paper[row[i]][col[i]];
	}
	sum = max(sum, value);
}

void T3(vector<vector<int>>& paper, int N, int M, int r, int c)
{
	int value = 0;
	int row[] = { r, r + 1, r + 2, r + 1 }; //ㅓ
	int col[] = { c, c, c, c - 1 };

	for (int i = 0; i < 4; i++)
	{

		if (row[i] < 0 || row[i] >= N || col[i] < 0 || col[i] >= M)
			return;
		value += paper[row[i]][col[i]];
	}
	sum = max(sum, value);
}

void T4(vector<vector<int>>& paper, int N, int M, int r, int c)
{
	int value = 0;
	int row[] = { r, r, r, r - 1 }; //ㅗ
	int col[] = { c, c + 1, c + 2, c + 1 };

	for (int i = 0; i < 4; i++)
	{

		if (row[i] < 0 || row[i] >= N || col[i] < 0 || col[i] >= M)
			return;
		value += paper[row[i]][col[i]];
	}
	sum = max(sum, value);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	int value = 0;

	vector<vector<int>> paper(N, vector<int>(M, 0));
	vector<vector<bool>> visit(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> paper[i][j];

	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
		{
			T1(paper, N, M, r, c);
			T2(paper, N, M, r, c);
			T3(paper, N, M, r, c);
			T4(paper, N, M, r, c);

			visit[r][c] = true;
			dfs(paper, visit, N, M, r, c, 0, paper[r][c]);
			visit[r][c] = false;
		}

	cout << sum << "\n";

	return 0;
}
