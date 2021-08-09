//Programmers > 깊이/너비 우선 탐색(DFS/BFS) > 단어 변환
//https://programmers.co.kr/learn/courses/30/lessons/43163


	//특정 words를 찾는 것이 아니라, words까지의 경로를 찾아야 한다.
	//DFS

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answerlist;

void dfs(vector<string> words, string cur_word, string target, int count, bool visit[], int index)
{
	if (count == words.size()) //가장 깊숙히 들어왔을 때는 cur_word와 target를 비교한 이후 return
	{
		if (cur_word == target)
			answerlist.push_back(count);
		return;
	}

	count++; //탐색을 들어오면 count를 올려준다.
	visit[index] = true; //방문했으니 index를 true로.

	for (int i = 0; i < words.size(); i++)
	{
		int diff = 0; //단어간의 차이를 세준다
		for (int j = 0; j < words[i].size(); j++)
		{
			if (cur_word[j] != words[i][j])
				diff++;
		}
		if (diff == 1) //차이가 1인 경우에만 다음 탐색으로 들어가도록
		{
			if (words[i] == target)
			{
				answerlist.push_back(count); //words[i]가 target인 경우 정답횟수에 추가하고 return. (다른 최솟값이 있나 확인하러)
				return;
			}

			if (!visit[i]) //방문하지 않은 곳을 찾아간다.
			{
				dfs(words, words[i], target, count, visit, i);
				visit[i] = false;
			}
		}
	}

}

int solution(string begin, string target, vector<string> words) {
	bool visit[50] = { 0 };
	int count = 0;

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
		{
			break;
		}

		if (i == words.size() - 1) //끝까지 탐색했으나 target이 없는 경우 0을 return.
			return 0;
	}

	for (int i = 0; i < words.size(); i++)
	{
		int diff = 0;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (begin[j] != words[i][j])
				diff++;
		}

		if (diff == 1)
		{
			if (words[i] == target)
				return 1;

			if (!visit[i])
			{
				count++;

				dfs(words, words[i], target, count, visit, i);
				visit[i] = false;
			}
		}
	}

	if (answerlist.empty())
	{
		return 0;
	}
	sort(answerlist.begin(), answerlist.end());

	return answerlist[0];
}