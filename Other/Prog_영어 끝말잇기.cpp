//Programmers > Summer/Winter Coding(~2018) > 영어 끝말잇기
//https://programmers.co.kr/learn/courses/30/lessons/12981

    //set<> .find()에서 값을 찾으면 그 주소값을, 못찾으면 end()값을 반환한다는 것 기억
    //rbegin()과 begin() 역시 주소값을 반환한다는 것을 기억하기

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
        if (*(pre_word.rbegin()) != *(next_word.begin()) || english.find(next_word) != english.end()) //이 부분 기억 잘하기
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