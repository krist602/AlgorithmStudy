//Programmers > 연습문제 > 124 나라의 숫자
//https://programmers.co.kr/learn/courses/30/lessons/12899

    //나는 map 자료형을 이용해서 나머지가 들어갈 때마다 적절한 값이 나오도록 구현해놨다.
    //그리고 string형식을 거꾸로 뒤집어주기 위해 새로운 string형을 만들고 for문으로 뒤집는 방법을 썼었다.
    //근데 다른 사람 코드를 보니 재밌는 게 있어 가져왔다.
    //앞에 새로운 것을 넣고 뒤에 기존 string값을 넣는다면 그게 string을 뒤집는 방법이었다.

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
        answer = num124[t % 3] + answer;  //answer == "412"[t % 3] + answer; 을 사용했더라
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

