//Programmers > 2021 Dev-Matching: �� �鿣�� ������(��ݱ�) > �ٴܰ� ĩ�� �Ǹ�
//https://programmers.co.kr/learn/courses/30/lessons/77486

	//dfs�� �̿��� �ذ��ߴ�.
	//���������� �ּҰ��� �̿��ϱ� �Ⱦ�����, �ؾ��ߴ� ����.
	//���״� �ǿ� �ڵ��� �ٸ��ٴ� ���� �ٽ� �ѹ� ����ϰ� ���� ��������.
	//����, �ö󰡴� ���� 0���̶�� �� �̻� ȣ���� �ʿ䰡 ���ٴ� ���� �����ؾ� �Ѵ�.

#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> idx;
unordered_map<string, string> person;

void dfs(vector<string>& enroll, vector<string>& referral, string seller, int amount, vector<int>& answer)
{
	int tenp_money = amount / 10;
	answer[idx[seller]] += (amount - tenp_money);

	if (tenp_money != 0 && person[seller] != "-")
		dfs(enroll, referral, person[seller], tenp_money, answer);
	return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer(enroll.size(), 0);

	for (int i = 0; i < enroll.size(); i++)
	{
		idx[enroll[i]] = i; //�ε�����. seller�� �̸��� ������ �� �� ���������� �ٷ� ã�� �� �ִ�.
		person[enroll[i]] = referral[i]; //referral�� �̸��� enroll�� �̸��� �������.
	}

	for (int i = 0; i < seller.size(); i++)
		dfs(enroll, referral, seller[i], amount[i] * 100, answer);

	return answer;
}