//Baekjoon > 2263 > Ʈ���� ��ȸ
//https://www.acmicpc.net/problem/2263

	//���� Ʈ���� ���� ���� Ʈ���� �ƴϴ�. ���� ���� Ʈ���� �����ϰ� ������ Ǯ� ������ �߸��߾���.
	//postorder�� ������ ������ �� �κ��� root�̱� ������ �װ� �̿��ؼ� �հ� �ڷ� ������ �����Ѵ�.
	//postorder�� �հ� �ڸ� ã�� ����� inorder�� ���� ���� �̿��ؼ� �ܼ��ϰ� �����ָ� �ȴ�.

	// ����� ó������ vector preorder�� �����ؼ� push_back���� ����־�����, �׷��� �Ѵٸ� �޸� �ʰ��� ���´�.

#include <iostream>
#include <vector>

using namespace std;

void find_preorder(vector<int>& inorder, vector<int>& postorder, vector<int>& index, int iS, int iE, int pS, int pE)
{
	if (iS > iE || pS > pE)
		return;

	int root = postorder[pE];
	cout << root << " ";
	find_preorder(inorder, postorder, index, iS, index[root] - 1, pS, pS + (index[root] - iS) - 1);
	find_preorder(inorder, postorder, index, index[root] + 1, iE, pS + (index[root] - iS), pE - 1);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, root = 0;
	cin >> N;
	vector<int> inorder(N);
	vector<int> postorder(N);
	vector<int> index(N + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 0; i < N; i++)
		cin >> postorder[i];

	root = postorder[N - 1];

	find_preorder(inorder, postorder, index, 0, N - 1, 0, N - 1);

	return 0;
}

