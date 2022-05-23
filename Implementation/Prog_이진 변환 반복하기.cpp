//Programmers > ���� �ڵ� ç���� ����1 > ���� ��ȯ �ݺ��ϱ�
//https://programmers.co.kr/learn/courses/30/lessons/70129

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int sum_zero_num = 0; //��ü ������ 0�� ����
    int zero_num = 0; //�� ���긶�� 0�� ����
    int count = 0; //��ü ������ Ƚ��
    int len = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            zero_num++;
    }
    len -= zero_num; //�� ���̿��� 0��ŭ�� ���̸� ���ش�. ���� len�� ���� 2������ ��ȯ�Ѵٴ� ����
    sum_zero_num += zero_num;
    count++;

    while (len != 1)
    {
        int t = len; //len�� 2������ ��ȯ�� �� ����� �ӽú���
        len = 0; //���� ���꿡���� ���̸� �˱� ���� �ʱ�ȭ �ص�
        zero_num = 0;
        while (t != 0)
        {
            len++;

            if (t % 2 == 0)
                zero_num++; //�ӽ� ������ 2�� ������ ������ �� 0�� �����.

            t /= 2;
        }
        len -= zero_num;
        sum_zero_num += zero_num;
        count++;
    }

    answer.push_back(count);
    answer.push_back(sum_zero_num);

    return answer;
}