//Programmers > ���� �ڵ� ç���� ����3 > ���� ��� ����Ŭ
//https://programmers.co.kr/learn/courses/30/lessons/86052

    //���� Ǫ�� ����� �����س��� ������� �ٸ� ����� Ǯ�̸� ���� �����ߴ�.
    //������ ������� �����ؼ� ������ ����Ŭ�� �ϼ��ȴٴ� ���� �˾ƾ��Ѵ�.
    //������ Ǯ�̰� ������ dfs�� Ǫ�°� ���� �����ϱ� ������.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
int rowsize, colsize;
bool visit[500][500][4] = { false };
char arr[500][500];
int drow[4] = { 0, 1, 0, -1 }; //��, ��, ��, ��
int dcol[4] = { 1, 0, -1, 0 };


void dfs(int row, int col, int dir, int count)
{
    if (visit[row][col][dir])
    {
        answer.push_back(count - 1);
        return;
    }

    char t = arr[row][col];
    int next_dir = dir;
    int next_row = 0;
    int next_col = 0;

    visit[row][col][dir] = true;

    if (t == 'L')
        next_dir = (dir + 1) % 4;
    else if (t == 'R')
        next_dir = (dir + 3) % 4;

    next_row = row + drow[next_dir];
    next_col = col + dcol[next_dir];
    if (next_row >= rowsize)
        next_row -= rowsize;
    else if (next_row < 0)
        next_row += rowsize;

    if (next_col >= colsize)
        next_col -= colsize;
    else if (next_col < 0)
        next_col += colsize;

    dfs(next_row, next_col, next_dir, count + 1);
}

vector<int> solution(vector<string> grid) {
    rowsize = grid.size();
    colsize = grid[0].size();

    for (int i = 0; i < rowsize; i++)
        for (int j = 0; j < colsize; j++)
            arr[i][j] = grid[i][j];

    for (int i = 0; i < rowsize; i++)
        for (int j = 0; j < colsize; j++)
            for (int k = 0; k < 4; k++) //��0, ��1, ��2, ��3
            {
                if (visit[i][j][k])
                    continue;
                dfs(i, j, k, 1);
            }

    sort(answer.begin(), answer.end());

    return answer;
}