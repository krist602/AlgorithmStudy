//Programmers > Summer/Winter Coding(~2018) > �湮 ����
//https://programmers.co.kr/learn/courses/30/lessons/49994

    //<bool> visit�� ����ߴ�. set<pair<int,int>>�� �̿��ؼ� 2���� ��ǥ�� ��ģ �ϳ��� ���� �̿��� ����� �־���.
    //�������� ���� �� �� �־ ����ϴ°� ���ų� �����ϱ⿣ �� ���� �� ����.

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

        if (next_x < 0 || next_y < 0 || next_x > 10 || next_y > 10) //����
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