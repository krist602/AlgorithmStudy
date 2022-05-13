//Programmers > ���� �ڵ� ç���� ����2 > ��ȣ ȸ���ϱ�
//https://programmers.co.kr/learn/courses/30/lessons/76502?language=cpp

    //stack�� ���� ������ ���� ������ string, brute force ���� 
    //������ ���ǿ��� cur_s�� empty()�̸鼭 IsRight�� empty()���� �˻��ؾ��Ѵ�. �׷��� ������ �ҿ����� ���ڿ��� ī��Ʈ�� ��������.

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