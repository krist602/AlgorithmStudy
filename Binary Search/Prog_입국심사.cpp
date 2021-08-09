//Programmers > 이분탐색 > 입국심사
//https://programmers.co.kr/learn/courses/30/lessons/43238

    //최댓값은 가장 오래 걸리는 심사관에게 모든 사람을 배정했을 경우로 잡는다.
    //중간값의 시간을 입력했을 때, 각자 처리할 수 있는 사람을 모두 더하고,
    //그 값이 대기 인원(n)보다 크다면 answer에 입력한 후, 중간값을 줄인다.
    //반대의 경우라면 대기 인원을 처리하지 못하기 때문에 answer에 입력하지 않고, 중간값을 높인다.

#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, minTime = 1, maxTime, avgTime;
    maxTime = *max_element(times.begin(), times.end()) * (long long)n; //maxTime에 times의 최댓값 * n을 입력
    //참고로 max_element는 algorithm 헤더 파일에 존재하며, 주소값을 반환하기 때문에 그 값을 가져오려면 *를 사용해야함.
    //이 값을 저장하고 싶다면 배열의 경우 포인터, 벡터 등의 경우 해당 이터레이터 변수에 대입해야 한다고 하지만 아직 이해 못함.

    while (minTime <= maxTime) //min이 max보다 작을 때만 반복
    {
        long long human = 0; //처리할 수 있는 사람의 수를 담을 함수.
        avgTime = (minTime + maxTime) / 2; //중간값은 min + max / 2

        for (auto i : times) 
            human += avgTime / i; //각 심사관이 주어진 시간동안 처리할 수 있는 인원 수를 더해준다.

        if (human >= n) //처리할 수 있는 인원이 주어진 대기 인원보다 크다면
        {
            answer = avgTime; //정답에 시간을 입력한 이후
            maxTime = avgTime - 1; //max값을 avg보다 앞으로 가져온다.
        }
        else
            minTime = avgTime + 1; //반대의 경우엔 min값을 avg보다 뒤로 보낸다.
    }

    return answer;
}