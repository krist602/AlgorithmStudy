//Programmers > 해시 > 완주하지 못한 선수
//https://programmers.co.kr/learn/courses/30/lessons/42576

    //둘의 수가 다르다는 것을 이용해야 한다.

#include <vector>
#include <map>

using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> member;

    for (auto c : completion)
    {
        member[c] += 1; //완주자들에게 값을 먼저 넣어주고
    }

    for (auto p : participant)
    {
        member[p] -= 1; //참가자들을 빼다보면
        if (member[p] < 0) //완주자와 수가 다르다면(참가자가 더 많다면) return한다.
            return p;
    }
}