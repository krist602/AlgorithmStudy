//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3차] n진수 게임
//https://programmers.co.kr/learn/courses/30/lessons/17687
//2022-06-14(화) 16:48

/*
    1. String reverse함수 사용법을 기억해두자. 또한 <algorithm>헤더에 함수가 들어있다는 점에 유의하자.

    2. List[]를 만들어서 뱉어야 하는 점이 있었다.
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