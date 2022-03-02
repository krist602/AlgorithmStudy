//Programmers > �ؽ� > �������� ���� ����
//https://programmers.co.kr/learn/courses/30/lessons/42576

    //���� ���� �ٸ��ٴ� ���� �̿��ؾ� �Ѵ�.

#include <vector>
#include <map>

using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> member;

    for (auto c : completion)
    {
        member[c] += 1; //�����ڵ鿡�� ���� ���� �־��ְ�
    }

    for (auto p : participant)
    {
        member[p] -= 1; //�����ڵ��� ���ٺ���
        if (member[p] < 0) //�����ڿ� ���� �ٸ��ٸ�(�����ڰ� �� ���ٸ�) return�Ѵ�.
            return p;
    }
}