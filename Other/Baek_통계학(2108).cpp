//Baejoon > 2108 > 통계학
//https://www.acmicpc.net/problem/2108

	//어려운 문제는 아닌데 평소엔 다 초기화 해주다가 오늘은 변수들 초기화 안해줬더니 그것 때문에 계속 틀렸었다.
	//덕분에 map가지고 열심히 뜯어볼 수 있었다.
	//또한 정확한 수치가 필요한 코테같은 경우 float형 말고 double형 사용을 생활화하자

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N, tmp, MAX = 0, sum = 0;
	double avg;
	bool flag = false;
	map<int, int> count;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		sum += tmp;
		count[tmp] += 1;
		MAX = max(MAX, count[tmp]);
	}

	//산술평균
	avg = double(sum) / double(N);
	avg > 0 ? avg += 0.5 : avg -= 0.5;
	cout << int(avg) << endl; //
	//========

	//중앙값
	tmp = N / 2;
	for (auto c : count)
	{
		if (tmp >= c.second)
			tmp -= c.second;
		else
		{
			cout << c.first << endl; //
			break;
		}
	}
	//========

	//최빈값
	for (auto c : count)
	{
		if (c.second == MAX)
		{
			tmp = c.first;
			if (flag)
				break;
			flag = true;
		}
	}
	//========

	cout << tmp << endl;

	cout << (*count.rbegin()).first - (*count.begin()).first << endl; //범위

	return 0;
}