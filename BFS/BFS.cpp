//BFS의 구현
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[9];
bool visited[9];

void bfs(int start)
{
	queue<int> route; //경로를 담을 Queue 선언
	route.push(start); //시작노드를 Queue에 Push
	visited[start] = true; //Queue에 Push한 노드의 방문 여부는 True로 전환
	while (!route.empty()) //Queue가 빌 때까지 반복한다
	{
		int current_node = route.front();
		cout << route.front() << endl;
		route.pop();

		for (int i = 0; i < graph[current_node].size(); i++)
		{
			if (!visited[graph[current_node][i]]) //다음으로 갈 노드를 방문했었는지 확인
			{
				route.push(graph[current_node][i]); //방문하지 않았을 경우엔 다음 노드를 Push하고 방문여부를 바꿔준다.
				visited[graph[current_node][i]] = true;
			}
		}
	}
}

int main()
{
	/*
		그래프는 2차원 배열이나 벡터를 이용하여 구현할 수 있다.
	*/
	graph[1].push_back(2);
	graph[1].push_back(5);
	graph[1].push_back(9);

	graph[2].push_back(3);
	graph[2].push_back(4);

	graph[3].push_back(7);
	graph[3].push_back(8);

	graph[5].push_back(6);

	bfs(1);

	return 0;
}