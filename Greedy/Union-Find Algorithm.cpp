#include <vector>

using namespace std;

int findParent(int parent[], int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent, parent[x]);
}

void union(int parent[],int x, int y)
{
	x = findParent(parent, x);
	y = findParent(parent, y);

	if (x == y) 
		return;
	x < y ? parent[y] = x : parent[x] = y;
}