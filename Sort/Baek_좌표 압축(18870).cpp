//Baekjoon > 18870 > 좌표 압축
//https://www.acmicpc.net/problem/18870

	//map 혹은 vector로 풀면 되는 문제
	//다른 사람은 map으로 풀면서 map.first에는 기존 좌표 값을, map.second 의 값에는 압축 좌표값을 넣고, 인쇄했다.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_second(pair<int, int> l, pair<int, int> r)
{
	return l.second < r.second;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio();

	int N = 0, count = 0, tmp = 0;
	vector<pair<int, int>> nums;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		nums.push_back(make_pair(tmp, i));
	}

	sort(nums.begin(), nums.end());

	tmp = nums[0].first;

	for (int i = 0; i < nums.size(); i++)
	{
		if (tmp != nums[i].first)
		{
			tmp = nums[i].first;
			count++;
		}
		nums[i].first = count;
	}

	sort(nums.begin(), nums.end(), cmp_second);

	for (auto n : nums)
		cout << n.first << " ";

	return 0;
}