//Programmers > ã�ƶ� ���α׷��� �������� > ���ϸ�
//https://programmers.co.kr/learn/courses/30/lessons/1845

    //map�� �ƴ϶� set�� �ᵵ �ȴ�. (Value���� �߿����� �ʱ� ����)
    //�ϵ� map�� �ͼ��ؼ� map�� ����ߴ�.

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> ketmon;

    for (auto n : nums)
        ketmon[n] += 1;

    return min(nums.size() / 2, ketmon.size());
}