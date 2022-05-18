//Programmers > Summer/Winter Coding(~2018) > ���
//https://programmers.co.kr/learn/courses/30/lessons/12978

    //���ͽ�Ʈ�� �˰��� ���
    //IDE�� ������� �ʰ� Programmers������ �ذ�.
    //Programmers���� �ٷ� �ڵ��ϴ� ������ �ؾߵ� �� ����... �ʹ� ����

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<int> distance(N + 1, -1);
    vector<vector<pair<int, int>>> edit_road(N + 1);
    for (int i = 0; i < road.size(); i++)
    {
        edit_road[road[i][0]].push_back(make_pair(road[i][2], road[i][1]));
        edit_road[road[i][1]].push_back(make_pair(road[i][2], road[i][0]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> route;
    route.push(make_pair(0, 1));

    while (!route.empty())
    {
        int cur = route.top().second;
        int dist = route.top().first;

        route.pop();

        if (distance[cur] != -1 && distance[cur] <= dist)
            continue;

        distance[cur] = dist;

        for (int i = 0; i < edit_road[cur].size(); i++)
        {
            int next_loc = edit_road[cur][i].second;
            int next_dist = edit_road[cur][i].first + dist;

            if (distance[next_loc] > next_dist)
                continue;

            route.push(make_pair(next_dist, next_loc));
        }

    }

    for (int i = 1; i <= N; i++)
        if (distance[i] <= K)
            answer++;

    return answer;
}