#include <string.h>
#include "stack.h"

#define SIZE 100

int Level(const char x)
{
	switch(x)
	{
		case '+':
		case '-':
			return 0;
			break;
		case '*':
		case '/':
			return 1;
			break;
		default:
			// (, )	
			return 2;
			break;
	}
}

int Priority(const char x, const char y)
{
	int ix = Level(x);
	int iy = Level(y);
	return ix-iy;
}

int main()
{
	char str[10];
	memset(str, 0, sizeof(str));
	Stack S = Create(SIZE);
	while (scanf("%s", str) != EOF)
	{
		int a, b;	
		if (strlen(str) > 1)
			printf("%s ", str); // numbers 
		else
		{
			char c = str[0];
			if (c == '(')
				Push(c, S);
			else if (c == ')')
			{
				char x;
				while (!IsEmpty(S)) 
				{
					x = TopAndPop(S);
					if (x == '(')
						break;
					printf ("%c ", x);
				}	
			}
			else if (c >= '0' && c <= '9')
			{
				printf("%c ", c);
			}
			else
			{
				// +, -, *, /
				while (!IsEmpty(S))
				{
					char x = Top(S);
					if (x == '(')
						break;
					else if (Priority(c, x) <= 0)
					{
						printf("%c ", x);
						Pop(S); 
					}
					else
						break; 
				}
				Push(c, S);
			}
		}
		getchar();
	}

	while (!IsEmpty(S))
	{
		printf("%c ", TopAndPop(S));
	}
	puts("");
	Dispose(S);
	
	return 0;
}	
