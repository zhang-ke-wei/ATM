#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
//extern ACCOUNT g_loginusers;       //���浱ǰ��¼���˺���Ϣ
//extern int g_count;                //��������û�����
//extern int g_pos;                  //��ǰ�û����±�

void changpwd(void)
{
	char oldpwd[10] = {0};
	char newpwd1[10] = {0};
	char newpwd2[10] = {0};

	printf(">>3.�޸�����<<\n");
	printf("����������룺\n");
	scanf("%s",oldpwd);
	if(strcmp(oldpwd,g_loginusers.password)==0)
	{
		printf("������������\n");
		scanf("%s",newpwd1);

		printf("���ٴ�����������\n");
		scanf("%s",newpwd2);

		if(strcmp(newpwd1,newpwd2)==0)
		{
			strcpy(g_loginusers.password , newpwd1);
			//strcpy(g_users[g_count].password,g_loginusers.password);
			printf("�����޸ĳɹ���");
			return 1;
		}
		else
		{
			printf("�������벻һ�£�\n");
		}
	}
	else
	{
		printf("�����������\n");
	}
	printf("�밴������������˵���\n");
	fflush(stdin);
	getchar();

}
