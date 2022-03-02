//Programmers > �ؽ� > ��ȭ��ȣ ���
//https://programmers.co.kr/learn/courses/30/lessons/42577

	//sort�� �ϸ� ����� ���ڳ��� ���δٴ� ���� �̿��ϸ� ���� Ǯ �� �ִ�.
	//�ٸ� ������� �򿬻��� �̿��غ��� �;����� �ʹ� ����� �� ���� ����.

#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
	sort(phone_book.begin(), phone_book.end());


	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		for (int l = 0; l < phone_book[i].size(); l++)
		{
			if (phone_book[i][l] != phone_book[i + 1][l])
				break;

			if (l == phone_book[i].size() - 1)
				return false;
		}
	}
	return true;
}