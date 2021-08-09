//Programmers > ����/�ʺ� �켱 Ž��(DFS/BFS) > ��Ʈ��ũ
//https://programmers.co.kr/learn/courses/30/lessons/43162


    //���� ��Ʈ��ũ�� ����Ǿ��ִ� ��ǻ�͸� ��� �����Ѵ�.
    //DFS

#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int x)
{
    if (!computers[x][x]) //�̹� Ž���� ���̶�� False�̱� ������ return false;
        return false;
    computers[x][x] = 0; //Ž���� ��ǻ���� ���� Falseó��
    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[x][i]) //��λ��� ��� ��ǻ�͸� �湮�Ѵ�.
            dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] && dfs(computers, i))
            answer += 1;
    }

    return answer;
}