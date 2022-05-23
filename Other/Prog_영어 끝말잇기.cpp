//Programmers > Summer/Winter Coding(~2018) > ���� �����ձ�
//https://programmers.co.kr/learn/courses/30/lessons/12981

    //set<> .find()���� ���� ã���� �� �ּҰ���, ��ã���� end()���� ��ȯ�Ѵٴ� �� ���
    //rbegin()�� begin() ���� �ּҰ��� ��ȯ�Ѵٴ� ���� ����ϱ�

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    set<string> english;
    string pre_word = words[0];

    int count = 1;

    for (int i = 1; i < words.size(); i++)
    {
        english.insert(pre_word);
        string next_word = words[i];
        count++;
        if (*(pre_word.rbegin()) != *(next_word.begin()) || english.find(next_word) != english.end()) //�� �κ� ��� ���ϱ�
        {
            if (count % n == 0)
            {
                answer[0] = n;
                answer[1] = count / n;
            }
            else
            {
                answer[0] = count % n;
                answer[1] = count / n + 1;
            }

            return answer;
        }

        pre_word = next_word;
    }


    return answer;
}