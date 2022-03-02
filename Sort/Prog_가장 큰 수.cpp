//Programmers > 정렬 > 가장 큰 수
//https://programmers.co.kr/learn/courses/30/lessons/42746

	//cmp만 잘 구상했으면 쉬웠을 문제

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string l, string r)
{
	return l + r > r + l;
}

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> s_numbers;

	for (auto n : numbers)
	{
		s_numbers.push_back(to_string(n));
	}
	sort(s_numbers.begin(), s_numbers.end(), cmp);

	for (auto s : s_numbers)
	{
		answer += s;
	}

	if (s_numbers.at(0) == "0")
		return "0";
	return answer;
}