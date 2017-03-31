#include <stdio.h>

int main(int argc, char** argv)
{
	double pettycash = 10.5;
	double grandtotal = 500.50;
	printf("pettycash=%.2f\n", pettycash);
	pettycash = 10.5 / 11;
	printf("pettycash=%.2f\n", pettycash);
	printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}