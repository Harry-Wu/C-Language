//�������������ͣ������float����
#include <stdio.h>

int main(int argc, char** argv)
{
	double subtotal = 200;
	double tax, grandtotal;  //subtotalΪ����˰�۸�
	double taxrate = 0.174;
	tax = subtotal * taxrate; //��˰
	grandtotal = subtotal + tax;  //��˰�۸�
	//printf("pettycash=%.2f\n", pettycash);
	//pettycash = 10.5 / 11;
	printf("The tax on %f is %f, so the grand total is %f.\n", subtotal, tax, grandtotal);
	//printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}