//Baekjoon > 2630 > ������ �����
//https://www.acmicpc.net/problem/2630

    //

#include <iostream>
#include <vector>

using namespace std;

void cutting(vector<vector<int>>& paper, int row, int col, int size, int* white, int* blue)
{
    int color = paper[row][col];

    for (int r = row; r < row + size; r++)
        for (int c = col; c < col + size; c++)
            if (color != paper[r][c])
            {
                cutting(paper, row, col, size / 2, white, blue); //���� �� Ž��
                cutting(paper, row, col + size / 2, size / 2, white, blue); //������ �� Ž��
                cutting(paper, row + size / 2, col, size / 2, white, blue); //���� �Ʒ� Ž��
                cutting(paper, row + size / 2, col + size / 2, size / 2, white, blue); //������ �Ʒ� Ž��
                return;
            }

    if (color == 1)
    {
        *blue += 1;
        return;
    }
    *white += 1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, blue = 0, white = 0;

    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    cutting(paper, 0, 0, N, &white, &blue);

    cout << white << "\n" << blue << "\n";

    return 0;
}