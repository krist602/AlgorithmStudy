//Programmers > 2021 KAKAO BLIND RECRUITMENT > 순위 검색
//https://programmers.co.kr/learn/courses/30/lessons/72412
//2022-06-29(수) 18:56

/*
    처음에는 그냥 조건문으로 해결하려했지만 효율성에서 실패함.
    인터넷에서 어떻게 해결했나 찾아봤다.

            1. 문자열 파싱함수에는 3가지가 있다. stringstream, istringstream, ostringstream.
               전부 알아두면 좋을 것 같다. 모두 <sstream>에 들어있다.

            2. lower_bound와 upper_bound 함수가 있다.
               lower_bound는 key값과 같거나 큰 주소값을 반환한다.
               근데 .end()에서 lower_bound()를 빼는 연산을 해도 된다는 것은 처음 알았다.
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