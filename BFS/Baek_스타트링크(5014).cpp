//Baekjoon > 5014 > ��ŸƮ��ũ
//https://www.acmicpc.net/problem/5014

	//Ư�̻��� ����

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int F, S, G, U, D;
	int cur_floor, count = 0;
	queue<pair<int, int>> floor;

	cin >> F >> S >> G >> U >> D;
	vector<bool> visit(F + 1, false);

	floor.emplace(S, 0);
	visit[S] = true;

	while (!floor.empty())
	{
		cur_floor = floor.front().first;
		count = floor.front().second;

		floor.pop();

		if (cur_floor == G)
			break;

		for (int nxt : {cur_floor + U, cur_floor - D})
		{
			if (nxt > F || nxt < 1)
				continue;
			if (!visit[nxt])
			{
				floor.emplace(nxt, count + 1);
				visit[nxt] = true;
			}
		}
	}

	if (visit[G])
		cout << count << endl;
	else
		cout << "use the stairs" << endl;

	return 0;
}