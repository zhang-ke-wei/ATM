#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
//extern ACCOUNT g_loginusers;       //���浱ǰ��¼���˺���Ϣ
//extern int g_count;                //��������û�����
//extern int g_pos;                  //��ǰ�û����±�

int init(void)//ϵͳ��ʼ�����ɹ�����1��ʧ�ܷ���0
{
	char filename[] = "account.txt";
	char buf[128] = {0};
	char *rp=NULL;
	int pos=0;
	FILE *fp=NULL;

	fp = fopen(filename,"r");

	if(fp!=NULL)
	{
		//�ļ��򿪳ɹ�
		while(!feof(fp))
		{
			rp = fgets(buf,sizeof(buf),fp);
			if(rp!=NULL)//��ȡ�ɹ�
			{
				if(pos<MAXUSER)
				{
					//��������
					g_users[pos] = convertaccount(buf);
					pos++;
				}
			}
		}
		g_count = pos;
		fclose(fp);
		return 1;
	}
	else
	{
		//�ļ���ʧ��
		printf("�ļ���ʧ��\n");
		return 0;
	}
}
//���ַ���ת���ɽṹ����
//�ַ�����ʽ��id;uername;password;money;
ACCOUNT convertaccount(char *str)
{
	ACCOUNT ac;
	char *rp;
	if (str != NULL)
	{
		rp = strtok(str, ";");
		sscanf(rp, "%d", &ac.id);

		rp = strtok(NULL, ";");
		sscanf(rp, "%s", ac.username);

		rp = strtok(NULL, ";");
		sscanf(rp, "%s", ac.password);

		rp = strtok(NULL, ";");
		sscanf(rp, "%f", &ac.money);
	}

	return ac;
}
