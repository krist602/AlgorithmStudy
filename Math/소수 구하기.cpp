#include <iostream>
#include <cmath>

using namespace std;

//�Ҽ� ���ϱ�
bool IsPrime(int num)
{
	if (num < 2)
		return false;

	int root = (int)sqrt(num); //sqrt�� <cmath>���̺귯���� ���Ѵ�.

	for (int i = 0; i <= root; i++)
		if (num % i == 0)
			return false;

	return true;
}

//�����ٱ����� ������ָ� �Ǵ� ������, i�� Ŀ�� ���� ���� �۾����µ�, �� ��������� �������̴�.