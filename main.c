#include "ATM.h"

ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
ACCOUNT g_loginusers;       //������ص��ڴ��е��˺���Ϣ
int g_count;                //��������û�����
int g_pos;                  //��ǰ�û����±�

int main(void)
{
	if(init())
	{
		//��ʼ���ɹ�
		/*for (int i = 0; i < g_count; i++)
		{
			printf("%s\n", g_users[i].username);
			printf("%d\n", g_users[i].id);
			printf("%s\n", g_users[i].password);
			printf("%.2f\n", g_users[i].money);
		}*/
		if (loginview())
		{
			//��¼�ɹ�
			//welcome();
			menu();
		}
		else
		{
			printf("��¼ʧ�ܣ�\n");
			return 0;
		}
	}
	else
	{
		printf("��ʼ��ʧ�ܣ�\n");
	}


//	if (UserMatching())
//	{
//		int a;
//		scanf("%d", &a);
//	//	system("CLS");
//	}
//	else
//	{
//		printf("ллʹ��!\n");
//		return 0;
//	}
	//system("pause");
	return 0;
}



/*int main(void)
{

	FILE *fp;
	fp = fopen("1001.txt", "a");
	if ("fp==NULL")
		printf("�ļ���ʧ��\n");
	else
	{
		time_t t;
		struct tm * lt;
		time(&t);             //��ȡʱ�䡣
		lt = localtime(&t);    //תΪʱ��ṹ��
		fprintf(fp, "%d/%.2d/%.2d %.2d:%.2d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min);//������
	}
	system("pause");
}*/

