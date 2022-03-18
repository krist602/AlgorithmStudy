//Baekjoon > 1927 > �ּ� ��
//https://www.acmicpc.net/problem/1927

	//�ð� �ʰ� ��û ���Դµ�, ���ؿ��� cin.tie(NULL), sync_with_stdio, \n�� ����Ѵ�...
	//���п� priority_queue��� ���� �����.
	//����� ���� map�� �̿��ؼ� Ǯ����. map Ȱ�� �˰����� �Ʒ��� ���� ÷���Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	priority_queue<int, vector<int>, greater<int>> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp)
			nums.push(tmp);
		else
		{
			if (nums.empty())
				cout << "0\n";
			else
			{
				cout << nums.top() << "\n";
				nums.pop();
			}
		}
	}

	return 0;
}

//====================================================================================

#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	map<int, int> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			if (!nums.empty())
			{
				cout << (*nums.begin()).first << "\n";
				if ((*nums.begin()).second == 1)
					nums.erase((*nums.begin()).first);
				else
					(*nums.begin()).second--;
			}
			else
				cout << "0\n";
		else
			nums[tmp] += 1;
	}

	return 0;
}