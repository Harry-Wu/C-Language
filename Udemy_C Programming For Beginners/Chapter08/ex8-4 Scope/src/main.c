/*****************************************************************************
@File name:
@Description: 
@	static������static������ʹ��. ��̬����Ҫ����ʹ��,��̬����(�ڲ�����)�õĸ���
@	ע��,mystringutils.c�ĺ�������Ҳ������mycdinfo.h��, ��������.c�ļ�ֻ��Ҫ����mycdinfo.h����.
@	������.c�ļ���Ҫʹ��mystringutils.c�еĺ���ʱ,IDE����������ȥ����(mystringutils.cҪ�ŵ�������)
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
	V1.0: static������static������ʹ��

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "mycdinfo.h"
#include "cs50.h"
//#include "mystringutils.h"

// Global scope
char *b;
char teststring[] = "Hello";
int num = 10;

void addnumbers() {
	static int x = 0;
	int y = 0;
	x++;
	y++;
	printf("In addnumbers() x=%d, y=%d\n", x, y);
}

void globalnum() {
	printf("In globalnum, num is %d\n", num);
}

void localnum() {
	int num;
	num = 100;
	printf("In localnum, num is %d\n", num);
}



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	int i;
	int stringpos = -1;
	CD thiscd;

	create_cdcollection();
	for (int i = 0; i < 4; i++)  //��ӡ��4���ṹ��������������
	{
		thiscd = cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks. My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
	printf("Enum, use head file\n");

	//���Ա��������÷�Χ
	printf("Please input any string:\n");
	b = get_string();
	i = strlen(b);
	printf("b=%s; i=%d\n", b, i);
	/*// --- This can't be run as long as searchstring() is a static function
	stringpos = search_str(b, teststring);
	if(stringpos > -1){
	printf( "'%s' found in '%s' at index #%d\n", teststring, b, stringpos);
	}else{
	printf( "'%s' not found in '%s'\n", teststring, b);
	}
	*/
	search_str2(b, teststring);
	localnum();
	globalnum();
	addnumbers();
	addnumbers();
	addnumbers();
	return 0;
}
