#ifndef _MYCDINFO_H_
#define _MYCDINFO_H_
#define MAXSTRLEN 500

enum score  //ö�ٵ�Ĭ��ֵ��0,1,2,3,4
{
	Terrible=1, Bad=2, Average=3, Good=4, Excellent=5
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

CD *cd_collection;
CD tempcd;
/**
* ��cd��Ϣ����ֵ
* ��������ǰ�ӵ���Щ˵��,�ں������õĵط�,����������ῴ��
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
