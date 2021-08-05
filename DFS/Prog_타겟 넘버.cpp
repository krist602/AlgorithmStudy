//Programmers > ����/�ʺ� �켱 Ž��(DFS/BFS) > Ÿ�� �ѹ�
//https://programmers.co.kr/learn/courses/30/lessons/43165

    //��� ��θ� Ž���ؾ��Ѵ�.
    //DFS

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int count, int sum)
{
    if (count == numbers.size()) //����� ���̸� target�� sum�� ��
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(numbers, target, count + 1, sum + numbers[count]); //���� ���� ���� ����� ��
    dfs(numbers, target, count + 1, sum - numbers[count]); //���� ���� �� ����� ��
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);

    return answer;
}