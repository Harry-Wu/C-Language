#include <stdio.h>

void main(int argc, char **argv[])
{
	printf("Hello World!\n");
	int i;
	for (i = 0; i < argc; i++)
	{
		printf("Hello World! argc=%d arg %d is %s\n", argc, i, argv[i]);
		//		printf()
	}
}
