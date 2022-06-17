//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3차] 압축
//https://programmers.co.kr/learn/courses/30/lessons/17684
//2022-06-17(금) 17:49

/*
    그냥 하라는대로 하니까 풀리긴 했다.
    
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;

    string search = "";
    int pre_i = 0;
    int i = 0;

    while (i < msg.length())
    {
        search += msg[i];
        if (search.length() <= 1) //A ~ Z까지 값 입력해주기 싫어서 연산
            pre_i = msg[i] - 'A' + 1;
        else
        {
            if (dict.find(search) == dict.end()) //찾는 문자열이 아직 사전에 등록이 안되어있다면
            {
                dict[search] = dict.size() + 27; //사전에 등록을 해주고
                answer.push_back(pre_i); //이전 인덱스 값을 넣어주고
                pre_i = msg[i] - 'A' + 1; //남은 값을 다시 저장해서 돌아간다.
                search = msg[i];
            }
            else
                pre_i = dict[search]; //사전에서 지금까지의 값을 등록.
        }

        i++;

        if (i == msg.length())
            answer.push_back(pre_i);
    }

    return answer;
}