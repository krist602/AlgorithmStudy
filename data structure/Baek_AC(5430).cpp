//Baekjoon > 5430 > AC
//https://www.acmicpc.net/problem/5430

	//vector�� ¥�� �ð� �ʰ� ���´�.
	//deque�� ���ϱ� ��û ����...
	//�׸��� string���� isdigit() �����ϴϱ� ����� ���� !

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n = 0;
		int i = 0;
		bool dir = true;
		string oper = "";
		string arr = "";
		deque<int> save_nums;

		cin >> oper;
		cin >> n;
		cin >> arr;
		string str_n = "";

		for (int i = 0; i < arr.size(); i++) //��� ���ڸ� �������� �������. ������ ��� ����� �ڵ�
		{
			if (isdigit(arr[i])) //arr[i]�� �������� �ľ��Ѵ� 
				str_n += arr[i];
			else
			{
				if (!str_n.empty())
					save_nums.push_back(stoi(str_n));
				str_n = "";
			}
		}

		for (i = 0; i < oper.size(); i++)
		{
			if (oper[i] == 'R')
				dir = !dir;
			else if (oper[i] == 'D')
			{
				if (save_nums.empty())
				{
					cout << "error\n";
					break;
				}
				else if (dir)
					save_nums.pop_front();
				else
					save_nums.pop_back();
			}
		}

		if (i == oper.size())
		{
			arr.clear();
			arr += "[";
			if (dir)
				for (auto iter = save_nums.begin(); iter != save_nums.end(); iter++)
					arr += to_string(*iter) + ",";
			else
				for (auto r_iter = save_nums.rbegin(); r_iter != save_nums.rend(); r_iter++)
					arr += to_string(*r_iter) + ",";
			arr += "]";
			if (!save_nums.empty())
				arr.erase(arr.rfind(','), 1);
			cout << arr << "\n";
		}
	}

	return 0;
}
