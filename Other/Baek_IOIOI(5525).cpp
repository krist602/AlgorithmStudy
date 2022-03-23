//Baekjoon > 5525 > IOIOI
//https://www.acmicpc.net/problem/5525

	//������ ���� ������ �����Ϸ��� �ϳ��ϳ� ���� ������ �Ǵ��ؼ� ��������Ѵ�.
	//���� ����Ž�� ����. �Ź� ���� ������ I���� O���� Ȯ���ؼ� ���������ߴ�.

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