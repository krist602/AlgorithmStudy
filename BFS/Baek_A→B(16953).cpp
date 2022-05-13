//Baekjoon > 16953 > A �� B
//https://www.acmicpc.net/problem/16953

    //bfs ����
    //A�� B�� 10�� 9��(10��)����������, 
    //10�踦 ���� �� int���� �ڷ����� �Ѿ�� ������ int�� ���� �ȵǴ� ����

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int A, int B)
{
    priority_queue<pair<long long, long long>> convert;
    convert.push(make_pair(A, 1));

    while (!convert.empty())
    {
        if (convert.top().first > B)
        {
            convert.pop();
        }
        else if (convert.top().first == B)
        {
            cout << convert.top().second;
            return;
        }
        else
        {
            long long cur_A = convert.top().first;
            long long cur_count = convert.top().second;

            convert.pop();

            convert.push(make_pair(cur_A * 2, cur_count + 1));
            convert.push(make_pair(cur_A * 10 + 1, cur_count + 1));
        }
    }

    cout << "-1" << "\n";
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A = 0, B = 0;
    cin >> A >> B;

    bfs(A, B);

    return 0;
}