//Programmers > �̺�Ž�� > ¡�˴ٸ�
//https://programmers.co.kr/learn/courses/30/lessons/43236

	//�Ÿ��� �ϳ��� ���� ����, �� �Ÿ��� ������ �����־�� ������� ���غ���.

#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0, min = 1, max = distance, mid; //���� ������ �Ÿ��� �ּ��� ���� 1, �ִ��� ���� distance-1�̴�. (������ 1���� ���) ������ BinarySearch�� �̿��� ���̱⿡ �׳� distance�� �־���.

	sort(rocks.begin(), rocks.end()); //���� ������ �Ÿ��� ���� ���� ���������.

	while (min <= max) //min���� max���� ���� ���� �ݺ��ϵ��� �ݺ��� ����.
	{
		int count = 0, cur_loc = 0; //count�� ������ ������ ��, cur_loc�� ���� ��ġ�̴�.
		mid = (min + max) / 2; //mid���� min�� max�� �߰����� �־��ش�.

		for (int i = 0; i < rocks.size(); i++) //�� �������� Ž���� �ݺ��Ѵ�.
			if (rocks[i] - cur_loc < mid) //���� ��ġ�� ���� ���������� �Ÿ��� mid���� ���� ��� ������ �����Ѵ�.
				count++;
			else //���� ��ġ�� ���� ���������� �Ÿ��� mid���� ū ��� ���� ��ġ�� ���� ������ �����Ѵ�.
				cur_loc = rocks[i];

		if (count <= n) //������ ���� ���� n���� ���ٸ�
		{
			if (answer < mid) //answer�� mid���� ���ϰ� mid���� �� ũ�ٸ� answer�� mid���� �־��ش�.
				answer = mid;
			min = mid + 1; //�� ū ��찡 �ִ��� Ž���ϱ� ���� min���� mid���� �ڷ� ������.
		}
		else //������ ���� ���� n���� ���ٸ� �Ÿ��� �ʹ� �� ���̱� ������
			max = mid - 1; //max���� mid���� ������ ������.
	}

	return answer;
}