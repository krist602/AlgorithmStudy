//Programmers > 2021 Dev-Matching: 웹 백엔드 개발자(상반기) > 행렬 테두리 회전하기
//https://programmers.co.kr/learn/courses/30/lessons/77485

	//모든 경우를 잘 그려서 풀어야했던 문제
	//하나씩 쫓아가서 오류를 찾았다.

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	vector<vector<int>> array(rows, vector<int>(columns, 0));
	int min = 1;
	int move_num;
	int tmp_num;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			array[i][j] = min++;

	for (int m = 0; m < queries.size(); m++)
	{
		int x1 = queries[m][0] - 1;
		int y1 = queries[m][1] - 1;
		int x2 = queries[m][2] - 1;
		int y2 = queries[m][3] - 1;
		min = array[x1][y1];
		move_num = min;
		int i = x1;
		int j;

		for (j = y1; j < y2; j++)
		{
			tmp_num = array[i][j + 1];
			array[i][j + 1] = move_num;
			move_num = tmp_num;

			if (min > move_num) //min값이 더 크다면 바꿔준다.
				min = move_num;
		}

		for (i = x1; i < x2; i++)
		{
			tmp_num = array[i + 1][j];
			array[i + 1][j] = move_num;
			move_num = tmp_num;

			if (min > move_num) //min값이 더 크다면 바꿔준다.
				min = move_num;
		}

		for (j = y2; j > y1; j--)
		{
			tmp_num = array[i][j - 1];
			array[i][j - 1] = move_num;
			move_num = tmp_num;

			if (min > move_num) //min값이 더 크다면 바꿔준다.
				min = move_num;
		}

		for (i = x2; i > x1; i--)
		{
			tmp_num = array[i - 1][j];
			array[i - 1][j] = move_num;
			move_num = tmp_num;

			if (min > move_num) //min값이 더 크다면 바꿔준다.
				min = move_num;
		}
		answer.push_back(min);
	}

	return answer;
}