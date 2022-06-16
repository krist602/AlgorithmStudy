//Programmers > 2019 KAKAO BLIND RECRUITMENT > 후보키
//https://programmers.co.kr/learn/courses/30/lessons/42890
//2022-06-16(목) 15:15

/*
    제가 해냈습니다 여러분!
    
        1. 비트연산에서 &를 활용해 현재 값이 포함되어있는지 계산할 수 있다. 
           (A & B) == A -> A가 B에 포함되어있음.
           (A | B) == B -> A가 B에 포함되어있음.
    
        2. 나는 처음 풀이에서는 pow(2, x)를 사용했는데, 2의 제곱승은 비트시프트와 다를게 없다. 그걸 활용하는게 더 알아보기도 쉽고 깔끔하다.
           pow(2, x) == (1 << x)

        3. 다른 사람의 풀이에서는 flag를 사용하지 않고, 일단 모두 set에 insert한 이후, set의 size와 relation의 size를 비교했다.
           그런 방법도 있구나 알아두고 넘어가는게 좋을 것이다.
*/


#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    vector<int> candi_key;

    int row_size = relation.size();
    int col_size = relation[0].size();
    int key_num = (1 << col_size);
    bool flag;

    for (int c = 0; c < key_num; c++)
    {
        flag = true;

        for (int k : candi_key)
        {
            if ((c & k) == k)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;

        set<string> candi;
        for (int r = 0; r < row_size; r++)
        {
            string temp_key = "";
            for (int x = 0; x < col_size; x++)
            {
                if (((1 << x) & c) == (1 << x))
                {
                    temp_key += relation[r][x];
                    temp_key += ","; //AB, BC와 A, BBC를 구분하기 위해 추가.
                }
            }

            if (candi.find(temp_key) != candi.end())
            {
                //데이터가 이미 존재함 -> 후보키 불가능
                flag = false;
                break;
            }
            candi.insert(temp_key);
        }

        if (flag)
        {
            //c는 후보키가 가능하다.
            candi_key.push_back(c);
        }
    }

    return candi_key.size();
}