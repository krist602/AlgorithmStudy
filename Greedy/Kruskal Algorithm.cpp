#include <algorithm>
#include <vector>

using namespace std;

int getParent(vector<int>& parent, int x) 
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int>& parent, int x, int y)
{
	x = getParent(parent, x);
	y = getParent(parent, y);
	x < y ? parent[y] = x : parent[x] = y;
}

bool findParent(vector<int>& parent, int x, int y) 
{
	x = getParent(parent, x);
	y = getParent(parent, y);
	return x == y;
}

int main() {
	vector<int> parent;
	vector<vector<int>> costs;

	sort(costs.begin(), costs.end());

	for (int i = 0; i < n; i++)
		parent.push_back(i);

	for (int i = 0; i < costs.size(); i++)
	{
		if (!findParent(parent, costs[i][0], costs[i][1]))
		{
			answer += costs[i][2];
			unionParent(parent, costs[i][0], costs[i][1]);
		}
	}

	return 0;
}