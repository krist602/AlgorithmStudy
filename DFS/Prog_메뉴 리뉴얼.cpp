//Programmers > 2021 KAKAO BLIND RECRUITMENT > �޴� ������
//https://programmers.co.kr/learn/courses/30/lessons/72411
//2022-06-21(ȭ) 17:31

/*
        1. ������ ���� ���ϰ� �а� ��������. ���� ��ٰ� ���� ��������
    
        2. DFS������ ��������̴�. ó���� ��Ʈ���� �̿��ؼ� Ǯ���� �ߴµ�, �׷��� �ϴϱ� ADE�� AD��� �޴��� ������ AD�� �ι� �����µ�, �װ� ����� ���ߴ�.

        3. cmp �ۼ��ϴ°� �� �������.
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& l, pair<string, int>& r)
{
    return l.second > r.second;
}

void dfs(string orders, vector<int>& course, map<string, int>& create, string menu, int count, int index)
{
    for (auto c : course)
        if (count == c)
        {
            sort(menu.begin(), menu.end());
            create[menu] += 1;
            break;
        }

    if (index > orders.size())
        return;

    for (int l = index; l < orders.size(); l++)
        dfs(orders, course, create, menu + orders[l], count + 1, l + 1);

    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> create;
    vector<vector<pair<string, int>>> new_menu(11, vector<pair<string, int>>());

    for (int i = 0; i < orders.size(); i++)
        dfs(orders[i], course, create, "", 0, 0);

    for (auto c : create)
        new_menu[c.first.length()].push_back(make_pair(c.first, c.second));

    for (int i = 0; i < course.size(); i++)
    {
        sort(new_menu[course[i]].begin(), new_menu[course[i]].end(), cmp);

        if (new_menu[course[i]].size() > 0)
        {
            int m = new_menu[course[i]][0].second;

            for (auto n : new_menu[course[i]])
                if (n.second == m && m > 1) //���� ���� �޴��� ���� �Ѵ�. 1�� �� ���� �ش���� �ʱ⿡ m > 1�� �ʿ��ϴ�.
                    answer.push_back(n.first);
                else
                    break;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}