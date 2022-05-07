//Baekjoon > 2161 > 카드1
//https://www.acmicpc.net/problem/2161

	//queue를 쓰면 간단한 문제

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N = 0;
	cin >> N;
	queue<int> card;

	for (int i = 1; i <= N; i++)
		card.push(i);

	while (!card.empty())
	{
		cout << card.front() << " ";
		card.pop();

		if (card.empty())
			break;
		card.push(card.front());
		card.pop();
	}

	return 0;
}