//Programmers > 월간 코드 챌린지 시즌1 > 삼각 달팽이
//https://programmers.co.kr/learn/courses/30/lessons/68645

	//풀이를 떠올리기 어려웠던 구현문제...
	//종이에다가 그려봐야 조금 이해가 된다.
	//구현 화이팅 취업 화이팅 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> temp(n + 1, vector<int>(n + 1, 0));

	int dir = 0;
	int x = 0, y = 0, number = 1;

	for (int i = 0; i < n; i++)
	{
		switch (dir)
		{
		case 0: //아래로
			for (int j = i; j < n; j++)
				temp[x++][y] = number++;

			x--;
			y++;
			dir = 1;
			break;
		case 1: //우측으로
			for (int j = i; j < n; j++)
				temp[x][y++] = number++;

			y -= 2;
			x--;
			dir = 2;
			break;
		case 2: //위로
			for (int j = i; j < n; j++)
				temp[x--][y--] = number++;

			x += 2;
			y++;
			dir = 0;
			break;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			answer.push_back(temp[i][j]);

	return answer;
}