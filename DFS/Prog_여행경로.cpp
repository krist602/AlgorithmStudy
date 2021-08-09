// Programmers > 깊이 / 너비 우선 탐색(DFS / BFS) > 여행경로
//https://programmers.co.kr/learn/courses/30/lessons/43163

	//여행경로를 모두 저장한 이후, 가장 알파벳순으로 빠른 값을 찾아준다.
	//DFS

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> answerlist;

void dfs(vector<vector<string>>& tickets, vector<pair<int, int>>& visited, string from, int count) 
{
	if (count == tickets.size()) //마지막 층까지 탐색 시
	{
		vector<string> answer;
		vector<pair<int, int>> temp = visited; //원본은 해치지 않기 위해 사본 생성

		sort(temp.begin(), temp.end()); //순서(count)대로 정렬

		for (auto a : temp)
			answer.push_back(tickets[a.second][0]);  //a.second(temp.second)에는 인덱스값이 저장되어있다. answer에 push_back. 

		answer.push_back(tickets[temp[temp.size() - 1].second][1]); //마지막 경로(마지막 도착점)는 직접 넣어준다.
		answerlist.push_back(answer); //경로가 여러 개일 수 있기 때문에 모든 경로를 answerlist에 push_back.

		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (visited[i].second == -1 && tickets[i][0] == from)
		{
			visited[i] = { count, i }; 
			dfs(tickets, visited, tickets[i][1], count + 1); //재귀한다.
			visited[i] = { 0, -1 }; //나온 후에는 방문하지 않은 상태로 복구 <<<여기때문에 못풀었음
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<pair<int, int>> visited(tickets.size(), { 0 , -1 }); //방문했는지 검사. first에는 순서, second는 방문 안한 상태면 -1, 방문했으면 인덱스값.
	dfs(tickets, visited, "ICN", 0);

	sort(answerlist.begin(), answerlist.end()); //여러 개일 수 있는 경로를 모두 정렬해준다. 알파벳 순으로 정렬.

	return answerlist[0]; //가장 빠른 값이 저장
}