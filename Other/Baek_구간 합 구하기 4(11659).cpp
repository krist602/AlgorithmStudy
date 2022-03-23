//Baekjoon > 11659 > 구간 합 구하기 4
//https://www.acmicpc.net/problem/11659

	//처음에는 매번 sum값을 구하도록 했는데 시간초과가 나왔다.
	//아예 전부 미리 다 더해놓도록 구현.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	vector<long long> nums(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		nums[i] = nums[i - 1] + tmp;
	}

	for (int i = 0; i < M; i++)
	{
		int start, end, sum = 0;
		cin >> start >> end;
		cout << nums[end] - nums[start - 1] << "\n";
	}

	return 0;
}