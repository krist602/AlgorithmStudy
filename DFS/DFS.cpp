//DFS�� ����
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[9];
bool visited[9];

/*
	DFS�� Stack�� ����Լ� �� ��θ� �̿��� ������ �� �ִ�.
*/

void dfs_recursive(int x)
{
	visited[x] = true; //�湮�� ����� �湮���θ� True�� ����
	cout << x << endl; //�湮�� ��� ���

	for (int i = 0; i < graph[x].size(); i++)
		if (!visited[graph[x][i]]) //������ �湮���� �ʾҴٸ�
			dfs_recursive(graph[x][i]); //DFS ȣ��
}

void dfs_stack(int start)
{
	stack<int> route; //��θ� ������ Stack ����
	route.push(start); //�湮�� ����� ��θ� Stack�� Push
	visited[start] = true; //�湮�� ����� �湮 ���θ� True�� ����
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
				route.push(x); //pop()�� �߾��� ������ ���� current_node�� Push
				route.push(graph[x][i]); //Stack�̱� ������ �湮�� node�� Push
				visited[graph[x][i]] = true; //�湮�� ����� �湮 ���θ� True�� ����

				break;
			}
		}
	}
}

int main()
{
	/*
		�׷����� 2���� �迭�̳� ���͸� �̿��Ͽ� ������ �� �ִ�.
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