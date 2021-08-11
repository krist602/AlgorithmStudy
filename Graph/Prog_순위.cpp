//Programmers > 그래프 > 순위
//https://programmers.co.kr/learn/courses/30/lessons/49191


	//Floyd Warshall 알고리즘 이용
	//	모든 노드에서 다른 모든 노드로의 최소 비용 경로 갱신 알고리즘
	//4가 3에게 이겼다면 [4][3]에 1 입력.
	//이후 Floyd Warshall을 이용해서 4가 3에게 이겼고, 3이 5에게 이겼다면, [4][5]에도 1 입력.
	//반복해서 확실히 이긴 사람만을 알 수 있게 표시한다.
	//그렇다면, [i][j]와 [j][i]를 탐색해서 둘 중 하나의 값이라도 1이 있다면, [i][j]끼리의 승부가 가려진다.
	

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> verse(n + 1, vector<bool>(n + 1, 0)); //전부 0으로 초기화

	for (int i = 0; i < results.size(); i++)
		verse[results[i][0]][results[i][1]] = 1; //이겼다면 1을 표시

	for (int v = 1; v <= n; v++) // v = via. 경유하는 사람
		for (int s = 1; s <= n; s++) // s = start. 시작 위치
			for (int e = 1; e <= n; e++) // e = end. 목표 위치
				if (verse[s][v] && verse[v][e]) //s가 v를 이기고, v가 e를 이겼다면, s도 e를 이겼기 때문에 1로 표시
					verse[s][e] = 1;

	for (int i = 1; i <= n; i++)
	{
		int WorL = 0; //승패가 정해진 사람의 수를 센다.
		for (int j = 1; j <= n; j++)
			if (verse[i][j] || verse[j][i]) //[i][j]와 [j][i] 중에 하나라도 1이 있다면 승패가 가려졌기 때문에
				WorL++; //++

		if (WorL == n - 1) //승패를 가린 사람이 전체 인원 - 자기 자신 이라면
			answer++; //answer++
	}

	return answer;
}