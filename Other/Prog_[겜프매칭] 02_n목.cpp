//Programmers > 2022 Dev-Matching: ���� ���α׷��� > 02_n��

    //����Ž���� �̿��ߴ�.
    //n���� �Ƿ��� �������� �ϴ�, ����, ���ϴ�, ���ϴ� Ž���ؾߵǴϱ� ���� Ž�����ش�.

#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
    map<int, int> group; //1�� ������ ������ n���� ����ϴ� �뵵.
    int temp = 0;

    for (int i = 0; i < h; i++) //�������� n��
        for (int j = 0; j < w - n + 1; j++)
        {
            if (board[i][j] & 1) //1�� ������
            {
                for (int l = j; l < w; l++)
                    if (board[i][l] & 1) temp++;
                    else break;

                group[temp] += 1;
            }

            temp = 0;
        }

    for (int i = 0; i < h - n + 1; i++) //�ϴܹ��� n��
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] & 1) //1�� ������
            {
                for (int l = i; l < h; l++)
                    if (board[l][j] & 1) temp++;
                    else break;

                group[temp] += 1;
            }
            temp = 0;
        }

    for (int i = 0; i < h - n + 1; i++) //���ϴܹ��� n��
        for (int j = 0; j < w - n + 1; j++)
        {
            if (board[i][j] & 1) //1�� ������
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

    for (int i = 0; i < h - n + 1; i++) //���ϴܹ��� n��
        for (int j = n - 1; j < w; j++)
        {
            if (board[i][j] & 1) //1�� ������
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

    //n+1�� �̻��̾ n���� �Ѱ��� �����ϱ� n���� �����ְ� n+1���� ���ش�.
    answer += group[n];
    answer -= group[n + 1];

    return answer;
}