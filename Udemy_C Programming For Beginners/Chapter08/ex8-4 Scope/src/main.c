/*****************************************************************************
@File name:
@Description: 
@	static变量和static函数的使用. 静态变量要谨慎使用,静态函数(内部函数)用的更多
@	注意,mystringutils.c的函数声明也放在了mycdinfo.h中, 这样其他.c文件只需要包含mycdinfo.h即可.
@	当其他.c文件需要使用mystringutils.c中的函数时,IDE的链接器会去查找(mystringutils.c要放到工程中)
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
	V1.0: static变量和static函数的使用

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
	for (int i = 0; i < 4; i++)  //打印出4个结构体变量数组的内容
	{
		thiscd = cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks. My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
	printf("Enum, use head file\n");

	//测试变量的作用范围
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
