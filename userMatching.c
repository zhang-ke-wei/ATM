#include <stdio.h>
#include <stdlib.h>
#include "ATM.h"
extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
extern int g_count;                //��������û�����

int UserMatching(void)
{
	int id;
	char username[MAXUSER];  //�û���
	char password[MAXUSER];   //�û�����
	printf("�������û���������\n");
	int i,k;
	for(k=0;k<3;k++)  //�������3��
	{
		scanf("%s", username);
		//getchar();
		scanf("%s", password);
		for (i = 0; i < MAXUSER; i++)
		{
			if ((strcmp(username, g_users[i].username) == 0) && (strcmp(password, g_users[i].password) == 0))
			{
				system("CLS");
				printf("��¼�ɹ�\n");
				printf("��ӭʹ��***������������\n");
				break;
			}
		}
		if (i == MAXUSER)
		{
			printf("�˺Ż����������������������\n");
		}
		else
			break;
	}
	if (k==3)
	{
		printf("�����������3�Σ������˻��ѱ�����,\n��ֱ������֤�����й�̨�����ʧ!\n");
		return 0;
	}
	return 1;
}