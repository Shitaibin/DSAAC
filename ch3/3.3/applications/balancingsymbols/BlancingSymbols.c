
#include "../stack.h"
#include <string.h>

#define SIZE 1000

int main()
{
	Stack S = Create(SIZE);
	char c;
	char *line = malloc(sizeof(char) * SIZE);
	while (gets(line))
	{
		char *buf = line;
		while(sscanf(buf, "%c", &c) != EOF)
		{
			buf++;	
			if (c == '(' || c == '{' || c == '[')
				Push(c, S);
			else if (c == ')' || c == '}' || c ==']')
			{
				if (IsEmpty(S))
				{
					Error("Stack is empty!!!");
					exit(1);
				}	
				else
				{
					char y;
					if (c == ')')
						y = '(';	
					else if (c == '}')
						y = '{';
					else
						y = '[';
	
					char x = TopAndPop(S);
					if (x != y)
					{	
						printf("Not match! %c - %c\n", x, y);
						exit(1);
					}
				}	
			}
		}
	}

	if ( !IsEmpty(S) )
	{	
		Error("Stack is not empty!!!");
		exit(1);
	}

	Dispose(S);
	free(line);
	return 0;
}
