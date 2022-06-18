//Programmers > 2022 KAKAO BLIND RECRUITMENT > 주차 요금 계산
//https://programmers.co.kr/learn/courses/30/lessons/92341
//2022-06-18(토) 21:40

/*
        1. string의 활용 중 stringstream의 활용법 잘 기억하기 
           맨날 츠 까먹네 그만좀 까먹어라 먹는 것도 많으면서

        2. 올림함수가 기억 안나서 나머지가 있냐 없냐로 계산했다. 올림함수는 ceil이란다. 반올림은 round, 내림은 floor.
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> car_fees;
    map<int, int> car_records;

    for (int i = 0; i < records.size(); i++) //여길 stringstream으로 정보를 가공하면 더 깔끔하게 뽑아낼 수 있다.
    {
        int hh = stoi(records[i].substr(0, 2));
        int mm = stoi(records[i].substr(3, 2));
        int car = stoi(records[i].substr(6, 4));
        if (records[i].substr(11) == "IN")
            car_records[car] -= hh * 60 + mm;
        else
            car_records[car] += hh * 60 + mm;
    }

    for (auto c_r : car_records)
    {
        int temp_fees = fees[1];
        int car_time = c_r.second;

        if (car_time <= 0) //0보다 작다는 것은 입차기록만 있고, 출차기록은 없다는 뜻이다.
            car_time += 23 * 60 + 59;

        if (car_time > fees[0])
        {
            car_time -= fees[0];
            if ((car_time % fees[2]) != 0)
                temp_fees += fees[3] * (car_time / fees[2] + 1);
            else
                temp_fees += fees[3] * (car_time / fees[2]);
        }

        car_fees[c_r.first] = temp_fees;
    }

    for (auto c_f : car_fees)
        answer.push_back(c_f.second);

    return answer;
}