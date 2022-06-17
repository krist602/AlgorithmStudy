//Programmers > 2018 KAKAO BLIND RECRUITMENT > [3��] ����
//https://programmers.co.kr/learn/courses/30/lessons/17684
//2022-06-17(��) 17:49

/*
    �׳� �϶�´�� �ϴϱ� Ǯ���� �ߴ�.
    
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
        if (search.length() <= 1) //A ~ Z���� �� �Է����ֱ� �Ⱦ ����
            pre_i = msg[i] - 'A' + 1;
        else
        {
            if (dict.find(search) == dict.end()) //ã�� ���ڿ��� ���� ������ ����� �ȵǾ��ִٸ�
            {
                dict[search] = dict.size() + 27; //������ ����� ���ְ�
                answer.push_back(pre_i); //���� �ε��� ���� �־��ְ�
                pre_i = msg[i] - 'A' + 1; //���� ���� �ٽ� �����ؼ� ���ư���.
                search = msg[i];
            }
            else
                pre_i = dict[search]; //�������� ���ݱ����� ���� ���.
        }

        i++;

        if (i == msg.length())
            answer.push_back(pre_i);
    }

    return answer;
}