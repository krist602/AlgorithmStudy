//Programmers > 2021 카카오 채용연계형 인턴십 > 거리두기 확인하기
//https://programmers.co.kr/learn/courses/30/lessons/81302
//2022-06-14(화) 16:47

/*
		1. 구현으로 하나하나 다 따지게 풀었는데 코드가 너무 복잡하다.
	
		2. 그래서 다른 사람은 어떻게 풀었나 확인했더니, vector<int> visit을 이용해 풀었다. 그게 더 좋아보이더라... 
		   좌석이 'P'라면 상하좌우 좌석을 확인한다. 
		    _1 'P'라면 false
			_2 'X'라면 continue
			_3 'O'라면 visit값을 확인한다. 이미 방문한 경우가 있다면 옆옆 좌석이 사람이 있다는 뜻이기에 false. 없다면 true로 값을 변경하고 지나간다.


		그 코드를 첨부해둔다.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
"POOOP",
"OXXOX",
"OPXPX",
"OOXOX",
"POXXP"
*/

bool is_valid_place(const vector<string>& place)
{
	constexpr size_t N = 5;

	vector<vector<int>> is_in_use(
		N,
		vector<int>(N, false)
	);

	int di[] = { 1,-1,0,0 };
	int dj[] = { 0,0,1,-1 };

	for (size_t i = 0; i != N; ++i)
		for (size_t j = 0; j != N; ++j)
			if (place[i][j] == 'P') {
				for (size_t k = 0; k != 4; ++k) {
					size_t moved_i = i + di[k];
					size_t moved_j = j + dj[k];

					if (moved_i >= N || moved_j >= N)
						continue;

					switch (place[moved_i][moved_j]) {
					case 'P':
						return false;
					case 'O':
						if (is_in_use[moved_i][moved_j])
							return false;

						is_in_use[moved_i][moved_j] = true;
						break;
					case 'X':
						break;
					}
				}
			}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer(5);
	for (size_t i = 0; i != 5; ++i)
		answer[i] = is_valid_place(places[i]);
	return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int r[] = { 0, 1, 1, -1, 0, 2 };
int c[] = { 1, 0, 1, 1, 2, 0 };
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int room = 0; room < 5; room++)
	{
		bool flag = true;
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				if (places[room][row][col] == 'P')
				{
					int i = 0;
					int con_row = 0;
					int con_col = 0;
					for (i = 0; i < 2; i++)
					{
						con_row = row + r[i];
						con_col = col + c[i];

						if (con_row >= 5 || con_col >= 5)
							continue;

						if (places[room][con_row][con_col] == 'P')
						{
							//바로 옆이 사람 -> 거리두기X
							flag = false;
						}
					}

					i = 2;
					con_row = row + r[i];
					con_col = col + c[i];

					if (con_row < 5 && con_col < 5)
						if (places[room][con_row][con_col] == 'P')
						{
							if (places[room][con_row - 1][con_col] != 'X' || places[room][con_row][con_col - 1] != 'X')
							{
								//하나라도 파티션이 아님 -> 거리두기X
								flag = false;
							}
						}


					i = 3;
					con_row = row + r[i];
					con_col = col + c[i];

					if (con_row < 5 && con_col < 5 && con_row >= 0 && con_col >= 1)
						if (places[room][con_row][con_col] == 'P')
						{
							if (places[room][con_row + 1][con_col] != 'X' || places[room][con_row][con_col - 1] != 'X')
							{
								//하나라도 파티션이 아님 -> 거리두기X
								flag = false;
							}
						}


					for (i = 4; i < 6; i++)
					{
						con_row = row + r[i];
						con_col = col + c[i];

						if (con_row >= 5 || con_col >= 5)
							continue;

						if (places[room][con_row][con_col] == 'P')
						{
							if (places[room][con_row - r[i - 4]][con_col - c[i - 4]] != 'X')
							{
								//거리두기 X
								flag = false;
							}
						}
					}


				}
			}
		}

		answer.push_back(flag);

	}

	return answer;
}