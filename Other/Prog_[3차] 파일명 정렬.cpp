//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3차] 파일명 정렬
//https://programmers.co.kr/learn/courses/30/lessons/17686
//2022-06-19(일) 13:20

/*
    cmp함수를 넣지 않아도 정렬이 잘된다. pair형태의 비교 함수 기본형이 cmp함수처럼 생겼나봄

    stable_sort라는 정렬 방법이 있다. 나는 index값을 넣어서 모두 같을 시 index값 기준으로 정렬하게 해주었지만,
    stable_sort는 index값을 넣지 않아도 index 순서대로 정렬을 해준다. 알아두면 좋을 것이다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b)
{
    if (a.first.first < b.first.first)
        return a < b;
    else if (a.first.second < b.first.second)
        return a < b;
    else if (a.second < b.second)
        return a < b;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string, int>, int>> file_name;
    for (int i = 0; i < files.size(); i++)
    {
        string Head = "";
        string Number = "";
        string Tail = "";
        for (int l = 0; l < files[i].length(); l++)
        {
            if (Number == "" && !isdigit(files[i][l]))
                Head += tolower(files[i][l]);
            else if (Tail == "" && isdigit(files[i][l]))
                Number += files[i][l];
            else
                Tail += files[i][l];
        }
        file_name.push_back({ {Head, stoi(Number)}, i });
    }
    sort(file_name.begin(), file_name.end(), cmp);

    for (auto f : file_name)
        answer.push_back(files[f.second]);

    return answer;
}