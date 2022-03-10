//Programmers > 2022 Dev-Matching: 게임 프로그래머 > 02_n목

    //완전탐색을 이용했다.
    //n목이 되려면 위에부터 하단, 우측, 우하단, 좌하단 탐색해야되니까 각각 탐색해준다.

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
    map<int, int> group; //1을 만나면 주위에 n목을 기록하는 용도.
    int temp = 0;

    for (int i = 0; i < h; i++) //우측방향 n목
        for (int j = 0; j < w - n + 1; j++)
        {
            if (board[i][j] & 1) //1을 만나면
            {
                for (int l = j; l < w; l++)
                    if (board[i][l] & 1) temp++;
                    else break;

                group[temp] += 1;
            }

            temp = 0;
        }

    for (int i = 0; i < h - n + 1; i++) //하단방향 n목
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] & 1) //1을 만나면
            {
                for (int l = i; l < h; l++)
                    if (board[l][j] & 1) temp++;
                    else break;

                group[temp] += 1;
            }
            temp = 0;
        }

    for (int i = 0; i < h - n + 1; i++) //우하단방향 n목
        for (int j = 0; j < w - n + 1; j++)
        {
            if (board[i][j] & 1) //1을 만나면
            {
                int l = 0;
                while (i + l < h && j + l < w)
                {
                    if (board[i + l][j + l] & 1) temp++;
                    else break;

                    l++;
                }

                group[temp] += 1;
            }
            temp = 0;
        }

    for (int i = 0; i < h - n + 1; i++) //좌하단방향 n목
        for (int j = n - 1; j < w; j++)
        {
            if (board[i][j] & 1) //1을 만나면
            {
                int l = 0;
                while (i + l < h && j - l >= 0)
                {
                    if (board[i + l][j - l] & 1) temp++;
                    else break;

                    l++;
                }

                group[temp] += 1;
            }
            temp = 0;
        }

    //n+1목 이상이어도 n목이 한개는 나오니까 n목을 더해주고 n+1목을 빼준다.
    answer += group[n];
    answer -= group[n + 1];

    return answer;
}