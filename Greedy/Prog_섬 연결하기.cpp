//Programmers > 탐욕법(Greedy) > 섬 연결하기
//https://programmers.co.kr/learn/courses/30/lessons/42861


	/*
		최소 비용 신장 트리 문제.
		크루스칼 알고리즘 혹은 프림 알고리즘을 이용하여 풀면 된다고 한다.
		아래 알고리즘은 크루스칼 알고리즘을 이용했다.
		스스로 풀진 못...했지만
		오랜만에 매우 재밌는 알고리즘을 봤다. 
	*/

#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) //costs[2]에는 각 섬들을 연결하는데 필요한 
{
	return a[2] < b[2];
}

int getParent(vector<int>& island, int x) //island[x]에는 [x]의 부모노드를 저장해두었다. 따라가면서 부모를 가져오도록 설정.
{
	if (island[x] == x) return x;
	return island[x] = getParent(island, island[x]);
}

void unionParent(vector<int>& island, int x, int y) //x와 y의 부모노드를 둘 중 더 앞의 섬으로 통합
{
	x = getParent(island, x);
	y = getParent(island, y);
	x < y ? island[y] = x : island[x] = y;
}

bool findParent(vector<int>& island, int x, int y) //둘이 같은 그래프에 들어있는지 확인
{
	x = getParent(island, x);
	y = getParent(island, y);
	return x == y;
}

int solution(int n, vector<vector<int>> costs) { 
	int answer = 0, cnt = 0;
	vector<int> island;

	sort(costs.begin(), costs.end(), cmp); //costs[2] 순으로 오름차순 정렬.

	for (int i = 0; i < n; i++) //가장 초기에는 각자 부모노드를 자신으로 설정
		island.push_back(i);

	for (int i = 0; i < costs.size(); i++)
	{
		if (!findParent(island, costs[i][0], costs[i][1])) //서로 같은 그래프에 연결되어있지 않다면
		{
			answer += costs[i][2]; //값이 가장 작은 간선을 더해주고
			unionParent(island, costs[i][0], costs[i][1]); //둘의 부모노드를 합쳐준다.
		}
	}

	return answer;
}