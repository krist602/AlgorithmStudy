// Programmers > ���� / �ʺ� �켱 Ž��(DFS / BFS) > ������
//https://programmers.co.kr/learn/courses/30/lessons/43163

	//�����θ� ��� ������ ����, ���� ���ĺ������� ���� ���� ã���ش�.
	//DFS

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> answerlist;

void dfs(vector<vector<string>>& tickets, vector<pair<int, int>>& visited, string from, int count) 
{
	if (count == tickets.size()) //������ ������ Ž�� ��
	{
		vector<string> answer;
		vector<pair<int, int>> temp = visited; //������ ��ġ�� �ʱ� ���� �纻 ����

		sort(temp.begin(), temp.end()); //����(count)��� ����

		for (auto a : temp)
			answer.push_back(tickets[a.second][0]);  //a.second(temp.second)���� �ε������� ����Ǿ��ִ�. answer�� push_back. 

		answer.push_back(tickets[temp[temp.size() - 1].second][1]); //������ ���(������ ������)�� ���� �־��ش�.
		answerlist.push_back(answer); //��ΰ� ���� ���� �� �ֱ� ������ ��� ��θ� answerlist�� push_back.

		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (visited[i].second == -1 && tickets[i][0] == from)
		{
			visited[i] = { count, i }; 
			dfs(tickets, visited, tickets[i][1], count + 1); //����Ѵ�.
			visited[i] = { 0, -1 }; //���� �Ŀ��� �湮���� ���� ���·� ���� <<<���⶧���� ��Ǯ����
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<pair<int, int>> visited(tickets.size(), { 0 , -1 }); //�湮�ߴ��� �˻�. first���� ����, second�� �湮 ���� ���¸� -1, �湮������ �ε�����.
	dfs(tickets, visited, "ICN", 0);

	sort(answerlist.begin(), answerlist.end()); //���� ���� �� �ִ� ��θ� ��� �������ش�. ���ĺ� ������ ����.

	return answerlist[0]; //���� ���� ���� ����
}