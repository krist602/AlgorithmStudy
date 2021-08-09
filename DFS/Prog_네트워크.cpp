//Programmers > 깊이/너비 우선 탐색(DFS/BFS) > 네트워크
//https://programmers.co.kr/learn/courses/30/lessons/43162


    //같은 네트워크에 연결되어있는 컴퓨터를 모두 제거한다.
    //DFS

#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int x)
{
    if (!computers[x][x]) //이미 탐색한 곳이라면 False이기 때문에 return false;
        return false;
    computers[x][x] = 0; //탐색한 컴퓨터의 값을 False처리
    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[x][i]) //경로상의 모든 컴퓨터를 방문한다.
            dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] && dfs(computers, i))
            answer += 1;
    }

    return answer;
}