//Programmers > 2022 Dev-Matching: ���� ���α׷��� > 01_�����

	//����Ž������ �ذ�.
	//������ ��¥�� 365�� ���·� �����ϰ�, �� ��¥���� 30�ϱ��� �ݾ��� ���� �������.
	//ȿ���� substr�� �� ���Ƽ� ������, ���� ���α׷��� ���� ���� �������� �����ϸ� find�Լ��� ���� �� ����.

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