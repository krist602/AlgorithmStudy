#include <iostream>
#include <vector>

using namespace std;

int number = 4;
int INF = 1000000000; //int���� 21������̱⿡ ������ ǥ�����ַ��� 10���� ���.

void FloydWarshall(vector<vector<int>>& graph, vector<vector<int>>& distance)
{
	for (int k = 0; k < number; k++) //k = ���İ��� ���
		for (int i = 0; i < number; i++) //i = ��� ���
			for (int j = 0; j < number; j++) //j = ���� ���
				distance[i][k] + distance[k][j] < distance[i][j] ? distance[i][j] = distance[i][k] + distance[k][j] : distance[i][j];

}

int main()
{
	vector<vector<int>> graph = { {0, 5, INF, 8}, {7, 0, 9, INF}, {2, INF, 0, 4}, {INF, INF, 3, 0} };
	vector<vector<int>> distance(number, vector<int>(number, 0));

	for (int i = 0; i < number; i++)
		for (int j = 0; j < number; j++)
			distance[i][j] = graph[i][j];

	FloydWarshall(graph, distance);

	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
			cout << distance[i][j] << "  ";
		cout << endl;
	}

	return 0;
}