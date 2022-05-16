//Programmers > ���� �ڵ� ç���� ����1 > ������� �� ���� ����
//https://programmers.co.kr/learn/courses/30/lessons/68936

    //��������.
    //4���ҷ� ��� �������� ��͸� ����ߴ�.
    //�������� ���� �����Ұ� ���� �ڵ絥, ó���� ���� ���

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
                //1�и� 0 ~ size()/2 ����
                quad(arr, answer, size / 2, start_row, start_col);

                //2�и� x = size()/2 ~ arr.size() ����, y = 0 ~ size()/2����
                quad(arr, answer, size / 2, start_row + size / 2, start_col);

                //3�и� x = 0 ~ size()/2 ����. y = size()/2 ~ arr.size()
                quad(arr, answer, size / 2, start_row, start_col + size / 2);

                //4�и� size()/2 ~ arr.size()����
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
