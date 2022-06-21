//Programmers > 2021 KAKAO BLIND RECRUITMENT > 메뉴 리뉴얼
//https://programmers.co.kr/learn/courses/30/lessons/72411
//2022-06-21(화) 17:31

/*
        1. 문제를 아주 상세하게 읽고 이해하자. 글자 길다고 대충 읽지말자
    
        2. DFS문제의 응용버전이다. 처음엔 비트연산 이용해서 풀려고 했는데, 그렇게 하니까 ADE와 AD라는 메뉴가 있으면 AD가 두번 나오는데, 그걸 골라내지 못했다.

        3. cmp 작성하는거 잘 기억하자.
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
                if (n.second == m && m > 1) //여러 명이 메뉴를 골라야 한다. 1번 고른 것은 해당되지 않기에 m > 1이 필요하다.
                    answer.push_back(n.first);
                else
                    break;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}