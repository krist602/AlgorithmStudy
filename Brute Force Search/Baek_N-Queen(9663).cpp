//Baekjoon > 9663 > N-Queen
//https://www.acmicpc.net/problem/9663

	//���ͳݿ� �˻��ϰ�, �� �ڵ带 ���� �����ϴµ� �� ���� �ɷȴ�.
	//������ �а� õ��� ����;
	/*
	���� ó���� 2���� �迭�� �����ϰ� ���� �밡�ٱ������� ������ �ذ��Ϸ��� ������, 
	��ġ�� ������ �ʹ� ���� �߻��ϰ� �� ����� ���� �������� ���� ��� ������� �ߴµ�, 
	���丮��� ������� �ؼ� int���� �Ѱ踦 �Ѿ�� ������ �ְ�,
	(N = 4�̸� 4!, N = 5�̸� 5!��ŭ ��ġ�� ����)

	���� �ð��� �ʹ��ʹ��ʹ��ʹ��ʹ��ʹ��ʹ��ʹ� ���� �ɸ��� �����̶� �����ߴ�.
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
