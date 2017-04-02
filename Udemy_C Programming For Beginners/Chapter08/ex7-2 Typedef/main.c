/*****************************************************************************
@File name:
@Description: 结构体变量的使用, typedef的使用
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: 结构体变量赋值与取值
V1.1: typedef直接放到和结构体声明一起
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

//typedef struct cd CD;  //用typedef将结构体cd声明为一种数据类型别名，以后可以当int那样使用
typedef char STR50[50];
//此声明声明了拥有4个成员的结构体
//这个结构体的标签是cd
//可以在结尾声明一个结构体变量cd_collection[4]
typedef struct  //这里cd可加可不加，用typedef是创建了新类型CD
{
	STR50 name;  //这种使用typedef的方式注意下，数组的尺寸也不用再定义了
	STR50 artist;
	int trackcount;
	short rating;
}CD;

//struct cd cd_collection[4]; //如果前面的结构体声明时没有声明变量，可以用此句
CD cd_collection[4];

							//给变量赋初值
void create_cdcollection() {
	strcpy_s(cd_collection[0].name, 50, "Great Hits");
	strcpy_s(cd_collection[0].artist, 50, "Polly Darton");
	cd_collection[0].trackcount = 20;
	cd_collection[0].rating = 10;

	strcpy_s(cd_collection[1].name, 50, "Mega Songs");
	strcpy_s(cd_collection[1].artist, 50, "Lady Googoo");
	cd_collection[1].trackcount = 18;
	cd_collection[1].rating = 7;

	strcpy_s(cd_collection[2].name, 50, "The Best Ones");
	strcpy_s(cd_collection[2].artist, 50, "The Warthogs");
	cd_collection[2].trackcount = 24;
	cd_collection[2].rating = 4;

	strcpy_s(cd_collection[3].name, 50, "Songs From The Shows");
	strcpy_s(cd_collection[3].artist, 50, "The Singing Swingers");
	cd_collection[3].trackcount = 22;
	cd_collection[3].rating = 9;
}

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
	printf("Typedef\n");
	return 0;
}
