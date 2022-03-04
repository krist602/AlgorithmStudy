//Programmers > ���� �ڵ� ç���� ����3 > n ^ 2 �迭 �ڸ���
//https://programmers.co.kr/learn/courses/30/lessons/87390

    //ó���� �迭�� ����� �ʿ��� �κи� ���ʴ�� answer�� �־���µ� �ð� �ʰ��� ���Դ�.
    //��Ģ�� ã���� ����� �ʰ� Ǯ �� �־��� ����.
    //�ٸ� ��� Ǯ�̿� max�� ���°� �� ���ƺ����� �Ʒ��ٰ� ����д�. max min �Լ� ���� ���� �ʱ�

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