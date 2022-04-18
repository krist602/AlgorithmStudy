//Baekjoon > 1918 > 후위 표기식
//https://www.acmicpc.net/problem/1918

	//stack이라는건 깨달았지만, 설마 이렇게 전부 구현일줄은 몰랐다 !

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Post(string expression)
{
	stack<char> operation;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= 'A' && expression[i] <= 'Z')
		{
			cout << expression[i];
		}
		else
		{
			if (expression[i] == '(')
				operation.push(expression[i]);
			else if (expression[i] == '*' || expression[i] == '/')
			{
				while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
				{
					cout << operation.top();
					operation.pop();
				}
				operation.push(expression[i]);
			}
			else if (expression[i] == '+' || expression[i] == '-')
			{
				while (!operation.empty() && operation.top() != '(')
				{
					cout << operation.top();
					operation.pop();
				}
				operation.push(expression[i]);
			}
			else if (expression[i] == ')')
			{
				while (!operation.empty() && operation.top() != '(')
				{
					cout << operation.top();
					operation.pop();
				}
				operation.pop();
			}
		}
	}
	while (!operation.empty())
	{
		cout << operation.top();
		operation.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	string expression;
	cin >> expression;

	Post(expression);

	return 0;
}