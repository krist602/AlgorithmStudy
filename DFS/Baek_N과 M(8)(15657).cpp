//Baekjoon > 15657 > N과 M (8)
//https://www.acmicpc.net/problem/15657

    //늘 풀던 바로 그 문제
    //특이사항 없음!

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int N, int M, vector<int>& arr, int index, int depth)
{
    if (M == depth)
    {

        for (auto a : arr)
            cout << a << " ";
        cout << "\n";

        return;
    }

    for (int i = index; i < N; i++)
    {
        arr.push_back(nums[i]);
        dfs(nums, N, M, arr, i, depth + 1);
        arr.pop_back();
    }

    return;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N = 0, M = 0;
    vector<int> nums;
    vector<int> arr;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());
    dfs(nums, N, M, arr, 0, 0);

    return 0;
}