//Programmers > 탐욕법(Greedy) > 체육복
//https://programmers.co.kr/learn/courses/30/lessons/42862

	//전체 탐색하기 싫었지만...

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	int student[35] = { 0 };

	for (auto i : lost) //잃어버린 학생은 -=1로
		student[i] -= 1;
	for (auto i : reserve) //여벌이 있는 학생은 +=1로 해주면 여벌이 있는데 도난당한 학생은 0으로 표현
		student[i] += 1;

	for (int i = 0; i <= n; i++)
		if (student[i] * student[i + 1] == -1) //앞뒤로 1과 -1이 있다면 곱했을 시에 -1이 나온다.
		{
			student[i] = 0; //두 학생 전부 초기화
			student[i + 1] = 0;
		}

	for (int i = 0; i <= n; i++)
		if (student[i] == -1) //전체 학생에서 잃어버린 학생만큼 빼준다.
			answer--;

	return answer;
}