//Baekjoon > 11404 > 플로이드
//https://www.acmicpc.net/problem/11404

	//플로이드라고 써있는데도 문제 푸는데 약간의 시간이 걸린 이유
	//	1. bus[i][j] == 0 이라면 0이 더 작기 때문에 0의 값을 바꾸지 않았다.
	//	2. 출발지와 도착지가 같은 버스는 없다고 했으니 그 곳엔 따로 0을 입력
	//	3. 시작 도시와 도착 도시를 연결하는 노선이 하나가 아닐 수 있다.
	//	4. 그냥 주석달린 모든 조건문은 하나씩 다 추가했다고 보면 된다.

#include <iostream>
#include <vector>

using namespace std;

void floyd(vector<vector<int>>& bus, int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (bus[i][k] && bus[k][j]) //하나의 값이라도 없으면 안된다.
				{
					if (bus[i][j] > bus[i][k] + bus[k][j])
						bus[i][j] = bus[i][k] + bus[k][j];
					else if (!bus[i][j]) //bus[i][j] == 0 이라면 무조건 값을 받아준다.
						bus[i][j] = bus[i][k] + bus[k][j];
				}
			}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> bus(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		int s, e, p;
		cin >> s >> e >> p;
		if (!bus[s][e]) //값이 0이라면 무조건 받아준다.
			bus[s][e] = p;
		else //이미 버스가 있는 경우라면 더 작은 값을 입력해준다.
			bus[s][e] > p ? bus[s][e] = p : bus[s][e];
	}

	floyd(bus, n);

	for (int i = 1; i <= n; i++)
		bus[i][i] = 0; //출발 도시와 도착 도시가 같은 경우 0으로 초기화해준다.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << bus[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
