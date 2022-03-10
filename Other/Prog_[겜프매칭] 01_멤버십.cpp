//Programmers > 2022 Dev-Matching: 게임 프로그래머 > 01_멤버십

	//완전탐색으로 해결.
	//구매한 날짜를 365일 형태로 변경하고, 그 날짜부터 30일까지 금액을 전부 더해줬다.
	//효율이 substr이 더 좋아서 했지만, 실제 프로그램을 만들 때는 안정성을 생각하면 find함수가 나을 것 같다.

#include <string>
#include <vector>

using namespace std;

int totaldays(int m, int d)
{
	int total = 0;
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < m - 1; i++)
		total += months[i];
	total += d;

	return total;
}

vector<int> solution(vector<string> purchase) {
	vector<int> answer(5, 0);
	int amount[400] = { 0 };
	int mm = 0;
	int dd = 0;
	int money = 0;
	for (int i = 0; i < purchase.size(); i++)
	{
		mm = stoi(purchase[i].substr(5, 2));
		dd = stoi(purchase[i].substr(8, 2));
		money = stoi(purchase[i].substr(11));
		int total = totaldays(mm, dd);
		for (int j = 0; j < 30; j++)
			amount[total + j] += money;
	}

	for (int i = 1; i < 366; i++)
	{
		if (amount[i] < 10000)
			answer[0] += 1;
		else if (amount[i] < 20000)
			answer[1] += 1;
		else if (amount[i] < 50000)
			answer[2] += 1;
		else if (amount[i] < 100000)
			answer[3] += 1;
		else
			answer[4] += 1;
	}

	return answer;
}