//Baekjoon > 2667 > 단지번호붙이기
//https://www.acmicpc.net/problem/2667

	//BFS 응용 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { 1, 0, -1, 0 };

int find(vector<string>& apartment, vector<vector<bool>>& IsVisited, vector<int>& nums)
{
	int answer = 0;

	for (int i = 0; i < apartment.size(); i++)
		for (int j = 0; j < apartment[i].size(); j++)
			if (!IsVisited[i][j] && apartment[i][j] == '1')
			{
				answer++;
				int count = 1;
				queue<pair<int, int>> mix;
				IsVisited[i][j] = true;
				mix.push(make_pair(i, j));

				while (!mix.empty())
				{
					int row = mix.front().first;
					int col = mix.front().second;
					mix.pop();

					for (int m = 0; m < 4; m++)
					{
						int next_row = row + dir_r[m];
						int next_col = col + dir_c[m];

						if (next_row < 0 || next_row >= apartment.size() || next_col < 0 || next_col >= apartment.size())
							continue;

						if (apartment[next_row][next_col] == '1' && !IsVisited[next_row][next_col])
						{
							mix.push(make_pair(next_row, next_col));
							IsVisited[next_row][next_col] = true;
							count++;
						}
					}
				}

				nums.push_back(count);
			}

	return answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<string> apartment(N, "");
	vector<vector<bool>> IsVisited(N, vector<bool>(N, false));
	vector<int> nums;

	for (int i = 0; i < N; i++)
		cin >> apartment[i];

	cout << find(apartment, IsVisited, nums) << "\n";
	sort(nums.begin(), nums.end());
	for (auto n : nums)
		cout << n << "\n";

	return 0;
}