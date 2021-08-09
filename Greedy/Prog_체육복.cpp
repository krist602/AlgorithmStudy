//Programmers > Ž���(Greedy) > ü����
//https://programmers.co.kr/learn/courses/30/lessons/42862

	//��ü Ž���ϱ� �Ⱦ�����...

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	int student[35] = { 0 };

	for (auto i : lost) //�Ҿ���� �л��� -=1��
		student[i] -= 1;
	for (auto i : reserve) //������ �ִ� �л��� +=1�� ���ָ� ������ �ִµ� �������� �л��� 0���� ǥ��
		student[i] += 1;

	for (int i = 0; i <= n; i++)
		if (student[i] * student[i + 1] == -1) //�յڷ� 1�� -1�� �ִٸ� ������ �ÿ� -1�� ���´�.
		{
			student[i] = 0; //�� �л� ���� �ʱ�ȭ
			student[i + 1] = 0;
		}

	for (int i = 0; i <= n; i++)
		if (student[i] == -1) //��ü �л����� �Ҿ���� �л���ŭ ���ش�.
			answer--;

	return answer;
}