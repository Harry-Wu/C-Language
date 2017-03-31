

/*****************************************************************************
@File name:
@Description:
@Author: Harry Wu
@Version: V1.0
@Date: 2017-xx-xx
@History:
	V1.0: 测试scanf的功能
*****************************************************************************/



#include <stdio.h>
int main(int argc, char **argv[])
{
	int n;
	printf("Hello World\n");
	
	puts("How many bottles will there be?");  //puts会自动在字符串后面加换行符
	scanf("%d", &n);
	if (n<1)
	{
		printf("Sorry, that makes no sense.\n");
		return 1;
	}
	for (int i = n; i > 0; i--)
	{
		printf("There are %d bottle(s) standing on the %s.\n", i, "wall");
		printf("%d bottle(s) of beer,\n", i);
		printf("Take one down, pass it around,\n");

		if (i<=1)
		{
			printf("There is no beer on the wall.\n\n", i - 1);
		}
		else
		{
			printf("%d bottle(s) of beer on the wall.\n\n", i - 1);
		}

	}

	return 0;
}