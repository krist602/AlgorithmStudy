//Programmers > 정렬 > K번째 수
//https://programmers.co.kr/learn/courses/30/lessons/42748

    //K번째 수의 인덱스는 K-1임을 생각해야한다.

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> cut_num;
        for (int l = commands[i][0] - 1; l < commands[i][1]; l++)
        {
            cut_num.push_back(array[l]);
        }
        sort(cut_num.begin(), cut_num.end());
        answer.push_back(cut_num[commands[i][2] - 1]);
    }

    return answer;
}