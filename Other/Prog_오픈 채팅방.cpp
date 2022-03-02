//Programmers > 2019 KAKAO BLIND RECRUITMENT > 오픈채팅방
//https://programmers.co.kr/learn/courses/30/lessons/42888

    //나는 find와 rfind를 이용해 문제를 풀었다.
    //구분문자열이 공백이 아니거나 여러 일반적인 상황에선 find와 rfind가 좀 더 쓰일 것 같다.
    //하지만 sstream이라는 좋은 기능이 있다는 것을 배웠다.
    //자동으로 공백이나 \n문자를 기준으로 나눠준다. 

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> temp_answer;
    unordered_map<string, string> userID; //각 uid에 가장 마지막 닉네임을 덮어둔다.

    for (int i = 0; i < record.size(); i++)
    {
        int fspaceidx = record[i].find(" ");
        string command_str = record[i].substr(0, fspaceidx);

        if (command_str == "Enter")
        {
            string uid_str = record[i].substr(fspaceidx + 1, record[i].rfind(" ") - fspaceidx - 1);
            string user_name = record[i].substr(record[i].rfind(" ") + 1, record[i].size() - record[i].rfind(" "));
            temp_answer.push_back(uid_str); //idx 2n
            temp_answer.push_back("님이 들어왔습니다."); //idx 2n + 1
            userID[uid_str] = user_name;
        }
        else if (command_str == "Leave")
        {
            string uid_str = record[i].substr(fspaceidx + 1, record[i].size() - fspaceidx);
            temp_answer.push_back(uid_str);
            temp_answer.push_back("님이 나갔습니다.");
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
        temp_answer[i + 1]; //님이 나갔습니다 들어왔습니다.
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
    unordered_map<string, string> userID; //각 uid에 가장 마지막 닉네임을 덮어둔다.

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string command_str = "";
        string uid_str = "";
        string user_name = "";
        ss >> command_str; //처음 공백까지를 command_str에 담아주고

        if (command_str == "Enter")
        {
            ss >> uid_str; //다음 공백까지 uid_str에,
            ss >> user_name; //다음 공백까지 user_name에 넣어준다.
            temp_answer.push_back(uid_str); //idx 2n
            temp_answer.push_back("님이 들어왔습니다."); //idx 2n + 1
            userID[uid_str] = user_name;
        }
        else if (command_str == "Leave")
        {
            ss >> uid_str;
            temp_answer.push_back(uid_str);
            temp_answer.push_back("님이 나갔습니다.");
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
        temp_answer[i + 1]; //님이 나갔습니다 들어왔습니다.
        answer.push_back(userID[temp_answer[i]] + temp_answer[i + 1]);
    }

    return answer;
}