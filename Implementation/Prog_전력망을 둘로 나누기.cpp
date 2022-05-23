//Programmers > 위클리 챌린지 > 전력망을 둘로 나누기
//https://programmers.co.kr/learn/courses/30/lessons/86971

    //Union Find로 부모를 찾아서 푸는건가 했는데, 굳이 부모가 누구인지는 필요가 없어서 사용은 안했음.

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000000;
    
    for(int i = 0; i < wires.size(); i++)
    {
        //하나씩 끊어보고, 가장 작은 숫자를 answer에 저장
        vector<vector<int>> temp_wires(n + 1);
        vector<bool> visit(n + 1);
        queue<int> route;

        for(int j = 0; j < wires.size(); j++)
        {
            if(j == i)
                continue;
            
            temp_wires[wires[j][0]].push_back(wires[j][1]);
            temp_wires[wires[j][1]].push_back(wires[j][0]);
        }
        
        route.push(1);
        visit[1] = true;
        while(!route.empty())
        {
            int cur = route.front();
            route.pop();
                        
            for(int j = 0; j < temp_wires[cur].size(); j++)
                if(visit[temp_wires[cur][j]] == false)
                {
                    visit[temp_wires[cur][j]] = true;
                    route.push(temp_wires[cur][j]);
                }
        }
        
        int T = 0;
        
        for(int i = 1; i <= n; i++)
            if(visit[i])
                T++;
        
        answer = min(answer, abs(n-T-T));
    }
    return answer;
}