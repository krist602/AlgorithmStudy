//Programmers > 해시 > 전화번호 목록
//https://programmers.co.kr/learn/courses/30/lessons/42577

	//sort를 하면 비슷한 숫자끼리 모인다는 것을 이용하면 쉽게 풀 수 있다.
	//다른 방법으로 몫연산을 이용해보고 싶었지만 너무 길어질 것 같아 포기.

#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());


	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		for (int l = 0; l < phone_book[i].size(); l++)
		{
			if (phone_book[i][l] != phone_book[i + 1][l])
				break;

			if (l == phone_book[i].size() - 1)
				return false;
		}
	}
	return true;
}