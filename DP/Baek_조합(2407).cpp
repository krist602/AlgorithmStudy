//Baekjoon > 2407 > 조합
//https://www.acmicpc.net/problem/2407

	//나 혼자 풀라고 했으면 절대 못풀었을 거야..
	//string을 이용한 덧셈방법은 재밌다.
	//아직도 주소값을 이용한 계산은 공부해야될게 더 많을 것 같다.

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

	string& result = combination[n][r]; //result = combination[n][r]과 묶였다.

	if (result != "")
		return result;

	result = BigNumAdd(find_Combination(n - 1, r - 1), find_Combination(n - 1, r)); //이 곳에서 나오는 값을 coombination[n][r]에도 담아두고, 후에 호출할 때 값이 있으면 바로 불러온다.
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