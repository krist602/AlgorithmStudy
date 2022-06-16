//Programmers > 2021 īī�� ä�뿬���� ���Ͻ� > �Ÿ��α� Ȯ���ϱ�
//https://programmers.co.kr/learn/courses/30/lessons/81302
//2022-06-14(ȭ) 16:47

/*
		1. �������� �ϳ��ϳ� �� ������ Ǯ���µ� �ڵ尡 �ʹ� �����ϴ�.
	
		2. �׷��� �ٸ� ����� ��� Ǯ���� Ȯ���ߴ���, vector<int> visit�� �̿��� Ǯ����. �װ� �� ���ƺ��̴���... 
		   �¼��� 'P'��� �����¿� �¼��� Ȯ���Ѵ�. 
		    _1 'P'��� false
			_2 'X'��� continue
			_3 'O'��� visit���� Ȯ���Ѵ�. �̹� �湮�� ��찡 �ִٸ� ���� �¼��� ����� �ִٴ� ���̱⿡ false. ���ٸ� true�� ���� �����ϰ� ��������.


		�� �ڵ带 ÷���صд�.
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
							//�ٷ� ���� ��� -> �Ÿ��α�X
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
								//�ϳ��� ��Ƽ���� �ƴ� -> �Ÿ��α�X
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
								//�ϳ��� ��Ƽ���� �ƴ� -> �Ÿ��α�X
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
								//�Ÿ��α� X
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