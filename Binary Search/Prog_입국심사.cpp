//Programmers > �̺�Ž�� > �Ա��ɻ�
//https://programmers.co.kr/learn/courses/30/lessons/43238

    //�ִ��� ���� ���� �ɸ��� �ɻ������ ��� ����� �������� ���� ��´�.
    //�߰����� �ð��� �Է����� ��, ���� ó���� �� �ִ� ����� ��� ���ϰ�,
    //�� ���� ��� �ο�(n)���� ũ�ٸ� answer�� �Է��� ��, �߰����� ���δ�.
    //�ݴ��� ����� ��� �ο��� ó������ ���ϱ� ������ answer�� �Է����� �ʰ�, �߰����� ���δ�.

#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, minTime = 1, maxTime, avgTime;
    maxTime = *max_element(times.begin(), times.end()) * (long long)n; //maxTime�� times�� �ִ� * n�� �Է�
    //����� max_element�� algorithm ��� ���Ͽ� �����ϸ�, �ּҰ��� ��ȯ�ϱ� ������ �� ���� ���������� *�� ����ؾ���.
    //�� ���� �����ϰ� �ʹٸ� �迭�� ��� ������, ���� ���� ��� �ش� ���ͷ����� ������ �����ؾ� �Ѵٰ� ������ ���� ���� ����.

    while (minTime <= maxTime) //min�� max���� ���� ���� �ݺ�
    {
        long long human = 0; //ó���� �� �ִ� ����� ���� ���� �Լ�.
        avgTime = (minTime + maxTime) / 2; //�߰����� min + max / 2

        for (auto i : times) 
            human += avgTime / i; //�� �ɻ���� �־��� �ð����� ó���� �� �ִ� �ο� ���� �����ش�.

        if (human >= n) //ó���� �� �ִ� �ο��� �־��� ��� �ο����� ũ�ٸ�
        {
            answer = avgTime; //���信 �ð��� �Է��� ����
            maxTime = avgTime - 1; //max���� avg���� ������ �����´�.
        }
        else
            minTime = avgTime + 1; //�ݴ��� ��쿣 min���� avg���� �ڷ� ������.
    }

    return answer;
}