//Programmers > Ž���(Greedy) > �� �����ϱ�
//https://programmers.co.kr/learn/courses/30/lessons/42861


	/*
		�ּ� ��� ���� Ʈ�� ����.
		ũ�罺Į �˰��� Ȥ�� ���� �˰����� �̿��Ͽ� Ǯ�� �ȴٰ� �Ѵ�.
		�Ʒ� �˰����� ũ�罺Į �˰����� �̿��ߴ�.
		������ Ǯ�� ��...������
		�������� �ſ� ��մ� �˰����� �ô�. 
	*/

#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) //costs[2]���� �� ������ �����ϴµ� �ʿ��� 
{
	return a[2] < b[2];
}

int getParent(vector<int>& island, int x) //island[x]���� [x]�� �θ��带 �����صξ���. ���󰡸鼭 �θ� ���������� ����.
{
	if (island[x] == x) return x;
	return island[x] = getParent(island, island[x]);
}

void unionParent(vector<int>& island, int x, int y) //x�� y�� �θ��带 �� �� �� ���� ������ ����
{
	x = getParent(island, x);
	y = getParent(island, y);
	x < y ? island[y] = x : island[x] = y;
}

bool findParent(vector<int>& island, int x, int y) //���� ���� �׷����� ����ִ��� Ȯ��
{
	x = getParent(island, x);
	y = getParent(island, y);
	return x == y;
}

int solution(int n, vector<vector<int>> costs) { 
	int answer = 0, cnt = 0;
	vector<int> island;

	sort(costs.begin(), costs.end(), cmp); //costs[2] ������ �������� ����.

	for (int i = 0; i < n; i++) //���� �ʱ⿡�� ���� �θ��带 �ڽ����� ����
		island.push_back(i);

	for (int i = 0; i < costs.size(); i++)
	{
		if (!findParent(island, costs[i][0], costs[i][1])) //���� ���� �׷����� ����Ǿ����� �ʴٸ�
		{
			answer += costs[i][2]; //���� ���� ���� ������ �����ְ�
			unionParent(island, costs[i][0], costs[i][1]); //���� �θ��带 �����ش�.
		}
	}

	return answer;
}