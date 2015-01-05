#include "stack.h"

#define SIZE 1000

int ToInt(char c)
{
	return c-'0';
}

int main()
{
	char c;
	Stack S = Create(SIZE);
	while (scanf("%c", &c) != EOF)
	{
		int a, b;	
		switch (c)
		{
			case '+':
				b = TopAndPop(S);
				a = TopAndPop(S);
				Push(a+b, S);
				break;
			case '-':
				 b = TopAndPop(S);
				 a = TopAndPop(S);
				Push(a-b, S);
				break;
			case '*':
				 b = TopAndPop(S);
				 a = TopAndPop(S);
				Push(a*b, S);
				break;
			case '/':
				 b = TopAndPop(S);
				 a = TopAndPop(S);
				Push(a/b, S);
				break;
			default:
				Push(ToInt(c), S);
				break;	
		}
		getchar();
	}

	int ans = TopAndPop(S);
	printf("%d\n", ans);

	Dispose(S);
	
	return 0;
}	
