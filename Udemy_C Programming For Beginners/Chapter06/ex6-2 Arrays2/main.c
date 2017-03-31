
/*****************************************************************************
@File name:
@Description: 初始化数组时，不用定义数组大小，C语言会自动分配
@Author: Harry Wu
@Version: V1.0
@Date: 2017-xx-xx
@History:
	V1.0:
*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int intarray[] = {1, 11, 21, 31, 41};
double doublearray[] = { 2.1, 2.2, 2.3, 2.4, 2.5 };
char chararray[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char chararray2[] = "world";

int main(int argc, char** argv)
{
	/*intarry[0] = 1;
	intarray[1] = 11;
	intarray[2] = 21;
	intarray[3] = 31;
	intarray[4] = 41;*/

	for (int i = 0; i < 5; i++) {
		intarray[i] = ((i + 1) * 100); // note use of parentheses here!
	}

	printf("--- for loop ---\n");
	for (int i = 0; i < 5; i++)
	{
		printf("The integer at intarray[%d] is:%d\n", i, intarray[i]);
	}

	printf("--- while loop (i = 0) ---\n");
	int i = 0;
	while (i<5)
	{
		printf("The integer at intarray[%d] is:%d\n", i, intarray[i]);
		i++;
	}

	printf("--- do..while loop (i = 0) ---\n");
	i = 0;
	do 
	{
		printf("The integer at intarray[%d] is:%d\n", i, intarray[i]);
		i++;
	} while (i<5);

	printf("--- print doublearray ---\n");
	for (i = 0; i < (sizeof(doublearray) / sizeof(doublearray[0])); i++)
	{
		printf("%.2f\t", doublearray[i]);
	}
	
	printf("\n");
	printf("--- print chararray ---\n");
	printf("%s, ", chararray);
	printf("%s\n", chararray2);



}