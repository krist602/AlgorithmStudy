//Programmers > ���� > K��° ��
//https://programmers.co.kr/learn/courses/30/lessons/42748

    //K��° ���� �ε����� K-1���� �����ؾ��Ѵ�.

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