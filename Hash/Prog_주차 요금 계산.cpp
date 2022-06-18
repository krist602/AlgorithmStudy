//Programmers > 2022 KAKAO BLIND RECRUITMENT > ���� ��� ���
//https://programmers.co.kr/learn/courses/30/lessons/92341
//2022-06-18(��) 21:40

/*
        1. string�� Ȱ�� �� stringstream�� Ȱ��� �� ����ϱ� 
           �ǳ� �� ��Գ� �׸��� ��Ծ�� �Դ� �͵� �����鼭

        2. �ø��Լ��� ��� �ȳ��� �������� �ֳ� ���ķ� ����ߴ�. �ø��Լ��� ceil�̶���. �ݿø��� round, ������ floor.
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> car_fees;
    map<int, int> car_records;

    for (int i = 0; i < records.size(); i++) //���� stringstream���� ������ �����ϸ� �� ����ϰ� �̾Ƴ� �� �ִ�.
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

        if (car_time <= 0) //0���� �۴ٴ� ���� ������ϸ� �ְ�, ��������� ���ٴ� ���̴�.
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