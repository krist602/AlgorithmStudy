//Programmers > 2018 KAKAO BLIND RECRUITMENT > [1��] ���� Ŭ�����͸�
//https://programmers.co.kr/learn/courses/30/lessons/17677

    //isalpha��� �Լ��� ������ϴ�.
    //isalpha�� ���ĺ��빮�ڸ� 1��, �ҹ��ڸ� 2�� return�ϰ�, �� �ܿ��� 0�� return�ϴ� �Լ��̴�.
    //�׷��� �׳� map�� pair�� ������Ѽ� ū ���� �����ո����, ���� ���� �����ո���� �ְ� ����ߴ�.
    //userǮ���߿� ��� �ִ� ���� ��ó�� map�� string���� �����ϴ°� �ƴ϶� �ڸ����������� AB�� ��� (A&31)*26 + B&31 �������� ����� ��찡 �־���.
    //A���� Z���� �� 26���̹Ƿ� 00001���� 11010 �� 5��Ʈ�� ���� ǥ���� �� �ֱ� ������ &31(11111)�� �̿��� ��Ʈ������ �ؼ� ���� �ٿ��� ���̴�.

#include <string>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int min = 0;
    int max = 0;
    map<string, pair<int, int>> group;

    string l_str = str1;
    transform(l_str.begin(), l_str.end(), l_str.begin(), ::toupper);

    string r_str = str2;
    transform(r_str.begin(), r_str.end(), r_str.begin(), ::toupper);

    for (int i = 0; i < l_str.size() - 1; i++)
        if (isalpha(l_str[i]) && isalpha(l_str[i + 1]))
            group[l_str.substr(i, 2)].first += 1;

    for (int i = 0; i < r_str.size() - 1; i++)
        if (isalpha(r_str[i]) && isalpha(r_str[i + 1]))
            group[r_str.substr(i, 2)].second += 1;

    for (auto g : group)
    {
        if (g.second.first >= g.second.second)
        {
            max += g.second.first;
            min += g.second.second;
        }
        else
        {
            max += g.second.second;
            min += g.second.first;
        }
    }

    return min < max ? min * 65536 / max : 65536;
}