//Programmers > Summer/Winter Coding(~2018) > ������ ���� �̵�
//https://programmers.co.kr/learn/courses/30/lessons/12980

    //ó���� BFS�� DP�� ���������� �ð� �ʰ�, �޸� �ʰ�
    //���Ŀ� ��Ģ�� ã�ƺ���, 2������ 1�� ������ �ſ� �����ϴ���...

#include <iostream>

using namespace std;

int solution(int n)
{
    int ans = 0;
    int loc = n;

    while (loc != 0)
    {
        if (loc % 2 == 0) //¦����� �����ְ�
            loc /= 2;
        else //Ȧ����� ī��Ʈ�� 1 ���ϰ� 1���ش�.
        {
            loc -= 1;
            ans++;
        }
    }

    return ans;
}