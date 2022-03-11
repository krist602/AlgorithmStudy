//Programmers > 2017 팁스타운 > 예상 대진표
//https://programmers.co.kr/learn/courses/30/lessons/12985
 
    //풀기 편하게 데이터만 살짝 편집해주면 되는 문제
    //그래서 n은 왜 알려준걸까

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    a -= 1;
    b -= 1;

    while ((a /= 2) != (b /= 2))
        answer++;

    return answer;
}