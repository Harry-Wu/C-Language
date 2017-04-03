#ifndef _MYCDINFO_H_
#define _MYCDINFO_H_


enum score  //枚举的默认值是0,1,2,3,4
{
	Terrible, Bad, Average, Good, Excellent
};

typedef char STR50[50];
//此声明声明了拥有4个成员的结构体
//这个结构体的标签是cd
//可以在结尾声明一个结构体变量cd_collection[4]
typedef struct  //这里cd可加可不加，用typedef是创建了新类型CD
{
	STR50 name;  //这种使用typedef的方式注意下，数组的尺寸也不用再定义了
	STR50 artist;
	int trackcount;
	enum score rating;
}CD;

extern CD cd_collection[4];
void create_cdcollection();

#endif // !_MYCDINFO_H_
