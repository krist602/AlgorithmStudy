//Programmers > 월간 코드 챌린지 시즌3 > n ^ 2 배열 자르기
//https://programmers.co.kr/learn/courses/30/lessons/87390

    //처음엔 배열을 만들고 필요한 부분만 차례대로 answer에 넣어줬는데 시간 초과가 나왔다.
    //규칙을 찾으면 어렵지 않게 풀 수 있었던 문제.
    //다른 사람 풀이에 max를 쓰는게 더 좋아보여서 아래다가 적어둔다. max min 함수 존재 잊지 않기

#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        if ((i % n) <= (i / n))
        {
            answer.push_back((i / n) + 1);
            continue;
        }
        answer.push_back((i % n) + 1);
    }

    return answer;
}

//===================================================================================================================

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) 
        answer.push_back(max(i / n, i % n) + 1);

    return answer;
}