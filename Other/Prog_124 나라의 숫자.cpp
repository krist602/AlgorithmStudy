//Programmers > �������� > 124 ������ ����
//https://programmers.co.kr/learn/courses/30/lessons/12899

    //���� map �ڷ����� �̿��ؼ� �������� �� ������ ������ ���� �������� �����س���.
    //�׸��� string������ �Ųٷ� �������ֱ� ���� ���ο� string���� ����� for������ ������ ����� �����.
    //�ٵ� �ٸ� ��� �ڵ带 ���� ��մ� �� �־� �����Դ�.
    //�տ� ���ο� ���� �ְ� �ڿ� ���� string���� �ִ´ٸ� �װ� string�� ������ ����̾���.

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int n) {
    string answer = "";
    map <int, string> num124;
    num124[0] = "4";
    num124[1] = "1";
    num124[2] = "2";
    int t = n;

    while (t != 0)
    {
        answer = num124[t % 3] + answer;  //answer == "412"[t % 3] + answer; �� ����ߴ���
        if (t % 3 == 0)
        {
            t -= 1;
        }
        t /= 3;
    }
    //for (int i = temp_str.size() - 1; i >= 0; i--)
    //{
    //    answer += temp_str[i];
    //}

    return answer;
}

