//Programmers > �׷��� > ����
//https://programmers.co.kr/learn/courses/30/lessons/49191


	//Floyd Warshall �˰��� �̿�
	//	��� ��忡�� �ٸ� ��� ������ �ּ� ��� ��� ���� �˰���
	//4�� 3���� �̰�ٸ� [4][3]�� 1 �Է�.
	//���� Floyd Warshall�� �̿��ؼ� 4�� 3���� �̰��, 3�� 5���� �̰�ٸ�, [4][5]���� 1 �Է�.
	//�ݺ��ؼ� Ȯ���� �̱� ������� �� �� �ְ� ǥ���Ѵ�.
	//�׷��ٸ�, [i][j]�� [j][i]�� Ž���ؼ� �� �� �ϳ��� ���̶� 1�� �ִٸ�, [i][j]������ �ºΰ� ��������.
	

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> verse(n + 1, vector<bool>(n + 1, 0)); //���� 0���� �ʱ�ȭ

	for (int i = 0; i < results.size(); i++)
		verse[results[i][0]][results[i][1]] = 1; //�̰�ٸ� 1�� ǥ��

	for (int v = 1; v <= n; v++) // v = via. �����ϴ� ���
		for (int s = 1; s <= n; s++) // s = start. ���� ��ġ
			for (int e = 1; e <= n; e++) // e = end. ��ǥ ��ġ
				if (verse[s][v] && verse[v][e]) //s�� v�� �̱��, v�� e�� �̰�ٸ�, s�� e�� �̰�� ������ 1�� ǥ��
					verse[s][e] = 1;

	for (int i = 1; i <= n; i++)
	{
		int WorL = 0; //���а� ������ ����� ���� ����.
		for (int j = 1; j <= n; j++)
			if (verse[i][j] || verse[j][i]) //[i][j]�� [j][i] �߿� �ϳ��� 1�� �ִٸ� ���а� �������� ������
				WorL++; //++

		if (WorL == n - 1) //���и� ���� ����� ��ü �ο� - �ڱ� �ڽ� �̶��
			answer++; //answer++
	}

	return answer;
}