//�����ʹ����������
#include <stdio.h>

int main(int argc, char** argv)
{
	int subtotal=200, tax, grandtotal;  //subtotalΪ����˰�۸�
	double taxrate = 0.174;
	tax = subtotal * taxrate; //��˰
	grandtotal = subtotal + tax;  //��˰�۸�
	//printf("pettycash=%.2f\n", pettycash);
	//pettycash = 10.5 / 11;
	printf("The tax on %d is %d, so the grand total is %d.\n", subtotal, tax, grandtotal);
	//printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}