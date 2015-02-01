


/**
 * Efficient exponentiation
 *
 * T(N) = O(log N)
 */

#include <stdio.h>

int Pow (const int X, unsigned int N)
{
	if (N == 0)
		return 1;
	else if (N == 1)
		return X;
	else if (N >> 1 == 0)
		return Pow(X*X, N/2);
	else 
		return Pow(X*X, N/2) * X;
}


int main()
{
	int a , b;
	printf("Enter two interges: it will print out a^b:\n");
	scanf("%d%d", &a, &b);
	printf("%d\n", Pow(a, b) );

	return 0;
}









/**
 * Efficient exponentiation
 *
 * T(N) = O(log N)
 */








