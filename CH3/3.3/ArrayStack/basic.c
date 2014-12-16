#include "basic.h"

void FatalError(const char * str)
{
	printf("FatalError: %s\n", str);
}

void Error(const char *str)
{
	printf("Error: %s\n", str);
}
