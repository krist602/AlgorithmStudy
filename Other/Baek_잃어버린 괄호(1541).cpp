//Baekjoon > 1541 > �Ҿ���� ��ȣ
//https://www.acmicpc.net/problem/1541

	//�ϳ��� -�� �ִٸ�, �� �ڿ� �ִ� ���ڵ��� ���� ���� �� �ִ�.
	//�̰� �����ϱⰡ ������� ����. 
	//Ǫ�� ����� �� ���Ŀ� �ڵ� ������ ������.

	//		substr �Լ��� ���� 2���� begin�� end�� �ƴ϶� begin�� size�̴�.
	//		substr(1, 5) -> [1]���� 5����ŭ �ڸ���.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str = "";
	int s = 0, sum = 0;
	bool flag = true;
	vector<int> nums;
	vector<bool> oper; //�����ڰ� +��� true��, -��� false�� ����־���.
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '+') //�����ڸ� �����ٸ� �� ���������� ���ڴ�.
		{
			oper.push_back(true);
			nums.push_back(stoi(str.substr(s, i - s)));
			s = i + 1;
		}
		else if (str.at(i) == '-')
		{
			oper.push_back(false);
			nums.push_back(stoi(str.substr(s, i - s)));
			s = i + 1;
		}
	}
	nums.push_back(stoi(str.substr(s)));

	for (int i = 0; i < oper.size(); i++)
	{
		sum += nums[i];
		if (!oper[i]) // '-' ���
		{
			for (int j = i + 1; j < nums.size(); j++)
				sum -= nums[j];
			flag = false;
			break;
		}
	}
	if (flag)
		sum += *nums.rbegin();
	cout << sum << "\n";

	return 0;
}