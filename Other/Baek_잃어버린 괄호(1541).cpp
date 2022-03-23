//Baekjoon > 1541 > 잃어버린 괄호
//https://www.acmicpc.net/problem/1541

	//하나라도 -가 있다면, 그 뒤에 있는 숫자들은 전부 빼줄 수 있다.
	//이걸 생각하기가 어려웠던 문제. 
	//푸는 방법을 안 이후에 코드 구현은 쉬웠다.

	//		substr 함수는 인자 2개가 begin과 end가 아니라 begin과 size이다.
	//		substr(1, 5) -> [1]에서 5개만큼 자른다.

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
	vector<bool> oper; //연산자가 +라면 true를, -라면 false를 집어넣었다.
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '+') //연산자를 만난다면 그 직전까지가 숫자다.
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
		if (!oper[i]) // '-' 라면
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