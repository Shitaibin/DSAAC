#include <stdio.h>

int main()
{	
	
	FILE * in = fopen("1.in", "r");
	char line[100];
	fgets (line, sizeof(line), in);
	puts(line);

	return 0;

}
