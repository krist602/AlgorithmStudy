//Programmers > 탐욕법(Greedy) > 큰 수 만들기
//https://programmers.co.kr/learn/courses/30/lessons/42883


    //for문 너무 복잡하다.
    //아직 잘 이해 못했음... 후에 다시 확인해야지 ㅠㅠ

#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int j = 0, index = -1; j < number.length() - k; j++) {
        char max = 0;
        for (int i = index + 1; i <= k + j; i++) {
            if (max < number[i]) {
                index = i;
                max = number[i];
            }
        }
        answer += max;
    }
    return answer;
}