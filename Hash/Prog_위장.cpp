//Programmers > 해시 > 위장
//https://programmers.co.kr/learn/courses/30/lessons/42578

	//iterator 사용법을 잊지 말자
	//풀이 식만 생각해내면 어렵지 않다.

#include <map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes)
{
	map<string, int> calc;
	int answer = 1;

	for (auto c : clothes)
	{
		calc[c[1]] += 1;
	}
	map<string, int> ::iterator iter;
	for (iter = calc.begin(); iter != calc.end(); iter++)
	{
		answer *= (iter->second + 1);
	}
	return answer -= 1;
}