//Baekjoon > 11286 > ���� �� 
//https://www.acmicpc.net/problem/11286

	//multiset ������ ȯ���� �ݶ󺸷� Ǯ������, �ٸ� ����� ���ϱ� priority queue�� �ذ�....!
	//�ϴ�, multiset.erase(x)�� ����ϸ� x�� ���������� ���� ����� ������, �� ���� ����� ���ؼ� iterator�� ����Ѵٴ� ���� ����.
	//�Ʒ��� priority queue Ǯ�� ����� ������ �� ����ϱ�

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	multiset<int> p_nums; //����� ����
	multiset<int> m_nums; //������ ����
	multiset<int>::iterator it;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp > 0)
			p_nums.insert(tmp);
		else if (tmp < 0)
			m_nums.insert(tmp);
		else
		{
			if (p_nums.empty())
				if (m_nums.empty())
					cout << "0\n";
				else
				{
					cout << *m_nums.rbegin() << "\n";
					it = m_nums.find(*m_nums.rbegin());
					m_nums.erase(it);
				}
			else if (m_nums.empty())
			{
				cout << *p_nums.begin() << "\n";
				it = p_nums.find(*p_nums.begin());
				p_nums.erase(it);
			}
			else
				if (*p_nums.begin() + *m_nums.rbegin() >= 0)
				{
					cout << *m_nums.rbegin() << "\n";
					it = m_nums.find(*m_nums.rbegin());
					m_nums.erase(it);
				}
				else
				{
					cout << *p_nums.begin() << "\n";
					it = p_nums.find(*p_nums.begin());
					p_nums.erase(it);
				}
		}
	}

	return 0;
}

//============================================================================================

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nums;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp)
			nums.push(make_pair(abs(tmp), tmp));
		else
		{
			if (nums.empty())
				cout << "0\n";
			else
			{
				cout << nums.top().second << "\n";
				nums.pop();
			}
		}
	}

	return 0;
}