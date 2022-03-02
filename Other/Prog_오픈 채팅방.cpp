//Programmers > 2019 KAKAO BLIND RECRUITMENT > ����ä�ù�
//https://programmers.co.kr/learn/courses/30/lessons/42888

    //���� find�� rfind�� �̿��� ������ Ǯ����.
    //���й��ڿ��� ������ �ƴϰų� ���� �Ϲ����� ��Ȳ���� find�� rfind�� �� �� ���� �� ����.
    //������ sstream�̶�� ���� ����� �ִٴ� ���� �����.
    //�ڵ����� �����̳� \n���ڸ� �������� �����ش�. 

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> temp_answer;
    unordered_map<string, string> userID; //�� uid�� ���� ������ �г����� ����д�.

    for (int i = 0; i < record.size(); i++)
    {
        int fspaceidx = record[i].find(" ");
        string command_str = record[i].substr(0, fspaceidx);

        if (command_str == "Enter")
        {
            string uid_str = record[i].substr(fspaceidx + 1, record[i].rfind(" ") - fspaceidx - 1);
            string user_name = record[i].substr(record[i].rfind(" ") + 1, record[i].size() - record[i].rfind(" "));
            temp_answer.push_back(uid_str); //idx 2n
            temp_answer.push_back("���� ���Խ��ϴ�."); //idx 2n + 1
            userID[uid_str] = user_name;
        }
        else if (command_str == "Leave")
        {
            string uid_str = record[i].substr(fspaceidx + 1, record[i].size() - fspaceidx);
            temp_answer.push_back(uid_str);
            temp_answer.push_back("���� �������ϴ�.");
        }
        else if (command_str == "Change")
        {
            string uid_str = record[i].substr(fspaceidx + 1, record[i].rfind(" ") - fspaceidx - 1);
            string user_name = record[i].substr(record[i].rfind(" ") + 1, record[i].size() - record[i].rfind(" "));
            userID[uid_str] = user_name;
        }
    }
    for (int i = 0; i < temp_answer.size(); i = i + 2)
    {
        temp_answer[i]; //uid
        temp_answer[i + 1]; //���� �������ϴ� ���Խ��ϴ�.
        answer.push_back(userID[temp_answer[i]] + temp_answer[i + 1]);
    }

    return answer;
}

// ==========================================================================================================================================================

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> temp_answer;
    unordered_map<string, string> userID; //�� uid�� ���� ������ �г����� ����д�.

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string command_str = "";
        string uid_str = "";
        string user_name = "";
        ss >> command_str; //ó�� ��������� command_str�� ����ְ�

        if (command_str == "Enter")
        {
            ss >> uid_str; //���� ������� uid_str��,
            ss >> user_name; //���� ������� user_name�� �־��ش�.
            temp_answer.push_back(uid_str); //idx 2n
            temp_answer.push_back("���� ���Խ��ϴ�."); //idx 2n + 1
            userID[uid_str] = user_name;
        }
        else if (command_str == "Leave")
        {
            ss >> uid_str;
            temp_answer.push_back(uid_str);
            temp_answer.push_back("���� �������ϴ�.");
        }
        else if (command_str == "Change")
        {
            ss >> uid_str;
            ss >> user_name;
            userID[uid_str] = user_name;
        }
    }
    for (int i = 0; i < temp_answer.size(); i = i + 2)
    {
        temp_answer[i]; //uid
        temp_answer[i + 1]; //���� �������ϴ� ���Խ��ϴ�.
        answer.push_back(userID[temp_answer[i]] + temp_answer[i + 1]);
    }

    return answer;
}