//Programmers > Summer/Winter Coding(~2018) > ��ųƮ��
//https://programmers.co.kr/learn/courses/30/lessons/49993

    //map�� �Ἥ �����ϰ� Ǯ����.
    //find�� contains, count�Լ��� ���°� �� ������ �� ���� �ϴ�.

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