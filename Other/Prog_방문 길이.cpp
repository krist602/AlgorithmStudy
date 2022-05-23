//Programmers > Summer/Winter Coding(~2018) > 방문 길이
//https://programmers.co.kr/learn/courses/30/lessons/49994

    //<bool> visit을 사용했다. set<pair<int,int>>를 이용해서 2개의 좌표를 합친 하나의 수를 이용한 사람도 있었다.
    //시작점과 끝점 둘 다 넣어서 사용하는게 보거나 생각하기엔 더 편할 것 같다.

#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int dir_y[] = { 1, 0, -1, 0 };
    int dir_x[] = { 0, 1, 0, -1 };
    int x = 5, y = 5;
    vector<vector<vector<bool>>> visit(11, vector<vector<bool>>(11, (vector<bool>(4, false))));
    for (int i = 0; i < dirs.size(); i++)
    {
        int next_x = 0;
        int next_y = 0;
        int dir = 0;

        switch (dirs[i])
        {
        case 'U':
        {
            next_x = dir_x[0] + x;
            next_y = dir_y[0] + y;
            dir = 0;
            break;
        }
        case 'D':
        {
            next_x = dir_x[2] + x;
            next_y = dir_y[2] + y;
            dir = 2;
            break;
        }
        case 'R':
        {
            next_x = dir_x[1] + x;
            next_y = dir_y[1] + y;
            dir = 1;
            break;
        }
        case 'L':
        {
            next_x = dir_x[3] + x;
            next_y = dir_y[3] + y;
            dir = 3;
            break;
        }
        default:
            break;
        }

        if (next_x < 0 || next_y < 0 || next_x > 10 || next_y > 10) //나감
            continue;

        if (visit[next_x][next_y][dir])
        {
            x = next_x;
            y = next_y;
        }
        else
        {
            visit[next_x][next_y][dir] = true;
            visit[x][y][(dir + 2) % 4] = true;
            x = next_x;
            y = next_y;
            answer++;
        }
    }

    return answer;
}