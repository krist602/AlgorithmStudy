//Programmers > Summer/Winter Coding(2019) > 멀쩡한 사각형
//https://programmers.co.kr/learn/courses/30/lessons/62048

    //나는 사각형이 가로 혹은 세로의 크기만큼은 기본적으로 필요하고 그 외에 좌표가 소수일 때에 한개씩 추가한다는 점을 기반으로 풀었다.
    //그러나 풀이는 그대론데 계속 틀리다가 자료형이 오버플로우된다는 것을 깨달았고(w, h < 100000000) h와 w를 각각 long()으로 바꿔주어 계산했다.
    //  참고로 프로그래머스에서는 long long( ) 형 변환이 실행되지 않았다.
    //다른 유저들의 풀이과정을 보니 GCD(최대공약수)를 이용해 풀었다. 
    //잘리는 사각형의 개수는 w+h에서 gcd를 빼면 성립한다고 한다.(겹치는 부분을 제거)
    //풀이보다, 최대공약수를 구하는 방식이 중요하기에 기록해둔다.

#include <vector>

using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    long long cut_square = h;
    double x = 0; // 12 / 8 = 1.5
    for (int i = 0; i < w; i++) // i는 0부터 7까지
    {
        x = double(h) * double(i) / double(w);
        if (x - (int)x > 1e-12) //x가 소수라면
            cut_square++;
    }
    answer = long(h) * long(w) - cut_square;
    return answer;
}

//======================================================================

#include <vector>

using namespace std;

long long gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long solution(int w, int h)
{
    long long answer = 1;
    int t = gcd(w, h);
    answer = (long long)((long long)w * (long long)h) - (w + h - t);
    return answer;
}