//Baekjoon > 11404 > �÷��̵�
//https://www.acmicpc.net/problem/11404

	//�÷��̵��� ���ִµ��� ���� Ǫ�µ� �ణ�� �ð��� �ɸ� ����
	//	1. bus[i][j] == 0 �̶�� 0�� �� �۱� ������ 0�� ���� �ٲ��� �ʾҴ�.
	//	2. ������� �������� ���� ������ ���ٰ� ������ �� ���� ���� 0�� �Է�
	//	3. ���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ִ�.
	//	4. �׳� �ּ��޸� ��� ���ǹ��� �ϳ��� �� �߰��ߴٰ� ���� �ȴ�.

#include <iostream>
#include <vector>

using namespace std;

void floyd(vector<vector<int>>& bus, int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (bus[i][k] && bus[k][j]) //�ϳ��� ���̶� ������ �ȵȴ�.
				{
					if (bus[i][j] > bus[i][k] + bus[k][j])
						bus[i][j] = bus[i][k] + bus[k][j];
					else if (!bus[i][j]) //bus[i][j] == 0 �̶�� ������ ���� �޾��ش�.
						bus[i][j] = bus[i][k] + bus[k][j];
				}
			}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> bus(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		int s, e, p;
		cin >> s >> e >> p;
		if (!bus[s][e]) //���� 0�̶�� ������ �޾��ش�.
			bus[s][e] = p;
		else //�̹� ������ �ִ� ����� �� ���� ���� �Է����ش�.
			bus[s][e] > p ? bus[s][e] = p : bus[s][e];
	}

	floyd(bus, n);

	for (int i = 1; i <= n; i++)
		bus[i][i] = 0; //��� ���ÿ� ���� ���ð� ���� ��� 0���� �ʱ�ȭ���ش�.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << bus[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
