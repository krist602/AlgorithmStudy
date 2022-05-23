//Programmers > 위클리 챌린지 > 교점에 별 만들기
//https://programmers.co.kr/learn/courses/30/lessons/87377

    //10만 * 10만 = int형 overflow이기에 변수를 long long으로 선언해줬다.
    //unsigned long long은 왜 안되나 생각해보니까 결과값에 음수도 나온다 ㅎㅎ; 난 멍청이다.
    //코드를 더 이쁘게 정리할 수 있을텐데 내는 것에 급급햇다. string의 사용에 익숙해질 필요가 있다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {

    vector<pair<long long, long long>> pos;
    long long min_x = 10000000000; long long max_x = -10000000000;
    long long min_y = 10000000000; long long max_y = -10000000000;

    for (int i = 0; i < line.size() - 1; i++)
    {
        long long A = (long long)line[i][0];
        long long B = (long long)line[i][1];
        long long E = (long long)line[i][2];

        for (int j = i + 1; j < line.size(); j++)
        {
            long long C = (long long)line[j][0];
            long long D = (long long)line[j][1];
            long long F = (long long)line[j][2];

            if (A * D - B * C == 0)
                continue;

            if ((B * F - E * D) % (A * D - B * C) == 0 && (E * C - A * F) % (A * D - B * C) == 0)
            {
                pos.push_back(make_pair(((B * F - E * D) / (A * D - B * C)), ((E * C - A * F) / (A * D - B * C))));

                if ((B * F - E * D) / (A * D - B * C) > max_x)
                    max_x = (B * F - E * D) / (A * D - B * C);
                if ((B * F - E * D) / (A * D - B * C) < min_x)
                    min_x = (B * F - E * D) / (A * D - B * C);

                if ((E * C - A * F) / (A * D - B * C) > max_y)
                    max_y = (E * C - A * F) / (A * D - B * C);
                if ((E * C - A * F) / (A * D - B * C) < min_y)
                    min_y = (E * C - A * F) / (A * D - B * C);
            }
        }
    }
    /*
    이렇게 짠 사람도 있는데, 훨씬 깔끔하고 좋은 것 같다.

    long long row = max_y - min_y + 1;
    long long col = max_x - min_x + 1;
    string temp(col, '.');  col개수만큼 .으로 만들고,
    answer.assign(row, temp); row개수만큼 temp를 넣어준다. 벡터에서 이렇게도 활용할 수 있구나.

    for(int i=0;i<v.size();i++)
    {
        long long y = v[i].y;
        long long x = v[i].x;
        answer[max_y - y][x - min_x]='*';
    }

    */

    max_x -= min_x;
    max_y -= min_y;

    vector<string> answer(max_y + 1);
    for (int j = 0; j <= max_y; j++)
        for (int i = 0; i <= max_x; i++)
            answer[j].push_back('.');

    for (auto p : pos)
        answer[p.second - min_y][p.first - min_x] = '*';

    reverse(answer.begin(), answer.end());

    return answer;
}