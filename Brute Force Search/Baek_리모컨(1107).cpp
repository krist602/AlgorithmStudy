//Baekjoon > 1107 > ������
//https://www.acmicpc.net/problem/1107

	//����Ž������ Ǯ����Ѵ�.
	//�� ����ϰ� © �� �ִµ� ���ļ� �����Ѵ�.
	//����Ž������ �𸣰� �� ��� �� ��� �� ���ٰ� �˻��غ��� �˾Ҵ�. ����Ž�� �Ⱦ�....

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int digit(int x)
{
	int num = 1;
	while (x / 10 != 0)
	{
		x /= 10;
		num += 1;
	}
	return num;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string channel = "";
	cin >> channel;
	int i_c = stoi(channel);
	int M = 0, click = 0;
	set<int> button;
	cin >> M;
	for (int i = 0; i < 10; i++)
	{
		button.insert(i);
	}
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		button.erase(tmp);
	}

	click = (abs(i_c - 100));

	for (int i = 0; i < 1000000; i++)
	{
		string s_c = to_string(i);
		for (int j = 0; j < s_c.size(); j++)
		{
			if (button.find(s_c[j] - 48) == button.end())
				break;

			if (j == s_c.size() - 1)
				click = min(click, abs(i_c - i) + digit(i));
		}
	}
	cout << click << "\n";

	return 0;
}