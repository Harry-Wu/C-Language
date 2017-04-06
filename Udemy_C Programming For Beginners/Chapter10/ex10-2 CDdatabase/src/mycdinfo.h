#ifndef _MYCDINFO_H_
#define _MYCDINFO_H_
#define MAXSTRLEN 500

enum score  //枚举的默认值是0,1,2,3,4
{
	Terrible=1, Bad=2, Average=3, Good=4, Excellent=5
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

CD *cd_collection;
CD tempcd;
/**
* 给cd信息赋初值
* 函数声明前加的这些说明,在函数调用的地方,鼠标放在上面会看到
*/
void create_cdcollection();
void display_cdcollection(char *filename);
int number_of_records_in_db(char *);
//void backup_cd(char*);
int cdarraylen;
void add_cd(char*);
//void modify_cd(char*);

void read_binfile(char *filename);


#endif // !_MYCDINFO_H_
