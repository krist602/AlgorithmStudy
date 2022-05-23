//Programmers > 월간 코드 챌린지 시즌2 > 2개 이하로 다른 비트
//https://programmers.co.kr/learn/courses/30/lessons/87694

    //홀수와 짝수의 규칙을 찾아야 했던 문제
    //난 못찾았음 !ㅠ

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        long long nums = numbers[i];
        if (nums % 2 == 0)
        {
            answer.push_back(nums + 1); //짝수라면 nums + 1이 조건에 해당하는 수다.
            continue;
        }
        else 
        {
            long long index = 2; //홀수라면 맨 마지막 비트는 무조건 1이다.
            long long tmp = nums;
            while (tmp <= nums)
            {
                tmp = nums ^ index; 
                if (tmp < nums) //만약 index위치의 비트가 1이라면 0으로 바뀌기 때문에 값이 낮아진다.
                {
                    tmp = nums;
                    index *= 2;
                }
                else //값이 높아졌다면 그 위치의 비트는 0이다.
                {
                    index /= 2;
                    tmp ^= index; //1을 0으로 바꿔주면 변환 완료.
                    answer.push_back(tmp);
                }
            }
        }
    }

    return answer;
}