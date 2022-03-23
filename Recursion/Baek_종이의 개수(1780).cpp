//Baekjoon > 1780 > 종이의 개수
//https://www.acmicpc.net/problem/1780

	//색종이 만들기와 아주 유사한 문제.

#include <iostream>
#include <vector>

using namespace std;

void cutting(vector<vector<int>>& papers, int row, int col, int size, int* m, int* z, int* p)
{
	int check = papers[row][col];
	for (int i = row; i < row + size; i++)
		for (int j = col; j < col + size; j++)
			if (check != papers[i][j])
			{
				cutting(papers, row, col, size / 3, m, z, p);
				cutting(papers, row, col + size / 3, size / 3, m, z, p);
				cutting(papers, row, col + size / 3 + size / 3, size / 3, m, z, p);
				cutting(papers, row + size / 3, col, size / 3, m, z, p);
				cutting(papers, row + size / 3, col + size / 3, size / 3, m, z, p);
				cutting(papers, row + size / 3, col + size / 3 + size / 3, size / 3, m, z, p);
				cutting(papers, row + size / 3 + size / 3, col, size / 3, m, z, p);
				cutting(papers, row + size / 3 + size / 3, col + size / 3, size / 3, m, z, p);
				cutting(papers, row + size / 3 + size / 3, col + size / 3 + size / 3, size / 3, m, z, p);
				return;
			}

	if (check == -1)
		*m += 1;
	else if (check)
		*p += 1;
	else
		*z += 1;

	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, m = 0, z = 0, p = 0;
	cin >> N;
	vector<vector<int>> papers(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> papers[i][j];

	cutting(papers, 0, 0, N, &m, &z, &p);

	cout << m << "\n" << z << "\n" << p << "\n";

	return 0;
}