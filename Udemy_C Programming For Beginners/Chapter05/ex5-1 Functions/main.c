
/*****************************************************************************
@File name:
@Description: 测试函数的使用， 注意参数的传递
@Author: Harry Wu
@Version: V1.0
@Date: 2017-03-31
@History:
	V1.0:
*****************************************************************************/

#include <stdio.h>

void sayHello() 
{
	printf("Hello\n");
}

void greet(char aName[]) 
{
	printf("Hello %s\n", aName);
}

int add(int num1, int num2) 
{
	num1 = num1 + num2;
	return num1;
}

double divide1(int num1, int num2) 
{
	return num1 / num2;
}

double divide2(double num1, double num2) 
{
	return num1 / num2;
}

int main(int argc, char **argv) 
{
	double result;
	int n1;
	int n2;
	int total;

	n1 = 10;
	n2 = 3;

	sayHello();
	greet("Fred");

	total = add(n1, n2);
	printf("%d + %d = %d\n", n1, n2, total);
	result = divide1(100, 3);
	printf("Result of 100/3 with divide1 = %f\n", result);
	result = divide2(100, 3);
	printf("Result of 100/3 with divide2 = %f\n", result);
	return 0;
}
