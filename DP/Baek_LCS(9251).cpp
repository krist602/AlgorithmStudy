//Baekjoon > 9251 > LCS(Longest Common Subsequence, ���� ���� �κ� ����)
//https://www.acmicpc.net/problem/9251

	//dfs�� Ǯ���µ� �޸��ʰ�, ���������� ������ �ִ��� �޸� ������ �ð��ʰ� ����.
	//DP���� �������� �����ؾ߰ڴ�.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str1 = "", str2 = "";
	int s1_size = 0, s2_size = 0;

	cin >> str1 >> str2;

	s1_size = str1.size();
	s2_size = str2.size();
	vector<vector<int>> DP(s1_size + 1, (vector<int>(s2_size + 1, 0)));

	for (int i = 1; i <= s1_size; i++)
	{
		for (int j = 1; j <= s2_size; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[s1_size][s2_size] << "\n";

	return 0;
}
