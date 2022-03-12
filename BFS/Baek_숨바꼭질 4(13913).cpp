//Baekjoon > 13913 > 숨바꼭질 4
//https://www.acmicpc.net/problem/13913

	//지나온 경로를 저장해야 되었던 문제
	//처음에는 queue안에다가 vector<int>를 넣어서 그곳에 전부 보관했었는데, 메모리 초과가 나왔다. 
	//그럴만한게 정답으로 오지 않던 전혀 상관없는 길도 모두 경로를 저장했었기 때문이었을듯.
	//그래서 map을 이용해서 바로 이전 노드만 저장하도록 했다.

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
	queue<pair<int, int>> route; //현재 위치, count, 경로
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