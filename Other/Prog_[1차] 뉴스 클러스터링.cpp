//Programmers > 2018 KAKAO BLIND RECRUITMENT > [1차] 뉴스 클러스터링
//https://programmers.co.kr/learn/courses/30/lessons/17677

    //isalpha라는 함수를 배워갑니다.
    //isalpha는 알파벳대문자면 1을, 소문자면 2를 return하고, 그 외에는 0을 return하는 함수이다.
    //그러곤 그냥 map에 pair로 저장시켜서 큰 값을 합집합멤버에, 작은 값을 교집합멤버에 넣고 계산했다.
    //user풀이중에 흥미 있던 것은 나처럼 map에 string으로 저장하는게 아니라 자리수개념으로 AB일 경우 (A&31)*26 + B&31 형식으로 계산한 경우가 있었다.
    //A부터 Z까지 총 26개이므로 00001부터 11010 총 5비트면 전부 표현할 수 있기 때문에 &31(11111)을 이용해 비트연산을 해서 값을 줄여준 것이다.

#include <string>
#include <algorithm>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int min = 0;
    int max = 0;
    map<string, pair<int, int>> group;

    string l_str = str1;
    transform(l_str.begin(), l_str.end(), l_str.begin(), ::toupper);

    string r_str = str2;
    transform(r_str.begin(), r_str.end(), r_str.begin(), ::toupper);

    for (int i = 0; i < l_str.size() - 1; i++)
        if (isalpha(l_str[i]) && isalpha(l_str[i + 1]))
            group[l_str.substr(i, 2)].first += 1;

    for (int i = 0; i < r_str.size() - 1; i++)
        if (isalpha(r_str[i]) && isalpha(r_str[i + 1]))
            group[r_str.substr(i, 2)].second += 1;

    for (auto g : group)
    {
        if (g.second.first >= g.second.second)
        {
            max += g.second.first;
            min += g.second.second;
        }
        else
        {
            max += g.second.second;
            min += g.second.first;
        }
    }

    return min < max ? min * 65536 / max : 65536;
}