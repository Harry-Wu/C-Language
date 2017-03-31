//函数的命名规范，个人倾向于首字母大写
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

#define TAXRATE 0.174


double Cal_Tax(double x)
{
	return x*TAXRATE;
}

double Cal_GrandTotal(double x)
{
	double grand_total;
	grand_total = x * (1 + TAXRATE);
	return grand_total;
}

int main(int argc, char** argv)
{
	double subtotal = 200;
	printf("The TAXRATE is %.3f.\n", TAXRATE);
	printf("The tax on %f is %f, so the grand total is %f.\n\n", subtotal, Cal_Tax(subtotal), Cal_GrandTotal(subtotal));
	printf("The tax on %f is %f, so the grand total is %f.\n\n", 101.0, Cal_Tax(101), Cal_GrandTotal(102));


	
	return 0;
}