//Programmers > Summer/Winter Coding(~2018) > 점프와 순간 이동
//https://programmers.co.kr/learn/courses/30/lessons/12980

    //처음엔 BFS나 DP로 구현했지만 시간 초과, 메모리 초과
    //이후에 규칙을 찾아보니, 2진법의 1의 개수와 매우 유사하더라...

#include <iostream>

using namespace std;

int solution(int n)
{
    int ans = 0;
    int loc = n;

    while (loc != 0)
    {
        ans += loc % 2; //홀수일 때만 ans에 값이 올라간다.
        loc /= 2;
    }

    return ans;
}
