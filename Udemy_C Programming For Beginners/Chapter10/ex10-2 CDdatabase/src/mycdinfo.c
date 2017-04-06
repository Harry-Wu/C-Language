#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "mycdinfo.h"
#include "cs50.h"

//struct cd cd_collection[4]; //如果前面的结构体声明时没有声明变量，可以用此句
//CD cd_collection[4];

static CD *get_cd_data();

/**
* 给变量赋初值
*/
void create_cdcollection() {
	cd_collection = (CD *)malloc(sizeof(CD) * 4);
	cdarraylen = 4;
	//CD thiscd = cd_collection[0];
	//strcpy_s(thiscd.name, 50, "Great Hits");
	//printf("tEST");
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

int number_of_records_in_db(char *filename)
{
	FILE *fp;  //文件流
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--二进制方式打开文件
	long numbytes = 0;  //保存文件有多少个字节
	long items_read = 0;  //保存文件流中实际读取的cd信息数
	int numRecords = 0;
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //用于二进制方式打开的文件,移动文件读写指针位置到文件结尾
		numbytes = ftell(fp); //到文件位置指针当前位置相对于文件首的偏移字节数
		numRecords = numbytes / sizeof(CD);
		//rewind(fp);  //将文件指针重新指向一个流的开头
		fclose(fp);
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
	
	return numRecords;
}

void add_cd(char *filename)
{
	FILE *fp;  //文件流
	CD *tempcd = get_cd_data();
	errno_t err = fopen_s(&fp, filename, "ab");  //"rb"--二进制方式打开文件
												
	
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened, will append data.\n", filename);
		fwrite(tempcd, sizeof(CD), 1, fp);
		fclose(fp);
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
}


//从cd_database文件中获取cd信息并显示到屏幕上
void display_cdcollection(char *filename)
{
	FILE *fp;  //文件流
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--二进制方式打开文件
	//char line[MAXSTRLEN];  //用于临时存放从文件获取到的一行字符串
	int numRecords = number_of_records_in_db(filename);  //保存有多少项cd记录
	long items_read = 0;  //保存文件流中实际读取的cd信息数
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		cd_collection = realloc(cd_collection, sizeof(CD) * numRecords);		// alloc some memory
		items_read = fread(cd_collection, sizeof(CD), numRecords, fp);			// read all recs into memory, 同时查询下读到多少个元素
		if (items_read != numRecords) {
			printf("Error: %d records in file but %d were read into memory", numRecords, items_read);
		}
		fclose(fp);
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
	for (int i = 0; i < items_read ; i++)
	{
		printf("%d CD #%d: '%s' by %s has %d tracks. My rating = %d\n", sizeof(CD), i, (cd_collection+i)->name, (cd_collection + i)->artist, (cd_collection + i)->trackcount, (cd_collection + i)->rating);
	}
	cdarraylen = items_read;  //备份内存中的cd信息时用这个数字
	//return items_read;
}

//二进制格式读取文件信息
void read_binfile(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--二进制方式打开文件
	char line[MAXSTRLEN];  //用于临时存放从文件获取到的一行字符串
	int numlines = 0;  //保存文件有多少行文字
	long numbytes = 0;  //保存文件有多少个字节
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //用于二进制方式打开的文件,移动文件读写指针位置到文件结尾
		numbytes = ftell(fp); //到文件位置指针当前位置相对于文件首的偏移字节数
		rewind(fp);  //将文件指针重新指向一个流的开头
		char *buffer = (char *)malloc(numbytes);
		long items_read = fread(buffer, 1, numbytes, fp);		//查询下读到多少个元素
																//注意如果用fgets去计算有多少行的时候，文件指针fp一定要移回到文件开头处
																//另一种方法是遍历buffer[],查询'\n'的个数就知道有多少行了
		rewind(fp);
		while (fgets(line, sizeof(line), fp) != 0)
		{
			numlines++;  //只要读完一行就+1
		}
		fclose(fp);
		printf("number of lines was %d with %d chars (%d items read).\n", numlines, numbytes, items_read);
		free(buffer);
	}
	else
	{
		printf("Can not open file:%s!\n", filename);
	}
	printf("The fopen return address is %p\n", fp);
	printf("\n-----------------------------------------\n");
}

static void init_tempcd(CD cd) {
	// EXERCISE: How else might I assign an 'empty' string?
	// Hint: Look at 04_ReturnStrings in Step 07
	strcpy_s(cd.name, 50, "");
	strcpy_s(cd.artist, 50, "");
	cd.trackcount = 0;
	cd.rating = 0;
}

static CD *get_cd_data()
{
	//CD tempcd;
	init_tempcd(tempcd);
	char *temp_cd_name, *temp_cd_artist;
	int temp_cd_tracks, temp_cd_rating;
	printf("Enter CD Name:\n");
	temp_cd_name = get_string();
	printf("Enter Artist:\n");
	temp_cd_artist = get_string();
	printf("Enter Number of tracks:\n");
	temp_cd_tracks = get_int();
	printf("Enter Rating:\n");
	temp_cd_rating = get_int();
	if (temp_cd_tracks == 0)
	{
		printf("'%d' is Invalid number for cd tracks. 1 will be used\n", temp_cd_tracks);
		temp_cd_tracks = 1;
	}
	if (temp_cd_rating == 0) 
	{
		printf("'%d' is Invalid number for cd tracks. 1 will be used\n", temp_cd_rating);
		temp_cd_rating = 1;
	}
	strcpy_s(tempcd.name, 50, temp_cd_name);
	strcpy_s(tempcd.artist, 50, temp_cd_artist);
	tempcd.trackcount = temp_cd_tracks;
	tempcd.rating= temp_cd_rating;

	return &tempcd;
}

