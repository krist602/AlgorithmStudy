//DFS의 구현
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[9];
bool visited[9];

/*
	DFS는 Stack과 재귀함수 둘 모두를 이용해 구현할 수 있다.
*/

void dfs_recursive(int x)
{
	visited[x] = true; //방문한 노드의 방문여부를 True로 변경
	cout << x << endl; //방문한 노드 출력

	for (int i = 0; i < graph[x].size(); i++)
		if (!visited[graph[x][i]]) //기존에 방문하지 않았다면
			dfs_recursive(graph[x][i]); //DFS 호출
}

void dfs_stack(int start)
{
	stack<int> route; //경로를 저장할 Stack 선언
	route.push(start); //방문한 노드의 경로를 Stack에 Push
	visited[start] = true; //방문한 노드의 방문 여부를 True로 변경
	cout << route.top() << endl;

	while (!route.empty())
	{
		int x = route.top();
		route.pop();
		for (int i = 0; i < graph[x].size(); i++)
		{
			if (!visited[graph[x][i]])
			{
				cout << graph[x][i] << endl;
				route.push(x); //pop()을 했었기 때문에 현재 current_node도 Push
				route.push(graph[x][i]); //Stack이기 때문에 방문할 node를 Push
				visited[graph[x][i]] = true; //방문한 노드의 방문 여부를 True로 변경

				break;
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

	dfs_recursive(1);
	//dfs_stack(1);

	return 0;
}