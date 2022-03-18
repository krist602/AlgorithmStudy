//Programmers > ã�ƶ� ���α׷��� �������� > ���� �� �ִܰŸ�
//https://programmers.co.kr/learn/courses/30/lessons/1844

    //BFS
    //�ִܰŸ��� ã�� ������ BFS �ƴϸ� Dijkstra �����̴�.
    //BFS���� �Ÿ��� ���� ����Ϸ��� ������ �ϳ� ���� �־���� �Ѵ�. �� ĭ �� �� ������ �Ÿ�+=1 �� ����� �Ѵ�.

#include<vector>
#include<queue>
using namespace std;

int rowsize, colsize; //���� ���� �ִ��ε���( size()-1 )�� ����
bool visit[110][110] = { false }; //�湮 ��� üũ
int dy[4] = { 0, 1, 0, -1 }; //�� �� �� �� 
int dx[4] = { 1, 0, -1, 0 }; //�� �� �� ��

int bfs(vector<vector<int>>& maps, int row, int col)
{
    int count = 0;
    queue<pair<int, int>> route;
    vector<vector<int>> dist(rowsize + 1, vector<int>(colsize + 1)); //vector �ʱ�ȭ. ���� �ᵵ �Ź� ��Դ´�. ���� ����
    route.push(make_pair(row, col)); //�湮�� ��� push.
    visit[row][col] = true; //�湮�� ��� true üũ
    dist[row][col] = 1; //�������� ùĭ�� �Ÿ��� 1�� ����ߴ�.
    while (!route.empty())
    {
        int current_row = route.front().first;
        int current_col = route.front().second;
        route.pop();

        for (int i = 0; i < 4; i++) //i���� ���� ���� ������ �޶�����. �� �� �� ��
        {
            if (current_row + dy[i] > rowsize || current_row + dy[i] < 0 || current_col + dx[i] > colsize || current_col + dx[i] < 0) //���� ��ǥ�� vector�� ����� �Ѵ´ٸ� �����Ѵ�.
                continue;

            if (maps[current_row + dy[i]][current_col + dx[i]]) //maps[][]�� ��ǥ�� 1�̶��
            {
                if (visit[current_row + dy[i]][current_col + dx[i]]) //�̹� �湮�ߴٸ� �Ѿ��
                    continue;

                route.push(make_pair(current_row + dy[i], current_col + dx[i])); //�ƴ϶�� rout�� �־��ش�.
                visit[current_row + dy[i]][current_col + dx[i]] = true;
                dist[current_row + dy[i]][current_col + dx[i]] = dist[current_row][current_col] + 1;
            }
        }

    }
    if (!visit[rowsize][colsize]) //���࿡ ��ǥ������ �湮�� ���ߴٸ� -1�� return�Ѵ�.
        return -1;

    return dist[rowsize][colsize]; //�Ÿ� ����
}

int solution(vector<vector<int>> maps)
{
    rowsize = maps.size() - 1;
    colsize = maps[0].size() - 1;

    return bfs(maps, 0, 0);
}