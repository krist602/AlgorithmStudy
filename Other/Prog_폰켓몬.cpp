//Programmers > 찾아라 프로그래밍 마에스터 > 폰켓몬
//https://programmers.co.kr/learn/courses/30/lessons/1845

    //map이 아니라 set를 써도 된다. (Value값은 중요하지 않기 때문)
    //하도 map이 익숙해서 map을 사용했다.

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