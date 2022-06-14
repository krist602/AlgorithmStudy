//Programmers > 2018 KAKAO BLIND RECRUITMENT > [1차] 캐시
//https://programmers.co.kr/learn/courses/30/lessons/17680
//2022-06-14(화) 16:20

/*
    1. LRU는 Least Recently Used. 가장 오랫동안 참조하지 않은 페이지를 바꾸는 기법이다. 
        처음엔 잘못 생각해서 가장 조금 참조한 페이지를 바꾸는 코딩을 짰었다.

    2. tolower, toupper 함수를 기억해두자.

    3. map.begin() 함수를 사용하면 가장 나중에 들어온 데이터를 가르키더라. 
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
            //존재할 때
            answer++;
            cache[cities[i]] = i;
            continue;
        }
        else
        {
            if(cache.size() < cacheSize)
            {
                //cache.size()가 작을 때
                cache[cities[i]] = i;
                answer += 5;
            }
            else
            {
                //cache.size()가 같을 때. cache 교체.
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