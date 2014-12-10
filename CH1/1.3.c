#include <stdio.h>


void PrintDigit(int x)
{
	printf("%d", x);
}


void PrintOut(int n)
{
	if (n >= 10)
		PrintOut(n/10);
	PrintDigit(n%10);
}



int main()
{
	int n;
	scanf("%d", &n);
	PrintOut(n);
	printf("\n");
	return 0;
}
