//Programmers > 깊이/너비 우선 탐색(DFS/BFS) > 타겟 넘버
//https://programmers.co.kr/learn/courses/30/lessons/43165

    //모든 경로를 탐색해야한다.
    //DFS

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int count, int sum)
{
    if (count == numbers.size()) //경로의 끝이면 target과 sum을 비교
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(numbers, target, count + 1, sum + numbers[count]); //현재 값을 더한 결과를 비교
    dfs(numbers, target, count + 1, sum - numbers[count]); //현재 값을 뺀 결과를 비교
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);

    return answer;
}