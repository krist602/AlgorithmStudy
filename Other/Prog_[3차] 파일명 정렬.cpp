//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3��] ���ϸ� ����
//https://programmers.co.kr/learn/courses/30/lessons/17686
//2022-06-19(��) 13:20

/*
    cmp�Լ��� ���� �ʾƵ� ������ �ߵȴ�. pair������ �� �Լ� �⺻���� cmp�Լ�ó�� ���峪��

    stable_sort��� ���� ����� �ִ�. ���� index���� �־ ��� ���� �� index�� �������� �����ϰ� ���־�����,
    stable_sort�� index���� ���� �ʾƵ� index ������� ������ ���ش�. �˾Ƶθ� ���� ���̴�.
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