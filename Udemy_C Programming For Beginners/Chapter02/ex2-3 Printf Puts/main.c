#include <stdio.h>
int main(int argc, char **argv[])
{
	printf("Hello World\n");
	puts("Hello, How are you?");  //puts会自动在字符串后面加换行符
	for (int i = 5; i > 0; i--)
	{
		printf("There are %d bottle(s) standing on the %s.\n", i, "wall");
		printf("%d bottle(s) of beer,\n", i);
		printf("Take one down, pass it around,\n");
		printf("%d bottle(s) of beer on the wall.\n\n", i - 1);

	}
	
	return 0;
}