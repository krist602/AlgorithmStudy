//Programmers > 월간 코드 챌린지 시즌3 > 빛의 경로 사이클
//https://programmers.co.kr/learn/courses/30/lessons/86052

    //문제 푸는 방식을 생각해내기 어려워서 다른 사람의 풀이를 보고 이해했다.
    //들어오는 방향까지 생각해서 같으면 사이클이 완성된다는 것을 알아야한다.
    //수많은 풀이가 있지만 dfs로 푸는게 가장 이해하기 쉬웠다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
int rowsize, colsize;
bool visit[500][500][4] = { false };
char arr[500][500];
int drow[4] = { 0, 1, 0, -1 }; //우, 하, 좌, 상
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
            for (int k = 0; k < 4; k++) //우0, 하1, 좌2, 상3
            {
                if (visit[i][j][k])
                    continue;
                dfs(i, j, k, 1);
            }

    sort(answer.begin(), answer.end());

    return answer;
}