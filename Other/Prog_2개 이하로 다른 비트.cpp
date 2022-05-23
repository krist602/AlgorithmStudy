//Programmers > ���� �ڵ� ç���� ����2 > 2�� ���Ϸ� �ٸ� ��Ʈ
//https://programmers.co.kr/learn/courses/30/lessons/87694

    //Ȧ���� ¦���� ��Ģ�� ã�ƾ� �ߴ� ����
    //�� ��ã���� !��

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
            answer.push_back(nums + 1); //¦����� nums + 1�� ���ǿ� �ش��ϴ� ����.
            continue;
        }
        else 
        {
            long long index = 2; //Ȧ����� �� ������ ��Ʈ�� ������ 1�̴�.
            long long tmp = nums;
            while (tmp <= nums)
            {
                tmp = nums ^ index; 
                if (tmp < nums) //���� index��ġ�� ��Ʈ�� 1�̶�� 0���� �ٲ�� ������ ���� ��������.
                {
                    tmp = nums;
                    index *= 2;
                }
                else //���� �������ٸ� �� ��ġ�� ��Ʈ�� 0�̴�.
                {
                    index /= 2;
                    tmp ^= index; //1�� 0���� �ٲ��ָ� ��ȯ �Ϸ�.
                    answer.push_back(tmp);
                }
            }
        }
    }

    return answer;
}