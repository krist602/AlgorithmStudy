//Programmers > Ž���(Greedy) > ���̽�ƽ
//https://programmers.co.kr/learn/courses/30/lessons/42860

	//������ ���� !
	//�׸���� �ذ��� �� ���� ���� !
	//�ּڰ��� ã����鼭 �ݷʰ� ���������� ����ߴ�.
	//�ݷ� : "ABBAAB"

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0, cur_loc = 0;
	string temp(name.length(), 'A');

	while (true) //���ڿ��� ������ ������ �ݺ�
	{
		name[cur_loc] - 'A' > 'Z' - name[cur_loc] + 1 ? answer += 'Z' - name[cur_loc] + 1 : answer += name[cur_loc] - 'A'; //�� ��ġ���� ��������ϴ� Ƚ���� ���ؼ� answer�� �����ش�.
		temp[cur_loc] = name[cur_loc]; //�ٲ�ٴ� �������� ���� �ٲ۴�.

		if (temp == name) //���ڿ��� ������ Ż��
			break;

		for (int move = 1; move < name.length(); move++)
		{
			if (name[(cur_loc + move) % name.length()] != temp[(cur_loc + move) % name.length()]) //1ĭ �̵��� ��ġ�� ���ڰ� �ٸ��ٸ� �̵��Ѵ�.
			{
				answer += move; //�̵��� ��ŭ �����ش�
				cur_loc = (cur_loc + move) % name.length(); //���� ��ġ ��ȯ
				break;
			}
			else if (name[(name.length() + cur_loc - move) % name.length()] != temp[(name.length() + cur_loc - move) % name.length()]) //�̰� �����ϴ��� ��Ӹ�. ��ü���� i�� �����ְ� �̵��� ��ŭ �� ���� ���̷� ������ �� �������� �� ��ġ�� �ȴ�.
			{
				answer += move; //�̵��� ��ŭ �����ش�
				cur_loc = (name.length() + cur_loc - move) % name.length(); //���� ��ġ ��ȯ
				break;
			}
		}
	}

	return answer;
}
