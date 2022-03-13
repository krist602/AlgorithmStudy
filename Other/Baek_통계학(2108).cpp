//Baejoon > 2108 > �����
//https://www.acmicpc.net/problem/2108

	//����� ������ �ƴѵ� ��ҿ� �� �ʱ�ȭ ���ִٰ� ������ ������ �ʱ�ȭ ��������� �װ� ������ ��� Ʋ�Ⱦ���.
	//���п� map������ ������ �� �� �־���.
	//���� ��Ȯ�� ��ġ�� �ʿ��� ���װ��� ��� float�� ���� double�� ����� ��Ȱȭ����

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N, tmp, MAX = 0, sum = 0;
	double avg;
	bool flag = false;
	map<int, int> count;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		sum += tmp;
		count[tmp] += 1;
		MAX = max(MAX, count[tmp]);
	}

	//������
	avg = double(sum) / double(N);
	avg > 0 ? avg += 0.5 : avg -= 0.5;
	cout << int(avg) << endl; //
	//========

	//�߾Ӱ�
	tmp = N / 2;
	for (auto c : count)
	{
		if (tmp >= c.second)
			tmp -= c.second;
		else
		{
			cout << c.first << endl; //
			break;
		}
	}
	//========

	//�ֺ�
	for (auto c : count)
	{
		if (c.second == MAX)
		{
			tmp = c.first;
			if (flag)
				break;
			flag = true;
		}
	}
	//========

	cout << tmp << endl;

	cout << (*count.rbegin()).first - (*count.begin()).first << endl; //����

	return 0;
}