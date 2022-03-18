//Baekjoon > 1927 > 최소 힙
//https://www.acmicpc.net/problem/1927

	//시간 초과 엄청 나왔는데, 백준에선 cin.tie(NULL), sync_with_stdio, \n을 써야한다...
	//덕분에 priority_queue라는 것을 배웠다.
	//참고로 나는 map을 이용해서 풀었다. map 활용 알고리즘은 아래에 따로 첨부한다.

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