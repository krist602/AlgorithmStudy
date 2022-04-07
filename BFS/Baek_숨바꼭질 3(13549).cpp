//Baekjoon > 13549 > 숨바꼭질 3
//https://www.acmicpc.net/problem/13549

	//BFS 문제
	//순간이동을 하는 경우에는 시간 소모가 없다는 점만 기억하면 된다.
	//범위 검사 꼭 해줘야 함

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()

{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	cin >> N >> K;
	vector<int> DP(100100, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_node;

	pq_node.push(make_pair(0, N));

	while (!pq_node.empty())
	{
		int cur_time = pq_node.top().first;
		int cur_loc = pq_node.top().second;

		pq_node.pop();

		if (DP[cur_loc] == -1)
		{
			DP[cur_loc] = cur_time;

			if (cur_loc == K)
				break;

			if (cur_loc * 2 <= 100000 && DP[cur_loc * 2] == -1)
				pq_node.push(make_pair(cur_time, cur_loc * 2));

			for (auto next_node : { cur_loc + 1, cur_loc - 1 })
				if (next_node >= 0 && next_node <= 100000 && DP[next_node] == -1)
					pq_node.push(make_pair(cur_time + 1, next_node));
		}
	}

	cout << DP[K] << "\n";

	return 0;
}
