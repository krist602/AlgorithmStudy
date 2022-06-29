//Programmers > 2021 KAKAO BLIND RECRUITMENT > ���� �˻�
//https://programmers.co.kr/learn/courses/30/lessons/72412
//2022-06-29(��) 18:56

/*
    ó������ �׳� ���ǹ����� �ذ��Ϸ������� ȿ�������� ������.
    ���ͳݿ��� ��� �ذ��߳� ã�ƺô�.

            1. ���ڿ� �Ľ��Լ����� 3������ �ִ�. stringstream, istringstream, ostringstream.
               ���� �˾Ƶθ� ���� �� ����. ��� <sstream>�� ����ִ�.

            2. lower_bound�� upper_bound �Լ��� �ִ�.
               lower_bound�� key���� ���ų� ū �ּҰ��� ��ȯ�Ѵ�.
               �ٵ� .end()���� lower_bound()�� ���� ������ �ص� �ȴٴ� ���� ó�� �˾Ҵ�.
*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    map<string, vector<int>> personInfo;

    for (int i = 0; i < info.size(); i++)
    {
        istringstream iss(info[i]);
        string person[4][2] = { {"-"}, {"-"}, {"-"}, {"-"} };
        int personScore = 0;
        iss >> person[0][1] >> person[1][1] >> person[2][1] >> person[3][1] >> personScore;
        string tempInfo = "";
        for (int l = 0; l < 2; l++)
            for (int j = 0; j < 2; j++)
                for (int m = 0; m < 2; m++)
                    for (int n = 0; n < 2; n++)
                    {
                        tempInfo = person[0][l] + person[1][j] + person[2][m] + person[3][n];
                        personInfo[tempInfo].push_back(personScore);
                    }
    }

    for (auto& a : personInfo)
        sort(a.second.begin(), a.second.end());

    for (int i = 0; i < query.size(); i++)
    {
        istringstream iss(query[i]);
        string trash;
        string queryA[4] = {};
        string queryString = "";
        int queryScore = 0;
        iss >> queryA[0] >> trash >> queryA[1] >> trash >> queryA[2] >> trash >> queryA[3] >> queryScore;

        for (int j = 0; j < 4; j++)
            queryString += queryA[j];

        vector<int> findScore = personInfo[queryString];

        answer[i] = findScore.end() - lower_bound(findScore.begin(), findScore.end(), queryScore);
    }

    return answer;
}