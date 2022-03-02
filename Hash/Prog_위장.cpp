//Programmers > �ؽ� > ����
//https://programmers.co.kr/learn/courses/30/lessons/42578

	//iterator ������ ���� ����
	//Ǯ�� �ĸ� �����س��� ����� �ʴ�.

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