//Programmers > Ž���(Greedy) > ����Ʈ
//https://programmers.co.kr/learn/courses/30/lessons/42885


	//���� Ǯ���� ����� �Ʒ��� �ּ�ó�� �س���.
	//ȿ���� 0��.
	//�ϴ� �� �ڵ�� for���� 2���� �ʿ��ϴ�.
	//���� Ǭ ����� ������������ ������ ����, ����Ž���� �ߴ�.
	//ū ������� �־��شٸ� �翬�� �ִ����� ���� �����ִ� ���� �°� ��������, ȿ������ ��������.
	//���� ����� �߰��� ������ ù ����� �ٽ� Ȯ���ؾ��ؼ� �ݺ����� �������. 
	//
	//�ϴ� ���� �߸� ������ �κ���, ���ſ� ��� �߿� ������ ����� ������ ��� �߿� ���ſ� ����� ������� ������ ���´ٰ� ������ ���̴�.
	//�ݴ�� �����غ��� ���� ���ſ� ����� ���� ������ ����� �����ָ� �ȴ�. �ֳ��ϸ� ����Ʈ�� �ִ� �ο��� 2���̱� ����. 
	//���� 2�� ������ �����ٸ� ���� Ǭ �ڵ尡 �¾��� ��. 
	// 
	//��� ����� ����, ���� ���ſ� ����� ���� ������ ����� �����ش�. ���� Ž���� ���ʿ��� ���ÿ� �ϱ� ������ end������ begin������ ���.
	// 
	//����� �ڼ��� ������ �Ʒ��� �ּ�����.
	//



#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0, cnt = 0, end = 1, begin = 0; //cnt�� ������� ���� ����� ��, end�� ���� ���ſ� ����� ��ġ, begin�� ���� ������ ����� ��ġ
	sort(people.begin(), people.end()); //������������ �������ش�. (������ ���������� �ʿ�� ���� ������������ ���൵ �ȴ�. �Ʒ� �ڵ常 �ٲٸ�.)

	while (true)
	{
		cnt++; //���� ���ſ� ����� ������ �ƴ� ������ ���.
		if (limit - people[people.size() - end++] >= people[begin]) 
			//if���� �����ϸ鼭 end++�� �ø��� ������ ���� ���ſ� ����� �Ǹ���. 
			//limit���� �� ����� ���Ը� �� ���� ���� ������ ����� ������ �˻�
		{
			begin++; //���Դٸ�, ���� ���ſ� ����� ���� ������ ����� �Ǿ��� ������ begin�� �÷��ش�.
			cnt++; //����� ++
		}
		answer++; //��Ʈ �Ѱ��� ����� ������ ������ answer�� �÷��ش�.
		if (cnt >= people.size()) //��� ����� �Ǿ��ٸ� break
			break;
	}
	return answer;
}

/*
bool cmp(int a, int b)
{
	return a > b;
}

int solution(vector<int> people, int limit) {
	int answer = 0,ship = 0, cnt=people.size();
	sort(people.begin(), people.end(),cmp);

	vector<pair<int, int>> boat(people.size());

	for (int i = 0; i < people.size(); i)
	{
		if (boat[ship].first + people[i] <= limit && boat[ship].second < 2)
		{
			boat[ship].first += people[i];
			boat[ship].second++;
			cnt--;
			i++;
			if (cnt == 0)
				break;
			ship = 0;
		}
		else
			ship++;
	}

	for (int i = 0; i < boat.size(); i++)
		if (boat[i].second != 0)
			answer++;

	return answer;
}
*/
