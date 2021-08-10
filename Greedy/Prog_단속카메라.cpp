//Programmers > Ž���(Greedy) > �ܼ�ī�޶�
//https://programmers.co.kr/learn/courses/30/lessons/42884

	//begin�� end�� ���ؼ� ��ġ�� ��ġ�� ī�޶� �߰��Ѵٰ� �����ߴ�.
	//���� ���� ����������, ���� �ÿ��� ���� ���������� ������ ���ָ�, �񱳰� ��������.
	//

#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] == b[0])
		return a[1] < b[1];
	return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
	int answer = 0, begin, end, index = 0;
	sort(routes.begin(), routes.end(), cmp); //���� ������ �� ���� ����, ���� ���� ���� ������ �� ���� ���� ������ ������.

	for (int i = 0; i < routes.size(); i)
	{
		begin = routes[i][0]; //���� ���� ���ڶ�� �����ϸ� �ȴ�.
		end = routes[i][1]; //�� ������ ���� �����̴�.
		answer++; //ī�޶�++
		for (int j = i + 1; j < routes.size(); j++) //���� �������� ���ϵ��� j=i+1�� �־��ش�.
		{
			begin < routes[j][0] ? begin = routes[j][0] : begin; //���� begin�� ���� �������� ���� ������ ���ؼ� �� ū ���� ����.
			end < routes[j][1] ? end : end = routes[j][1]; //���� end�� ���� �������� ���� ������ ���ؼ� �� ���� ���� ����.
			if (begin > end) //���� begin�� end�� �Ȱ�ģ�ٸ� break;
				break;
			index = j; //begin�� end ���̿� ��ġ�� �κ��� �ִٸ� index�� �÷��ش�.
		}
		i = ++index; //�Ϸ��� �˻��� ������ �� ���� Ž���� index���� 1�� �� ���� ������ �����ؾ��Ѵ�.
					 //ó�� ������ i=index+1 �� ���༭ �߻��ߴµ�, �� ������ index=j��� ¥���ִ� ���� ���� ���Ѵٸ� ��� ���� ���� �ݺ��ϱ� ����.
	}

	return answer;
}