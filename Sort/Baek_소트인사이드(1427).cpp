//Baekjoon > 1427 > 소트인사이드
//https://www.acmicpc.net/problem/1427

/*
	string을 정렬해서 출력하면 되는 간단한 문제
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