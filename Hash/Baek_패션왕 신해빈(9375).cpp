//Baekjoon > 9375 > 패션왕 신해빈
//https://acmicpc.net/problem/9375

	//Programmers > 위장 문제와 동일한 문제
	//복습할 겸 풀어봤는데 잘 기억하고 있었다.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int j = 0; j < T; j++)
	{
		int n, count = 1;
		map<string, int> cloths;
		string tmp = "";

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> tmp >> tmp;
			cloths[tmp] += 1;
		}

		for (auto C : cloths)
			count *= C.second + 1;

		cout << count - 1 << "\n";
	}
	return 0;
}