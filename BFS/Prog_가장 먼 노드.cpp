//Programmers > �׷��� > ���� �� ���
//https://programmers.co.kr/learn/courses/30/lessons/49189


	//����� ������ ��� Ž���Ͽ� �Ÿ��� �Է������ �Ѵ�.
	//bfs
	//��� ����� ���� �ٽ� Ǯ�� ������, �ð��ʰ��� ���Ծ��µ�, �� ������ bfs�� ���ڸ� ������ �� �ּҰ� �ƴ϶� value�� �����߾ �׷���.
	//      vector<vector<bool>> graph -> vector<vector<bool>> &graph

#include <vector>
#include <algorithm>

using namespace std;

void bfs(int current, vector<vector<bool>>& graph, vector<int>& distance, vector<int> route)
{
	vector<int> t_route; //���� BFS�� ���� �ӽ� queue ����

	while (!route.empty()) //route�� �� ������ �ݺ�
	{
		for (int i = 1; i < graph[route[0]].size(); i++) 
		{
			if (graph[route[0]][i] && !distance[i]) //����Ǿ��ִ°� && �˻��ߴ°�
			{
				distance[i] = current; //distance�� ������� �� �Ÿ� �߰�
				t_route.push_back(i); //�������� Ž���� ��� �߰�
			}
		}
		route.erase(route.begin()); //�� ���� ���ڸ� �����ش�. ����߱⶧��.
	}
	if (!t_route.empty())
		bfs(current + 1, graph, distance, t_route); //�˰����� ¥�ٰ� �� ���ŷӰ� �ӽ�queue�� ���� ���� �����ִ°� �����ߴµ�, current�� ����ϱ� ������ �� ����.
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<bool>> graph(n, (vector<bool>(n, false))); //����Ǿ� �ִ� ������ �˻��ϱ� ���� 2���� �迭 ����
	vector<int> distance(n); //�Ÿ��� �� vector

	for (auto a : edge)
	{
		graph[a[0] - 1][a[1] - 1] = true; //����Ǿ��ִ� ��忡 true�� �Է�
		graph[a[1] - 1][a[0] - 1] = true;
	}
	
	//BFS ����. { 0 }�� ���� �������. ó���� queue<int>�� �����߾��µ�, queue���� ���� ���� ������ ����� ã�� ���ߴ�.
	//��� queue�� �����Ϸ��� ���ʿ� queue�� ���� �Ȱ��� �ּ������� �ϸ� �ȴ�. queue<int> &route
	bfs(1, graph, distance, { 0 }); 

	int max = *max_element(distance.begin(), distance.end()); //���� ū ���� ã�Ƽ� �׿� ���� �Ÿ��� ���� ++
	for (auto a : distance)
		if (max == a)
			answer++;

	return answer;
}