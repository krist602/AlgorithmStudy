//Programmers > 그래프 > 가장 먼 노드
//https://programmers.co.kr/learn/courses/30/lessons/49189


	//가까운 노드부터 모두 탐색하여 거리를 입력해줘야 한다.
	//bfs
	//모범 답안을 보고 다시 풀긴 했지만, 시간초과가 나왔었는데, 그 이유가 bfs로 인자를 전달할 때 주소가 아니라 value를 전달했어서 그랬다.
	//      vector<vector<bool>> graph -> vector<vector<bool>> &graph

#include <vector>
#include <algorithm>

using namespace std;

void bfs(int current, vector<vector<bool>>& graph, vector<int>& distance, vector<int> route)
{
	vector<int> t_route; //다음 BFS로 보낼 임시 queue 선언

	while (!route.empty()) //route가 빌 때까지 반복
	{
		for (int i = 1; i < graph[route[0]].size(); i++) 
		{
			if (graph[route[0]][i] && !distance[i]) //연결되어있는가 && 검사했는가
			{
				distance[i] = current; //distance에 현재까지 온 거리 추가
				t_route.push_back(i); //다음으로 탐색할 노드 추가
			}
		}
		route.erase(route.begin()); //맨 앞의 인자를 지워준다. 사용했기때문.
	}
	if (!t_route.empty())
		bfs(current + 1, graph, distance, t_route); //알고리즘을 짜다가 왜 번거롭게 임시queue를 만들어서 따로 보내주는가 생각했는데, current를 계산하기 위함인 것 같다.
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<bool>> graph(n, (vector<bool>(n, false))); //연결되어 있는 곳인지 검사하기 위해 2차원 배열 선언
	vector<int> distance(n); //거리가 들어갈 vector

	for (auto a : edge)
	{
		graph[a[0] - 1][a[1] - 1] = true; //연결되어있는 노드에 true값 입력
		graph[a[1] - 1][a[0] - 1] = true;
	}
	
	//BFS 실행. { 0 }은 새로 배워간다. 처음에 queue<int>로 선언했었는데, queue에는 위와 같이 보내는 방법을 찾지 못했다.
	//대신 queue로 선언하려면 애초에 queue를 만들어서 똑같이 주소전달을 하면 된다. queue<int> &route
	bfs(1, graph, distance, { 0 }); 

	int max = *max_element(distance.begin(), distance.end()); //가장 큰 값을 찾아서 그와 같은 거리의 개수 ++
	for (auto a : distance)
		if (max == a)
			answer++;

	return answer;
}