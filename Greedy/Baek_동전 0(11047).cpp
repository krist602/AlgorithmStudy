//Baekjoon > 11047 > 동전 0
//https://www.acmicpc.net/problem/11047

	//Greedy 알고리즘
	//가장 가치가 큰 동전부터 챙긴다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0, coin_nums = 0;
	vector<int> coin;
	cin >> N >> K;
	int money = K;

	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		cin >> tmp;
		coin.push_back(tmp);
	}

	vector<int>::reverse_iterator r_iter;
	for (r_iter = coin.rbegin(); r_iter != coin.rend(); r_iter++)
	{
		if (money >= *r_iter)
		{
			coin_nums += (money / *r_iter);
			money %= *r_iter;
		}
	}

	cout << coin_nums << "\n";

	return 0;
}