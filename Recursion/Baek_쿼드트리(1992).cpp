//Baekjoon > 1992 > 쿼드트리
//https://www.acmicpc.net/problem/1992

	//특이사항이 없던 재귀문제
	//굳이 찾자면 데이터의 입력이 띄어쓰기로 구분이 안되어있어서 char형으로 받았다.
	//string형식으로 받는게 메모리상으로는 이득이었을 것 같다.

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& image, int size, int row, int col)
{
	char check = image[row][col];

	for (int i = row; i < row + size; i++)
		for (int j = col; j < col + size; j++)
		{
			if (check != image[i][j])
			{
				cout << '(';
				solve(image, size / 2, row, col);
				solve(image, size / 2, row, col + size / 2);
				solve(image, size / 2, row + size / 2, col);
				solve(image, size / 2, row + size / 2, col + size / 2);
				cout << ')';
				return;
			}
		}

	cout << check - 48;

	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<vector<char>> image(N, vector<char>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> image[i][j];

	solve(image, N, 0, 0);

	return 0;
}