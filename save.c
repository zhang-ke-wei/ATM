#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
//extern ACCOUNT g_loginusers;       //���浱ǰ��¼���˺���Ϣ
//extern int g_count;                //��������û�����
//extern int g_pos;                  //��ǰ�û����±�

//�����ݴ����ļ�
int saveinfo(void)
{
	char buf[100] = {0};
	char filename[] = "account.txt";
	FILE *fp=NULL;
	int i;

	fp = fopen(filename,"w");

	if(fp!=NULL)
	{
		update();
		for(i=0;i<g_count;i++)
		{
			GetUserString(buf,g_users[i]);
			fputs(buf,fp);
		}
		fclose(fp);
		return 1;
	}
	else
	{
		printf("���������ļ�ʧ�ܣ�\n");
		return 0;
	}

}
//�ַ�����ʽ��id;uername;password;money;
void GetUserString(char *buf,ACCOUNT ac)
{
	if (buf != NULL)
		sprintf(buf, "%d;%s;%s;%.2f\n", ac.id, ac.username, ac.password, ac.money);
}

void update(void)
{
	g_users[g_pos] = g_loginusers;
}

void exitmenu(void)
{
	printf(">>5.�˳�<<\n");
	update();
	saveinfo();
	printf("��������˳�����...\n");
	fflush(stdin);
	getchar();
	exit(0);
}