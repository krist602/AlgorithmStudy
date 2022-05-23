//Programmers > ��Ŭ�� ç���� > ���¸��� �ѷ� ������
//https://programmers.co.kr/learn/courses/30/lessons/86971

    //Union Find�� �θ� ã�Ƽ� Ǫ�°ǰ� �ߴµ�, ���� �θ� ���������� �ʿ䰡 ��� ����� ������.

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000000;
    
    for(int i = 0; i < wires.size(); i++)
    {
        //�ϳ��� �����, ���� ���� ���ڸ� answer�� ����
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