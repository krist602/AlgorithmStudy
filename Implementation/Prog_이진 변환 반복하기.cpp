//Programmers > 월간 코드 챌린지 시즌1 > 이진 변환 반복하기
//https://programmers.co.kr/learn/courses/30/lessons/70129

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int sum_zero_num = 0; //전체 제거한 0의 개수
    int zero_num = 0; //각 연산마다 0의 개수
    int count = 0; //전체 연산의 횟수
    int len = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            zero_num++;
    }
    len -= zero_num; //총 길이에서 0만큼의 길이를 빼준다. 이후 len의 값을 2진수로 변환한다는 생각
    sum_zero_num += zero_num;
    count++;

    while (len != 1)
    {
        int t = len; //len을 2진수로 변환할 때 사용할 임시변수
        len = 0; //다음 연산에서의 길이를 알기 위해 초기화 해둠
        zero_num = 0;
        while (t != 0)
        {
            len++;

            if (t % 2 == 0)
                zero_num++; //임시 변수가 2로 나누어 떨어질 때 0이 생긴다.

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