//Baekjoon > 11727 > 2��n Ÿ�ϸ� 2
//https://www.acmicpc.net/problem/11727

	//DP����
	//��ȭ�� ����°� �ʹ� ����� �밡�� ����... DP��°͵� ���޾����� ��ȭ�� �������� �ᱹ Internet Search ��

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