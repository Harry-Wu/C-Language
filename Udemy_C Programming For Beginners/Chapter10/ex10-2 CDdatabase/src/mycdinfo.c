#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "mycdinfo.h"
#include "cs50.h"

//struct cd cd_collection[4]; //���ǰ��Ľṹ������ʱû�����������������ô˾�
//CD cd_collection[4];

static CD *get_cd_data();

/**
* ����������ֵ
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
	cd_collection[3].rating = 91;  //��ʹ��ö�������ֵҲ�ǿ��Ե�,����Ҫ��
}

void add_cd(char *filename)
{
	FILE *fp;  //�ļ���
	CD *tempcd = get_cd_data();
	errno_t err = fopen_s(&fp, filename, "ab");  //"rb"--�����Ʒ�ʽ���ļ�


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

//��cd_database�ļ��л�ȡcd��Ϣ����ʾ����Ļ��
void display_cdcollection(char *filename)
{
	FILE *fp;  //�ļ���
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--�����Ʒ�ʽ���ļ�
	//char line[MAXSTRLEN];  //������ʱ��Ŵ��ļ���ȡ����һ���ַ���
	int numRecords = number_of_records_in_db(filename);  //�����ж�����cd��¼
	long items_read = 0;  //�����ļ�����ʵ�ʶ�ȡ��cd��Ϣ��
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		cd_collection = realloc(cd_collection, sizeof(CD) * numRecords);		// alloc some memory
		items_read = fread(cd_collection, sizeof(CD), numRecords, fp);			// read all recs into memory, ͬʱ��ѯ�¶������ٸ�Ԫ��
		if (items_read != numRecords) {
			printf("Error: %d records in file but %d were read into memory", numRecords, items_read);
		}
		fclose(fp);
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
	for (int i = 0; i < items_read; i++)
	{
		printf("%d CD #%d: '%s' by %s has %d tracks. My rating = %d\n", sizeof(CD), i, (cd_collection + i)->name, (cd_collection + i)->artist, (cd_collection + i)->trackcount, (cd_collection + i)->rating);
	}
	printf("-----------------------------------------\n");
	cdarraylen = items_read;  //�����ڴ��е�cd��Ϣʱ���������
	//return items_read;
}

//��ȷ���޸��ĸ�cd��Ϣ,�ٰ���ʾ�����µ�cd��Ϣ
void modify_cd(char *filename)
{
	FILE *fp;  //�ļ���
	//long numbytes = 0;  //�����ļ��ж��ٸ��ֽ�
	//long items_read = 0;  //�����ļ�����ʵ�ʶ�ȡ��cd��Ϣ��
	int records_SN = 0;  //cd��Ϣ�����

	printf("Please input which cd data you want to modify:\n");
	records_SN = get_int();
	while ((records_SN < 0) || (records_SN > (number_of_records_in_db(filename) - 1)))
	{
		if (records_SN < 0)
		{
			printf("Don't input negative number!\nRetry:");
		} 
		else
		{
			printf("Can't fine cd serial number!\nRetry:");
		}
		records_SN = get_int();
	}
	CD *tempcd = get_cd_data();

	errno_t err = fopen_s(&fp, filename, "rb+");  //"b"--�����Ʒ�ʽ���ļ�
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened, will modify data.\n", filename);
		
		fseek(fp, sizeof(CD)*records_SN, SEEK_SET);  //���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ�õ��ļ���β
		fwrite(tempcd, sizeof(CD), 1, fp);
		fclose(fp);
		printf("Modified.\n");
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
}

int number_of_records_in_db(char *filename)
{
	FILE *fp;  //�ļ���
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--�����Ʒ�ʽ���ļ�
	long numbytes = 0;  //�����ļ��ж��ٸ��ֽ�
	long items_read = 0;  //�����ļ�����ʵ�ʶ�ȡ��cd��Ϣ��
	int numRecords = 0;  //�����ж�����cd��¼
	if (!err && fp != NULL)
	{
		//printf("File '%s' is opened.\n", filename);
		//printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ�õ��ļ���β
		numbytes = ftell(fp); //���ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
		numRecords = numbytes / sizeof(CD);
		//rewind(fp);  //���ļ�ָ������ָ��һ�����Ŀ�ͷ
		fclose(fp);
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}

	return numRecords;
}

//ע���Ǳ����ڴ��ж�ȡ��cd��Ϣ, ��cd_collection����Ϣ, ����cd_database.bin�ļ��ı���
//�ļ����Զ���
void backup_cd()
{
	FILE *fp;  //�ļ���
	int items_written = 0;  //����ʵ��д���ļ����е�cd��Ϣ��

	printf("Please give the name of the backup file:\n");
	char *filename = get_string();

	errno_t err = fopen_s(&fp, filename, "wb+");  //�����Ʒ�ʽ���ļ�����д
	long numbytes = 0;  //�����ļ��ж��ٸ��ֽ�
	//int numRecords = 0;

	if (!err && fp != NULL)
	{
		printf("Backup file '%s' is opened, will backup the cd data from memory.\n", filename);
		
		//numRecords = get_int();
		//fseek(fp, sizeof(CD)*numRecords, SEEK_SET);  //���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ�õ��ļ���β
		fwrite(cd_collection, sizeof(CD), cdarraylen, fp);
		fclose(fp);
		printf("Backup Done.\n");
	}
	else
	{
		printf("Can not read file:%s!\n", filename);
	}
}

//�����Ƹ�ʽ��ȡ�ļ���Ϣ
void read_binfile(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--�����Ʒ�ʽ���ļ�
	char line[MAXSTRLEN];  //������ʱ��Ŵ��ļ���ȡ����һ���ַ���
	int numlines = 0;  //�����ļ��ж���������
	long numbytes = 0;  //�����ļ��ж��ٸ��ֽ�
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ�õ��ļ���β
		numbytes = ftell(fp); //���ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
		rewind(fp);  //���ļ�ָ������ָ��һ�����Ŀ�ͷ
		char *buffer = (char *)malloc(numbytes);
		long items_read = fread(buffer, 1, numbytes, fp);		//��ѯ�¶������ٸ�Ԫ��
																//ע�������fgetsȥ�����ж����е�ʱ���ļ�ָ��fpһ��Ҫ�ƻص��ļ���ͷ��
																//��һ�ַ����Ǳ���buffer[],��ѯ'\n'�ĸ�����֪���ж�������
		rewind(fp);
		while (fgets(line, sizeof(line), fp) != 0)
		{
			numlines++;  //ֻҪ����һ�о�+1
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
	tempcd.rating = temp_cd_rating;

	return &tempcd;
}

