//Baekjoon > 1931 > 회의실 배정
//https://www.acmicpc.net/problem/1931

	//Greedy알고리즘
	//그 순간 순간에 최적의 해를 찾아야한다.
	//Greedy 너무 어려워

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> l, pair<int, int> r)
{
	if (l.second == r.second)
		return l.first < r.first;
	return l.second < r.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, tmp1, tmp2;
	vector<pair<int, int>> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp1 >> tmp2;
		nums.push_back(make_pair(tmp1, tmp2));
	}

	sort(nums.begin(), nums.end(), cmp);

	int time = nums[0].second;
	int count = 1;

	for (int i = 1; i < N; i++)
	{
		if (time <= nums[i].first)
		{
			count++;
			time = nums[i].second;
		}
	}

	cout << count << endl;

	return 0;
}