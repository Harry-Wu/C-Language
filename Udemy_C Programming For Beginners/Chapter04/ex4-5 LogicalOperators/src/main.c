
/*****************************************************************************
@File name:
@Description: 测试逻辑运算符的功能
@Author: Harry Wu
@Version: V1.1
@Date: 2017-03-31
@History:
	V1.0: 试验逻辑运算符
	V1.1: 加上cs50的格式化输入函数
*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "cs50.h"

int main(int argc, char **argv)
{
	int age;
	int number_of_children;
	double salary;

	/*age = 25;
	number_of_children = 1;
	salary = 20000.00;*/
	printf("Please input your age:\n");
	age = GetInt();
	printf("Please input how many children you have:\n");
	number_of_children = GetInt();
	printf("Please input your salary:\n");
	salary = GetDouble();

	if ((age <= 30) && (salary >= 30000)) {
		printf("You are a rich young person\n");
	}
	else {
		printf("You are not a rich young person\n");
	}

	if ((age <= 30) || (salary >= 30000)) {
		printf("You are either rich or young or both\n");
	}
	else {
		printf("You are neither rich nor young\n");
	}

	if ((age <= 30) && (salary >= 30000) && (number_of_children != 0)) {
		printf("You are a rich young parent\n");
	}
	else {
		printf("You are not a rich young parent\n");
	}

	printf("按任意键继续……");  //用来防止控制台程序一闪而过
	getchar();

	return 0;

	
}
