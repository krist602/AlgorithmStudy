//Baekjoon > 9375 > �мǿ� ���غ�
//https://acmicpc.net/problem/9375

	//Programmers > ���� ������ ������ ����
	//������ �� Ǯ��ôµ� �� ����ϰ� �־���.

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