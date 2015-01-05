#include <string.h>
#include "stack.h"

#define SIZE 1000


int main()
{
	char str[10];
	memset(str, 0, sizeof(str));
	Stack S = Create(SIZE);
	while (scanf("%s", str) != EOF)
	{
		int a, b;	
		if (strlen(str) == 1)
		{
			char c;
			c = str[0];
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
					Push(c-'0', S);
					break;	
			}
		}
		else
		{
			Push(atoi(str), S);
		}
		getchar();
	}

	int ans = TopAndPop(S);
	printf("%d\n", ans);

	Dispose(S);
	
	return 0;
}	
