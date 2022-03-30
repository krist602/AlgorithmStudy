//Baekjoon > 11725 > Ʈ���� �θ� ã��
//https://www.acmicpc.net/problem/11725

	//graph ��ü�� �����ϸ� �޸� �ʰ��� ���´�.
	//����� ��常 �������־�� �޸� �ʰ��� ������ �ʴ´�.

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<int>& parent, int index, int N)
{
	for (int i = 0; i < tree[index].size(); i++)
	{
		if (!parent[tree[index][i]])
		{
			parent[tree[index][i]] = index + 1;
			dfs(tree, parent, tree[index][i], N);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<vector<int>> tree(N, vector<int>());
	vector<int> parent(N, 0);

	for (int i = 1; i < N; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tree[tmp1 - 1].push_back(tmp2 - 1); //tree[tmp1 - 1][tmp1 - 2] = 1 �� ����ϸ� �޸� �ʰ�
		tree[tmp2 - 1].push_back(tmp1 - 1);
	}

	dfs(tree, parent, 0, N);

	for (int i = 1; i < N; i++)
		cout << parent[i] << "\n";

	return 0;
}
