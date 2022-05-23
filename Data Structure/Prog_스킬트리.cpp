//Programmers > Summer/Winter Coding(~2018) > 스킬트리
//https://programmers.co.kr/learn/courses/30/lessons/49993

    //map을 써서 간단하게 풀었다.
    //find나 contains, count함수를 쓰는게 더 좋았을 것 같긴 하다.

#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> pre_skill;

    for (int i = 0; i < skill.size(); i++)
        pre_skill[skill[i]] = i + 1;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        bool flag = true;
        int index = 1;

        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            char cur = skill_trees[i][j];

            if (pre_skill[cur])
            {
                if (pre_skill[cur] == index)
                    index++;
                else
                {
                    flag = false;
                    break;
                }
            }

        }

        if (flag)
            answer++;

    }

    return answer;
}