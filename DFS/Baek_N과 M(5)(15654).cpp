//Baekjoon > 15654 > N�� M(5)
//https://www.acmicpc.net/problem/15654

	//������ ����ִ� ���� �����.
	//�̹� �� ���ڰ� �ִ��� Ȯ��������Ѵ�.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, vector<int>& combination, set<int>& index, int step, int N, int M)
{
	if (step == M)
	{
		for (auto c : combination)
			cout << c << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (index.find(i) != index.end())
			continue;
		combination.push_back(nums[i]);
		index.insert(i);
		dfs(nums, combination, index, step + 1, N, M);
		index.erase(i);
		combination.pop_back();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;
	vector<int> nums(N);
	vector<int> combination;
	set<int> index;

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	dfs(nums, combination, index, 0, N, M);

	return 0;
}
