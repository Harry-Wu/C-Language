/*****************************************************************************
@File name:
@Description: �ṹ�������ʹ��
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: �ṹ�������ֵ��ȡֵ
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

//������������ӵ��4����Ա�Ľṹ��
//����ṹ��ı�ǩ��cd
//�����ڽ�β����һ���ṹ�����cd_collection[4]
struct cd
{
	char name[50];
	char artist[50];
	int trackcount;
	short rating;
};

struct cd cd_collection[4]; //���ǰ��Ľṹ������ʱû�����������������ô˾�

//����������ֵ
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
	struct cd thiscd;
	create_cdcollection();
	for (int i = 0; i < 4; i++)  //��ӡ��4���ṹ��������������
	{
		thiscd = cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks. My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
}