//Programmers > 2019 KAKAO BLIND RECRUITMENT > �ĺ�Ű
//https://programmers.co.kr/learn/courses/30/lessons/42890
//2022-06-16(��) 15:15

/*
    ���� �س½��ϴ� ������!
    
        1. ��Ʈ���꿡�� &�� Ȱ���� ���� ���� ���ԵǾ��ִ��� ����� �� �ִ�. 
           (A & B) == A -> A�� B�� ���ԵǾ�����.
           (A | B) == B -> A�� B�� ���ԵǾ�����.
    
        2. ���� ó�� Ǯ�̿����� pow(2, x)�� ����ߴµ�, 2�� �������� ��Ʈ����Ʈ�� �ٸ��� ����. �װ� Ȱ���ϴ°� �� �˾ƺ��⵵ ���� ����ϴ�.
           pow(2, x) == (1 << x)

        3. �ٸ� ����� Ǯ�̿����� flag�� ������� �ʰ�, �ϴ� ��� set�� insert�� ����, set�� size�� relation�� size�� ���ߴ�.
           �׷� ����� �ֱ��� �˾Ƶΰ� �Ѿ�°� ���� ���̴�.
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
                    temp_key += ","; //AB, BC�� A, BBC�� �����ϱ� ���� �߰�.
                }
            }

            if (candi.find(temp_key) != candi.end())
            {
                //�����Ͱ� �̹� ������ -> �ĺ�Ű �Ұ���
                flag = false;
                break;
            }
            candi.insert(temp_key);
        }

        if (flag)
        {
            //c�� �ĺ�Ű�� �����ϴ�.
            candi_key.push_back(c);
        }
    }

    return candi_key.size();
}