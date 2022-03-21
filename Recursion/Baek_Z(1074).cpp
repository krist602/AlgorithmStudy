//Baekjoon > 1074 > Z
//https://www.acmicpc.net/problem/1074

	//함수를 잘 짜보도록 하자

#include <iostream>

using namespace std;

int r, c;
int ans;
void Z(int row, int col, int size)
{
	if (row == r && c == col)
	{
		cout << ans << "\n";
		return;
	}

	if (r < row + size && r >= row && c < col + size && c >= col)
	{
		Z(row, col, size / 2);
		Z(row, col + size / 2, size / 2);
		Z(row + size / 2, col, size / 2);
		Z(row + size / 2, col + size / 2, size / 2);
	}
	else
	{
		ans += size * size;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;

	cin >> N >> r >> c;

	Z(0, 0, (1 << N)); //2^N을 표현하는 방법

	return 0;
}