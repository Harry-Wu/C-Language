#include <stdio.h>

void showPrefixAndPostfixOps() {
	int num1, num2;
	printf("\nPrefix and Postfix operators... (num1 = 10)");
	num1 = 10;
	num2 = num1++; // num2 = 10, num1 = 11
	printf("\nnum2 = num1++; so num2 = %d and num1 = %d", num2, num1);

	num1 = 10;
	num2 = ++num1; // num2 = 11, num1 = 11
	printf("\nnum2 = ++num1; so num2 = %d and num1 = %d\n", num2, num1);
}

int main(int argc, char **argv) 
{
	int a = 10;
	int b = 2;
	printf("\n\nHere are examples of some compound assignment operators...\n");
	a = a + b;
	printf("\na + b  : %d\n", a);
	a = 10;
	a += b;
	printf("a += b  : %d\n", a);
	a = 10;
	a = a - b;
	printf("a - b  : %d\n", a);
	a = 10;
	a -= b;
	printf("a -= b  : %d\n", a);
	a = 10;
	a = a * b;
	printf("a * b  : %d\n", a);
	a = 10;
	a *= b;
	printf("a *= b  : %d\n", a);
	a = 10;
	a = a / b;
	printf("a/b  : %d\n", a);
	a = 10;
	a /= b;
	printf("a /= b  : %d\n", a);
	a = 10;
	a++;
	printf("a++ : %d\n", a);
	a = 10;
	a--;
	printf("a-- : %d\n", a);

	showPrefixAndPostfixOps();
	return(0);
}
