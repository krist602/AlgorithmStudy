//Baekjoon > 9663 > N-Queen
//https://www.acmicpc.net/problem/9663

	//인터넷에 검색하고, 그 코드를 보고도 이해하는데 좀 오래 걸렸다.
	//세상은 넓고 천재는 많다;
	/*
	나는 처음에 2차원 배열을 선언하고 완전 노가다구현으로 문제를 해결하려고 했으나, 
	겹치는 정답이 너무 많이 발생하고 그 답들을 서로 구분해줄 수가 없어서 나눠줘야 했는데, 
	팩토리얼로 나눠줘야 해서 int형의 한계를 넘어서는 문제가 있고,
	(N = 4이면 4!, N = 5이면 5!만큼 겹치게 나옴)

	또한 시간이 너무너무너무너무너무너무너무너무 많이 걸리는 구현이라 실패했다.
	*/

#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& board, int N, int level)
{
	for (int i = 0; i < level; i++)
	{
		if (board[i] == board[level] || abs(board[i] - board[level]) == level - i)
			return false;
	}
	return true;
}

void N_queen(vector<int>& board, int N, int level, int* answer)
{
	if (N == level)
	{
		*answer = *answer + 1;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		board[level] = i;
		if (check(board, N, level))
			N_queen(board, N, level + 1, answer);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, answer = 0;
	cin >> N;
	vector<int> board(N, 0);

	N_queen(board, N, 0, &answer);
	cout << answer << endl;

	return 0;
}
