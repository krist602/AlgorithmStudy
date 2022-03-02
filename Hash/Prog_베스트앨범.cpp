//Programmers > �ؽ� > ����Ʈ�ٹ�
//https://programmers.co.kr/learn/courses/30/lessons/42579

	//�ʿ��� ��� ������ �� �����ؾ��Ѵ�.

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second > b.second;
}

bool cmp2(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b)
{
	if (a.first == b.first) return a.second.first > b.second.first;
	return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	int count = 0;
	map<string, int> song;
	vector<pair<string, pair<int, int>>> mix;


	for (int i = 0; i < genres.size(); i++)
	{
		mix.push_back(pair<string, pair<int, int>>(genres[i], pair<int, int>(plays[i], i))); //�� ���� vector�� ��ġ�鼭 ������ȣ�� �־��ش�.
		song[genres[i]] += plays[i]; //� �帣�� ���� ���� �÷��̵Ǿ����� �˱� ���� map�� �������ش�.
	}

	vector<pair<string, int>> temp(song.begin(), song.end()); //map�� �ڵ� �����̱⶧���� vector�� ���� �������ش�.

	sort(temp.begin(), temp.end(), cmp);
	sort(mix.begin(), mix.end(), cmp2);

	for (int i = 0; i < temp.size(); i++)
	{
		count = 0;
		for (int l = 0; l < mix.size(); l++)
		{
			if (mix[l].first == temp[i].first)
			{
				answer.push_back(mix[l].second.second);
				count++;
			}
			if (count == 2)
				break;
		}
	}


	return answer;
}