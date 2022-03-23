//Baekjoon > 5525 > IOIOI
//https://www.acmicpc.net/problem/5525

	//제한이 없는 조건을 충족하려면 하나하나 받을 때마다 판단해서 더해줘야한다.
	//거의 완전탐색 문제. 매번 들어올 때마다 I인지 O인지 확인해서 계산해줘야했다.

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0, size = 0, count = 0, rec = 0;
	char t, r = 'O';
	cin >> N >> M;
	size = 2 * N + 1;
	for (int i = 0; i < M; i++)
	{
		cin >> t;
		if (t == 'I')
		{
			if (r == 'I')
			{
				rec = 1;
			}
			else
			{
				rec++;
				if (rec >= size)
					count++;
			}
			r = t;
		}
		else
		{
			if (r == 'O')
				rec = 0;
			else
				rec++;

			r = t;
		}
	}

	cout << count << "\n";

	return 0;
}