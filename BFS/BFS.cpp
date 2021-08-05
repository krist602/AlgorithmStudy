//BFS�� ����
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[9];
bool visited[9];

void bfs(int start)
{
	queue<int> route; //��θ� ���� Queue ����
	route.push(start); //���۳�带 Queue�� Push
	visited[start] = true; //Queue�� Push�� ����� �湮 ���δ� True�� ��ȯ
	while (!route.empty()) //Queue�� �� ������ �ݺ��Ѵ�
	{
		int current_node = route.front();
		cout << route.front() << endl;
		route.pop();

		for (int i = 0; i < graph[current_node].size(); i++)
		{
			if (!visited[graph[current_node][i]]) //�������� �� ��带 �湮�߾����� Ȯ��
			{
				route.push(graph[current_node][i]); //�湮���� �ʾ��� ��쿣 ���� ��带 Push�ϰ� �湮���θ� �ٲ��ش�.
				visited[graph[current_node][i]] = true;
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

	bfs(1);

	return 0;
}