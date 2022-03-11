//Programmers > 탐욕법(Greedy) > 조이스틱
//https://programmers.co.kr/learn/courses/30/lessons/42860

	//쓰레기 문제 !
	//그리디로 해결할 수 없는 문제 !
	//최솟값을 찾으라면서 반례가 존재하지만 통과했다.
	//반례 : "ABBAAB"

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0, cur_loc = 0;
	string temp(name.length(), 'A');

	while (true) //문자열이 같아질 때까지 반복
	{
		name[cur_loc] - 'A' > 'Z' - name[cur_loc] + 1 ? answer += 'Z' - name[cur_loc] + 1 : answer += name[cur_loc] - 'A'; //각 위치마다 더해줘야하는 횟수를 구해서 answer에 더해준다.
		temp[cur_loc] = name[cur_loc]; //바꿨다는 가정으로 수를 바꾼다.

		if (temp == name) //문자열이 같으면 탈출
			break;

		for (int move = 1; move < name.length(); move++)
		{
			if (name[(cur_loc + move) % name.length()] != temp[(cur_loc + move) % name.length()]) //1칸 이동한 위치가 문자가 다르다면 이동한다.
			{
				answer += move; //이동한 만큼 더해준다
				cur_loc = (cur_loc + move) % name.length(); //현재 위치 변환
				break;
			}
			else if (name[(name.length() + cur_loc - move) % name.length()] != temp[(name.length() + cur_loc - move) % name.length()]) //이거 구현하느라 골머리. 전체에서 i를 더해주고 이동한 만큼 뺀 값을 길이로 나눴을 때 나머지가 그 위치가 된다.
			{
				answer += move; //이동한 만큼 더해준다
				cur_loc = (name.length() + cur_loc - move) % name.length(); //현재 위치 변환
				break;
			}
		}
	}

	return answer;
}
