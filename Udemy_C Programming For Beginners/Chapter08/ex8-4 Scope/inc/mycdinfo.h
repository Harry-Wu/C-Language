#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#define MAXSTRLEN 200

enum score  //ö�ٵ�Ĭ��ֵ��0,1,2,3,4
{
	Terrible, Bad, Average, Good, Excellent
};

typedef char STR50[50];
//������������ӵ��4����Ա�Ľṹ��
//����ṹ��ı�ǩ��cd
//�����ڽ�β����һ���ṹ�����cd_collection[4]
typedef struct  //����cd�ɼӿɲ��ӣ���typedef�Ǵ�����������CD
{
	STR50 name;  //����ʹ��typedef�ķ�ʽע���£�����ĳߴ�Ҳ�����ٶ�����
	STR50 artist;
	int trackcount;
	enum score rating;
}CD;

extern CD cd_collection[4];
void create_cdcollection();

int search_str(char *strDestination, char *searchstr);
int search_str2(char *strDestination, char *searchstr);

#endif // !_MYSTRING_H_
