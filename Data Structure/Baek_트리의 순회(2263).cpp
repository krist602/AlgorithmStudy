//Baekjoon > 2263 > 트리의 순회
//https://www.acmicpc.net/problem/2263

	//이진 트리는 완전 이진 트리가 아니다. 완전 이진 트리만 생각하고 문제를 풀어서 접근을 잘못했었다.
	//postorder의 끝에는 무조건 그 부분의 root이기 때문에 그걸 이용해서 앞과 뒤로 나눠서 접근한다.
	//postorder의 앞과 뒤를 찾는 방법은 inorder의 원소 수를 이용해서 단순하게 더해주면 된다.

	// 참고로 처음에는 vector preorder를 선언해서 push_back으로 담아주었지만, 그렇게 한다면 메모리 초과가 나온다.

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

