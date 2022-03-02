//Programmers > 2020 KAKAO BLIND RECRUITMENT > ���ڿ� ����
//https://programmers.co.kr/learn/courses/30/lessons/60057

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = s.size();
	int temp = s.size();
	string zip = "";

	for (int i = 1; i <= s.size() / 2; i++)
	{
		int count = 1;
		string cut_str = "";
		string temp_str = "";
		zip = "";
		for (int l = 0; l < s.size(); l = l + i)
		{
			temp_str = s.substr(l, i);
			if (cut_str != temp_str)
			{
				if (count > 1)
					zip += to_string(count);//zip�� ���ݱ��� ���� ���� �־��ش�.
				zip += cut_str;

				count = 1;
				cut_str = temp_str;
				temp_str = "";
			}
			else
			{
				count++;//������ ������� ǥ�����ش�.
			}

		}
		if (cut_str != "")
		{
			if (count > 1)
				zip += to_string(count);
			zip += cut_str;
		}
		if (answer > zip.size())
			answer = zip.size();
	}

	return answer;
}