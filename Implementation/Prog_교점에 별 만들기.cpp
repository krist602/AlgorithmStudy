//Programmers > ��Ŭ�� ç���� > ������ �� �����
//https://programmers.co.kr/learn/courses/30/lessons/87377

    //10�� * 10�� = int�� overflow�̱⿡ ������ long long���� ���������.
    //unsigned long long�� �� �ȵǳ� �����غ��ϱ� ������� ������ ���´� ����; �� ��û�̴�.
    //�ڵ带 �� �̻ڰ� ������ �� �����ٵ� ���� �Ϳ� �ޱ��޴�. string�� ��뿡 �ͼ����� �ʿ䰡 �ִ�.

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
    �̷��� § ����� �ִµ�, �ξ� ����ϰ� ���� �� ����.

    long long row = max_y - min_y + 1;
    long long col = max_x - min_x + 1;
    string temp(col, '.');  col������ŭ .���� �����,
    answer.assign(row, temp); row������ŭ temp�� �־��ش�. ���Ϳ��� �̷��Ե� Ȱ���� �� �ֱ���.

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