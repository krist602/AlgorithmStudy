//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3��] n���� ����
//https://programmers.co.kr/learn/courses/30/lessons/17687
//2022-06-14(ȭ) 16:48

/*
    1. String reverse�Լ� ������ ����ص���. ���� <algorithm>����� �Լ��� ����ִٴ� ���� ��������.

    2. List[]�� ���� ���� �ϴ� ���� �־���.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char List[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string calc_n(int n, int i)
{
    string temp_str = "";

    do
    {
        temp_str += List[i % n];
        i /= n;
    } while (i);
    reverse(temp_str.begin(), temp_str.end());
    return temp_str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp_str = "";

    int i = 0;
    while (answer.size() < t)
    {
        temp_str += calc_n(n, i);

        if (temp_str.size() >= m)
        {
            answer += temp_str[p - 1];
            temp_str.erase(0, m);
        }
        i++;
    }

    return answer;
}