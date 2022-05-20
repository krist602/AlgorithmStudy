//Programmers > 위클리 챌린지 > 모음 사전
//https://programmers.co.kr/learn/courses/30/lessons/84512

    //dfs로 구현
    //그냥 for문으로 돌려도 가능하거나, map구조를 사용해도 된다.
    //map<string, int> words를 한 이후, words.size()를 int에 박으면 되더라

#include <string>
#include <vector>

using namespace std;

void dfs(string word, string AEIOU, string temp_word, int* count, int* answer)
{
    if (temp_word == word)
    {
        *answer = *count;
        return;
    }

    if (temp_word.size() == 5)
        return;

    for (int i = 0; i < 5; i++)
    {
        *count += 1;
        dfs(word, AEIOU, temp_word + AEIOU[i], count, answer);

        if (*answer != -1)
            return;
    }
}

int solution(string word) {
    int answer = -1;
    int count = 0;

    dfs(word, "AEIOU", "", &count, &answer);

    return answer;
}