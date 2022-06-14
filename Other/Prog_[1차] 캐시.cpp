//Programmers > 2018 KAKAO BLIND RECRUITMENT > [1��] ĳ��
//https://programmers.co.kr/learn/courses/30/lessons/17680
//2022-06-14(ȭ) 16:20

/*
    1. LRU�� Least Recently Used. ���� �������� �������� ���� �������� �ٲٴ� ����̴�. 
        ó���� �߸� �����ؼ� ���� ���� ������ �������� �ٲٴ� �ڵ��� ®����.

    2. tolower, toupper �Լ��� ����ص���.

    3. map.begin() �Լ��� ����ϸ� ���� ���߿� ���� �����͸� ����Ű����. 
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> cache;
    
    if(cacheSize == 0)
        return 5 * cities.size();
    
    for(int i = 0; i < cities.size(); i++)
    {
        for(int l = 0; l < cities[i].size(); l++)
            cities[i][l] = tolower(cities[i][l]);
        
        if(cache.find(cities[i]) != cache.end())
        {
            //������ ��
            answer++;
            cache[cities[i]] = i;
            continue;
        }
        else
        {
            if(cache.size() < cacheSize)
            {
                //cache.size()�� ���� ��
                cache[cities[i]] = i;
                answer += 5;
            }
            else
            {
                //cache.size()�� ���� ��. cache ��ü.
                unordered_map<string,int>::iterator temp_iter = cache.begin();
                int min = temp_iter->second;
                for(auto iter = cache.begin(); iter != cache.end(); iter++ )
                {
                    if(iter->second <= min)
                    {
                        min = iter->second;
                        temp_iter = iter;
                    }
                }
                
                cache.erase(temp_iter);
                cache[cities[i]] = i;
                answer += 5;
            }
        }
    }
    
    return answer;
}