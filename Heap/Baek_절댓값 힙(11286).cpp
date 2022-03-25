//Baekjoon > 11286 > 절댓값 힙 
//https://www.acmicpc.net/problem/11286

	//multiset 가지고 환장의 콜라보로 풀었더니, 다른 사람들 보니까 priority queue로 해결....!
	//일단, multiset.erase(x)를 사용하면 x가 여러개여도 전부 지우기 때문에, 한 개만 지우기 위해선 iterator을 써야한다는 것을 유념.
	//아래에 priority queue 풀이 방법도 있으니 꼭 기억하기

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	multiset<int> p_nums; //양수를 보관
	multiset<int> m_nums; //음수를 보관
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