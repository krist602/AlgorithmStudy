//Baekjoon > 1427 > ��Ʈ�λ��̵�
//https://www.acmicpc.net/problem/1427

/*
	string�� �����ؼ� ����ϸ� �Ǵ� ������ ����
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(char l, char r)
{
	return l > r;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	string str = "";
	cin >> str;

	sort(str.begin(), str.end(), cmp);

	cout << str << "\n";

	return 0;
}