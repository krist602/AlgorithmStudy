//Baekjoon > 13913 > ���ٲ��� 4
//https://www.acmicpc.net/problem/13913

	//������ ��θ� �����ؾ� �Ǿ��� ����
	//ó������ queue�ȿ��ٰ� vector<int>�� �־ �װ��� ���� �����߾��µ�, �޸� �ʰ��� ���Դ�. 
	//�׷����Ѱ� �������� ���� �ʴ� ���� ������� �浵 ��� ��θ� �����߾��� �����̾�����.
	//�׷��� map�� �̿��ؼ� �ٷ� ���� ��常 �����ϵ��� �ߴ�.

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

void bfs(queue<pair<int, int>>& route, int& count, map<int, int>& node, vector<bool>& visit, int K)
{
	while (!route.empty())
	{
		int cur = route.front().first;
		count = route.front().second;

		route.pop();

		if (cur == K)
			return;

		for (int nxt : {cur - 1, cur + 1, 2 * cur})
		{
			if (nxt < 0 || nxt > 100000 || visit[nxt])
				continue;

			route.push(make_pair(nxt, count + 1));
			visit[nxt] = true;
			node[nxt] = cur;
		}
	}
}

int main()
{
	int N, K;
	int count = 0;
	queue<pair<int, int>> route; //���� ��ġ, count, ���
	map<int, int> node;
	vector<bool> visit(100010, false);

	cin >> N >> K;

	route.push(make_pair(N, 0));

	bfs(route, count, node, visit, K);

	cout << count << endl;

	vector<int> temp(1, K);
	vector<int>::reverse_iterator iter;

	int tmp = K;
	while (tmp != N)
	{
		temp.push_back(node[tmp]);
		tmp = node[tmp];
	}

	for (iter = temp.rbegin(); iter != temp.rend(); iter++)
		cout << *iter << " ";

	return 0;
}