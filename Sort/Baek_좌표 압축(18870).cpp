//Baekjoon > 18870 > ��ǥ ����
//https://www.acmicpc.net/problem/18870

	//map Ȥ�� vector�� Ǯ�� �Ǵ� ����
	//�ٸ� ����� map���� Ǯ�鼭 map.first���� ���� ��ǥ ����, map.second �� ������ ���� ��ǥ���� �ְ�, �μ��ߴ�.

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