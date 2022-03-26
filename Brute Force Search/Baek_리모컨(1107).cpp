//Baekjoon > 1107 > 리모컨
//https://www.acmicpc.net/problem/1107

	//완전탐색으로 풀어야한다.
	//더 깔끔하게 짤 수 있는데 지쳐서 포기한다.
	//완전탐색인줄 모르고 이 방법 저 방법 다 쓰다가 검색해보고 알았다. 완전탐색 싫어....

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