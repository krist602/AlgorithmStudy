#include <iostream>
#include <cmath>

using namespace std;

//소수 구하기
bool IsPrime(int num)
{
	if (num < 2)
		return false;

	int root = (int)sqrt(num); //sqrt는 <cmath>라이브러리에 속한다.

	for (int i = 0; i <= root; i++)
		if (num % i == 0)
			return false;

	return true;
}

//제곱근까지만 계산해주면 되는 이유는, i가 커질 수록 몫이 작아지는데, 그 경계지점이 제곱근이다.