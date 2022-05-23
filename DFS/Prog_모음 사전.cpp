//Programmers > ��Ŭ�� ç���� > ���� ����
//https://programmers.co.kr/learn/courses/30/lessons/84512

    //dfs�� ����
    //�׳� for������ ������ �����ϰų�, map������ ����ص� �ȴ�.
    //map<string, int> words�� �� ����, words.size()�� int�� ������ �Ǵ���

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