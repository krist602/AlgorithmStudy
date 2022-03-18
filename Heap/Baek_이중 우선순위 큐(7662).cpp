//Baekjoon > 7662 > ���� �켱���� ť
//https://www.acmicpc.net/problem/7662

	//(*node.begin()).first�� (*node.rbegin()).first �� ����ϱ�
	//Ǯ�� ���� �˻��� �غ��� multiset�� ���� �� ���� �� ����.
	//multiset �������

#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0, k = 0;
	char C;
	int num = 0;
	map<int, int> node;


	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> C >> num;
			if (C == 'D')
			{
				if (node.empty())
					continue;
				if (num == 1)
				{
					if ((*node.rbegin()).second == 1)
						node.erase((*node.rbegin()).first);
					else
						(*node.rbegin()).second -= 1;
				}
				else if (num == -1)
				{
					if ((*node.begin()).second == 1)
						node.erase((*node.begin()).first);
					else
						(*node.begin()).second -= 1;
				}
			}
			else if (C == 'I')
			{
				node[num] += 1;
			}
		}
		if (node.empty())
			cout << "EMPTY" << "\n";
		else
			cout << (*node.rbegin()).first << " " << (*node.begin()).first << "\n";

		node.clear();
	}

	return 0;
}