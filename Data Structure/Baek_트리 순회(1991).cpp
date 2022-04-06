//Baekjoon > 1991 > 트리 순회
//https://www.acmicpc.net/problem/1991

	//map을 이용해서 만들었다. map에 부모노드와 자식 노드를 모두 저장시켰다.

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

void preorder(map<char, pair<char, char>>& tree, char index)
{
	cout << index;
	if (tree[index].first != '.')
		preorder(tree, tree[index].first);
	if (tree[index].second != '.')
		preorder(tree, tree[index].second);
	return;
}

void inorder(map<char, pair<char, char>>& tree, char index)
{
	if (tree[index].first != '.')
		inorder(tree, tree[index].first);
	cout << index;
	if (tree[index].second != '.')
		inorder(tree, tree[index].second);
	return;
}

void postorder(map<char, pair<char, char>>& tree, char index)
{

	if (tree[index].first != '.')
		postorder(tree, tree[index].first);
	if (tree[index].second != '.')
		postorder(tree, tree[index].second);
	cout << index;
	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	char center, left, right;
	map<char, pair<char, char>> tree;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> center >> left >> right;
		tree.insert(make_pair(center, make_pair(left, right)));
	}

	preorder(tree, 'A');
	cout << "\n";
	inorder(tree, 'A');
	cout << "\n";
	postorder(tree, 'A');
	cout << "\n";

	return 0;
}
