//Programmers > 찾아라 프로그래밍 마에스터 > 게임 맵 최단거리
//https://programmers.co.kr/learn/courses/30/lessons/1844

    //BFS
    //최단거리를 찾는 문제는 BFS 아니면 Dijkstra 문제이다.
    //BFS에서 거리를 따로 계산하려면 변수를 하나 새로 넣어줘야 한다. 한 칸 씩 들어갈 때마다 거리+=1 을 해줘야 한다.

#include<vector>
#include<queue>
using namespace std;

int rowsize, colsize; //열과 행의 최대인덱스( size()-1 )값 저장
bool visit[110][110] = { false }; //방문 노드 체크
int dy[4] = { 0, 1, 0, -1 }; //우 하 좌 상 
int dx[4] = { 1, 0, -1, 0 }; //우 하 좌 상

int bfs(vector<vector<int>>& maps, int row, int col)
{
    int count = 0;
    queue<pair<int, int>> route;
    vector<vector<int>> dist(rowsize + 1, vector<int>(colsize + 1)); //vector 초기화. 자주 써도 매번 까먹는다. 잊지 말기
    route.push(make_pair(row, col)); //방문한 노드 push.
    visit[row][col] = true; //방문한 노드 true 체크
    dist[row][col] = 1; //문제에서 첫칸의 거리를 1로 계산했다.
    while (!route.empty())
    {
        int current_row = route.front().first;
        int current_col = route.front().second;
        route.pop();

        for (int i = 0; i < 4; i++) //i값에 따라 다음 방향이 달라진다. 우 하 좌 상
        {
            if (current_row + dy[i] > rowsize || current_row + dy[i] < 0 || current_col + dx[i] > colsize || current_col + dx[i] < 0) //들어온 좌표가 vector의 사이즈를 넘는다면 포기한다.
                continue;

            if (maps[current_row + dy[i]][current_col + dx[i]]) //maps[][]의 좌표가 1이라면
            {
                if (visit[current_row + dy[i]][current_col + dx[i]]) //이미 방문했다면 넘어가고
                    continue;

                route.push(make_pair(current_row + dy[i], current_col + dx[i])); //아니라면 rout에 넣어준다.
                visit[current_row + dy[i]][current_col + dx[i]] = true;
                dist[current_row + dy[i]][current_col + dx[i]] = dist[current_row][current_col] + 1;
            }
        }

    }
    if (!visit[rowsize][colsize]) //만약에 목표지점에 방문을 안했다면 -1을 return한다.
        return -1;

    return dist[rowsize][colsize]; //거리 리턴
}

int solution(vector<vector<int>> maps)
{
    rowsize = maps.size() - 1;
    colsize = maps[0].size() - 1;

    return bfs(maps, 0, 0);
}