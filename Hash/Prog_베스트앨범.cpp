//Programmers > 해시 > 베스트앨범
//https://programmers.co.kr/learn/courses/30/lessons/42579

	//필요한 모든 정보를 다 저장해야한다.

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
		mix.push_back(pair<string, pair<int, int>>(genres[i], pair<int, int>(plays[i], i))); //두 개의 vector를 합치면서 고유번호도 넣어준다.
		song[genres[i]] += plays[i]; //어떤 장르가 가장 많이 플레이되었는지 알기 위해 map에 정리해준다.
	}

	vector<pair<string, int>> temp(song.begin(), song.end()); //map은 자동 정렬이기때문에 vector를 만들어서 정렬해준다.

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