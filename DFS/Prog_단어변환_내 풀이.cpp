//Programmers > ����/�ʺ� �켱 Ž��(DFS/BFS) > �ܾ� ��ȯ
//https://programmers.co.kr/learn/courses/30/lessons/43163


	//Ư�� words�� ã�� ���� �ƴ϶�, words������ ��θ� ã�ƾ� �Ѵ�.
	//DFS

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answerlist;

void dfs(vector<string> words, string cur_word, string target, int count, bool visit[], int index)
{
	if (count == words.size()) //���� ����� ������ ���� cur_word�� target�� ���� ���� return
	{
		if (cur_word == target)
			answerlist.push_back(count);
		return;
	}

	count++; //Ž���� ������ count�� �÷��ش�.
	visit[index] = true; //�湮������ index�� true��.

	for (int i = 0; i < words.size(); i++)
	{
		int diff = 0; //�ܾ�� ���̸� ���ش�
		for (int j = 0; j < words[i].size(); j++)
		{
			if (cur_word[j] != words[i][j])
				diff++;
		}
		if (diff == 1) //���̰� 1�� ��쿡�� ���� Ž������ ������
		{
			if (words[i] == target)
			{
				answerlist.push_back(count); //words[i]�� target�� ��� ����Ƚ���� �߰��ϰ� return. (�ٸ� �ּڰ��� �ֳ� Ȯ���Ϸ�)
				return;
			}

			if (!visit[i]) //�湮���� ���� ���� ã�ư���.
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

		if (i == words.size() - 1) //������ Ž�������� target�� ���� ��� 0�� return.
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