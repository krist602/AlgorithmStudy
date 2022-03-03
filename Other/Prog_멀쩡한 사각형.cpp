//Programmers > Summer/Winter Coding(2019) > ������ �簢��
//https://programmers.co.kr/learn/courses/30/lessons/62048

    //���� �簢���� ���� Ȥ�� ������ ũ�⸸ŭ�� �⺻������ �ʿ��ϰ� �� �ܿ� ��ǥ�� �Ҽ��� ���� �Ѱ��� �߰��Ѵٴ� ���� ������� Ǯ����.
    //�׷��� Ǯ�̴� �״�е� ��� Ʋ���ٰ� �ڷ����� �����÷ο�ȴٴ� ���� ���޾Ұ�(w, h < 100000000) h�� w�� ���� long()���� �ٲ��־� ����ߴ�.
    //  ����� ���α׷��ӽ������� long long( ) �� ��ȯ�� ������� �ʾҴ�.
    //�ٸ� �������� Ǯ�̰����� ���� GCD(�ִ�����)�� �̿��� Ǯ����. 
    //�߸��� �簢���� ������ w+h���� gcd�� ���� �����Ѵٰ� �Ѵ�.(��ġ�� �κ��� ����)
    //Ǯ�̺���, �ִ������� ���ϴ� ����� �߿��ϱ⿡ ����صд�.

#include <vector>

using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    long long cut_square = h;
    double x = 0; // 12 / 8 = 1.5
    for (int i = 0; i < w; i++) // i�� 0���� 7����
    {
        x = double(h) * double(i) / double(w);
        if (x - (int)x > 1e-12) //x�� �Ҽ����
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