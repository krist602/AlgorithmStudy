//Programmers > ��Ŭ�� ç���� > �Ƿε�
//https://programmers.co.kr/learn/courses/30/lessons/87946

    //ó���� BFS�� Ǯ���� �ߴµ�, Visit ������ ������� DFS�� ��ȯ

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& dungeons, vector<bool>& visit, int p, int count, int *max)
{
    if(*max < count)
        *max = count;
    
    if(count == dungeons.size())
        return;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        int need_p = dungeons[i][0];
        int use_p = dungeons[i][1];
        if(need_p > p || visit[i])
            continue;
        
        visit[i] = true;
        dfs(dungeons, visit, p - use_p, count + 1, max);
        visit[i] = false;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -1;
    vector<bool> visit(dungeons.size() + 1, false);
    dfs(dungeons, visit, k, 0, &answer);
    
    return answer;
}