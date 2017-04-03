/*****************************************************************************
@File name:
@Description: 枚举类型的使用
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: 结构体变量赋值与取值
V1.1: 把添cd信息的函数放到单独的c文件,然后包含到main.c文件中

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "mycdinfo.h"



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//struct cd thiscd;
	CD thiscd;
	create_cdcollection();
	for (int i = 0; i < 4; i++)  //打印出4个结构体变量数组的内容
	{
		thiscd = cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks. My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
	printf("Enum, use head file\n");
	return 0;
}
