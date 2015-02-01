#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void PrintContent(char *fname)
{
	FILE *fp = fopen(fname, "r");
	if (fp == NULL)
	{
		puts("Open failed");
		printf("errno is %d\n", errno);
		return;
	}
	
	char line[100];
	
	while(fgets (line, sizeof(line), fp) != NULL)
	{
		char* pos = strstr(line, "#include");
		if (pos != 0) 
		{
			// only recognize the header file included by angle brackets
			// and open the file in the current directory, although i 
			// konw it's not correct(cause these file are library 
			// files). I just to test this recurrsive function, so i
			// suppose those files are in the current directory
	
			char * p1 = strchr(line, '<');
			if (p1 > 0) 
			{
				char *p2 = strchr(p1, '>');	
				char *fn = (char *) malloc(sizeof(char) * (p2-p1+5));
				strncpy(fn, p1+1, p2-1-p1);
				PrintContent(fn); // recursive
			// 	puts(fn); // this line for test
			}	
		}else {
			printf("%s", line);			
		}
	}	
}


int main()
{

	char * inf = (char *)malloc(sizeof(char) * 10);
	scanf("%s", inf);
	PrintContent(inf);
	puts("");
	return 0;

}



