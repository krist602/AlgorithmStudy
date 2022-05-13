//Programmers > 월간 코드 챌린지 시즌2 > 괄호 회전하기
//https://programmers.co.kr/learn/courses/30/lessons/76502?language=cpp

    //stack을 쓰면 간단히 구현 가능한 string, brute force 문제 
    //마지막 조건에서 cur_s가 empty()이면서 IsRight도 empty()한지 검사해야한다. 그렇지 않으면 불완전한 문자열도 카운트를 세버린다.

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        string cur_s = s;
        stack<char> IsRight;

        while (!cur_s.empty())
        {
            if (cur_s.front() == '(' || cur_s.front() == '{' || cur_s.front() == '[')
            {
                IsRight.push(cur_s.front());
            }
            else if (IsRight.empty())
                break;
            else if (cur_s.front() == ')')
            {
                if (IsRight.top() == '(')
                    IsRight.pop();
                else
                    break;
            }
            else if (cur_s.front() == '}')
            {
                if (IsRight.top() == '{')
                    IsRight.pop();
                else
                    break;
            }
            else if (cur_s.front() == ']')
            {
                if (IsRight.top() == '[')
                    IsRight.pop();
                else
                    break;
            }

            cur_s.erase(0, 1);

            if (cur_s.empty() && IsRight.empty())
                answer++;
        }

        char front = s.front();
        s.erase(0, 1);
        s.push_back(front);
    }

    return answer;
}