//Baekjoon > 11444 > �Ǻ���ġ �� 6
//https://www.acmicpc.net/problem/11444

	//�̰� ���� Ǯ�� �� ����;
	//https://blogshine.tistory.com/274 Ǯ�� ����

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(matrix& a, matrix& b)
{
	matrix temp(2, vector<long long>(2));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000000007;
		}
	}
	return temp;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	long long n = 0;
	cin >> n;

	matrix ans = { {1,0}, {0,1} };
	matrix a = { {1,1}, {1,0} };

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1] << "\n";

	return 0;
}