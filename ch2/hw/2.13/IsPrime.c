/**
  compile error:

IsPrime.c:(.text+0xd): undefined reference to `sqrt'
collect2: error: ld returned 1 exit status

  conquer it by cmd:
gcc -std=c99 IsPrime.c -o prime -L /path/to/libs -lm

 reference:
http://stackoverflow.com/questions/5248919/c-undefined-reference-to-sqrt-or-other-mathematical-functions

 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int IsPrime(const int x)
{
	int y =(int) sqrt((double)x);
	int i;
	for (i=y; x%i != 0; i--)
		;	

	return i == 1;
}



int main(int argc, char *grgv[])
{
	int n = atoi(grgv[1]);

	printf("%d\n", IsPrime(n));

	return 0;
}
	




