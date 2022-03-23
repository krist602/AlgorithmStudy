//Baekjoon > 11727 > 2×n 타일링 2
//https://www.acmicpc.net/problem/11727

	//DP문제
	//점화식 세우는거 너무 어려워 대가리 터져... DP라는것도 깨달았지만 점화식 못세워서 결국 Internet Search ㅠ

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int>square(n + 1, 0);
	square[1] = 1;
	square[2] = 3;
	for (int i = 3; i <= n; i++)
		square[i] = (square[i - 1] + square[i - 2] * 2) % 10007;
	cout << square[n] << "\n";

	return 0;
}