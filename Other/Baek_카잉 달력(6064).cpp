//Baekjoon > 6064 > ī�� �޷�
//https://www.acmicpc.net/problem/6064

	//������ �����ϴ°� ������� ����
	//������ ������ ��Ŭ���� ȣ������ �ּҰ���� ������ �˾Ƶδ°� ���� �� ����.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0;

	cin >> T;

	int M = 0, N = 0, x = 0, y = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;
		int temp = 0;
		int j = 0;
		bool right = false;
		if (y == N)
			y = 0;
		for (j = x; j <= M * N; j = j + M)
		{
			temp = j % N;
			if (temp == y)
			{
				right = true;
				cout << j << "\n";
				break;
			}
		}

		if (!right)
			cout << "-1" << "\n";

	}

	return 0;
}