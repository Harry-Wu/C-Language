#include <stdio.h>
#include <string.h>
#include "mycdinfo.h"

//struct cd cd_collection[4]; //如果前面的结构体声明时没有声明变量，可以用此句
CD cd_collection[4];

//给变量赋初值
void create_cdcollection() {
	strcpy_s(cd_collection[0].name, 50, "Great Hits");
	strcpy_s(cd_collection[0].artist, 50, "Polly Darton");
	cd_collection[0].trackcount = 20;
	cd_collection[0].rating = Excellent;

	strcpy_s(cd_collection[1].name, 50, "Mega Songs");
	strcpy_s(cd_collection[1].artist, 50, "Lady Googoo");
	cd_collection[1].trackcount = 18;
	cd_collection[1].rating = Good;

	strcpy_s(cd_collection[2].name, 50, "The Best Ones");
	strcpy_s(cd_collection[2].artist, 50, "The Warthogs");
	cd_collection[2].trackcount = 24;
	cd_collection[2].rating = Bad;

	strcpy_s(cd_collection[3].name, 50, "Songs From The Shows");
	strcpy_s(cd_collection[3].artist, 50, "The Singing Swingers");
	cd_collection[3].trackcount = 22;
	cd_collection[3].rating = 91;  //不使用枚举里面的值也是可以的,但不要用
}

