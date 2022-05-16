//Programmers > 월간 코드 챌린지 시즌1 > 쿼드압축 후 개수 세기
//https://programmers.co.kr/learn/courses/30/lessons/68936

    //구현문제.
    //4분할로 어떻게 나눠줄지 재귀를 사용했다.
    //만들어놓고 보니 설명할게 없는 코든데, 처음에 조금 헤맴

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quad(vector<vector<int>>& arr, vector<int>& answer, int size, int start_row, int start_col)
{
    int num = arr[start_row][start_col];

    for (int row = start_row; row < start_row + size; row++)
        for (int col = start_col; col < start_col + size; col++)
        {
            if (num != arr[row][col])
            {
                //1분면 0 ~ size()/2 까지
                quad(arr, answer, size / 2, start_row, start_col);

                //2분면 x = size()/2 ~ arr.size() 까지, y = 0 ~ size()/2까지
                quad(arr, answer, size / 2, start_row + size / 2, start_col);

                //3분면 x = 0 ~ size()/2 까지. y = size()/2 ~ arr.size()
                quad(arr, answer, size / 2, start_row, start_col + size / 2);

                //4분면 size()/2 ~ arr.size()까지
                quad(arr, answer, size / 2, start_row + size / 2, start_col + size / 2);

                return;
            }
        }

    answer[num]++;

    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);

    quad(arr, answer, arr.size(), 0, 0);

    return answer;
}
