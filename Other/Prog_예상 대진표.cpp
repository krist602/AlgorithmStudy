//Programmers > 2017 ����Ÿ�� > ���� ����ǥ
//https://programmers.co.kr/learn/courses/30/lessons/12985
 
    //Ǯ�� ���ϰ� �����͸� ��¦ �������ָ� �Ǵ� ����
    //�׷��� n�� �� �˷��ذɱ�

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