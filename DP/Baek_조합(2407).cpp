//Baekjoon > 2407 > ����
//https://www.acmicpc.net/problem/2407

	//�� ȥ�� Ǯ��� ������ ���� ��Ǯ���� �ž�..
	//string�� �̿��� ��������� ��մ�.
	//������ �ּҰ��� �̿��� ����� �����ؾߵɰ� �� ���� �� ����.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string combination[101][101];

string BigNumAdd(string left, string right)
{
	int sum = 0;
	string result = "";

	while (!left.empty() || !right.empty() || sum)
	{
		if (!left.empty())
		{
			sum += left.back() - '0';
			left.pop_back();
		}
		if (!right.empty())
		{
			sum += right.back() - '0';
			right.pop_back();
		}
		result += (sum % 10) + '0';
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

string find_Combination(int n, int r)
{
	if (n == r || r == 0)
		return "1";

	string& result = combination[n][r]; //result = combination[n][r]�� ������.

	if (result != "")
		return result;

	result = BigNumAdd(find_Combination(n - 1, r - 1), find_Combination(n - 1, r)); //�� ������ ������ ���� coombination[n][r]���� ��Ƶΰ�, �Ŀ� ȣ���� �� ���� ������ �ٷ� �ҷ��´�.
	return result;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int n = 0, m = 0;
	cin >> n >> m;

	cout << find_Combination(n, m) << "\n";

	return 0;
}