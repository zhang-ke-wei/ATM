#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
//extern ACCOUNT g_loginusers;       //������ص��ڴ��е��˺���Ϣ
//extern int g_count;                //��������û�����
//extern int g_pos;                  //��ǰ�û����±�

//ʵ�ֵ�¼�Ĺ��ܣ��ɹ�����1 ��ʧ�ܷ���0
int loginview(void)
{
	int uid;
	int r,times;
	char password[50] = {0};
	printf("�������û�ID��\n");
	scanf("%d",&uid);
	printf("���������룺\n");
	scanf("%s",password);

	r=verify(uid,password);
	times = 1;

	while((r==0)&&(times<3))
	{
		printf("�û����������������\n");
		printf("�������û�ID��\n");
	    scanf("%d",&uid);
		getchar();
	    printf("���������룺\n");
	    scanf("%s",password);

	    r=verify(uid,password);
	    times++;
	}
	if (times == 3)
	{
		printf("��������������Σ������˻��ѱ�������Ŀǰ�޷���¼��������֤����̨�����\n");
		printf("лл������\n");
		printf("�밴������˳���\n");
		getch();
	}
	return r;

}

//��֤�ɹ�����1��ʧ�ܷ���0��
int verify(int uid,char *password)
{
	int valid = 0;
	int pos=-1;

	pos = SearchValidUser(uid);

	if(pos>=0)
	{
		if(strcmp(password, g_users[pos].password)==0)
			{
			valid = 1;
			g_loginusers=g_users[pos]; 
			g_pos = pos;
			}
		
	}
	return valid;
}

//�����û�����id��ȫ�����ṹ���е�λ�ã��±꣩����δ�ҵ�����-1
int SearchValidUser(int uid)
{
	int pos = -1;
	int i;
	for(i=0;i<g_count;i++)
	{
		if(uid==g_users[i].id)
		{

				pos = i;
				break;

		}
	}
	return pos;
}

void welcome(void)
{
	system("cls");
	printf("��ӭʹ��ATM����\n");
	printf("********************************\n");
	printf("*         ��ѡ�������         *\n");
	printf("*          1��ȡ��             *\n");
	printf("*          2������ѯ         *\n");
	printf("*          3���޸�����         *\n");
	printf("*          4��ת��             *\n");
	printf("*          5���˳�             *\n");
	printf("********************************\n");
}

void menu(void)
{
	char ch;
	welcome();
	while(ch = getch())
	{
		switch (ch)
		{
		case '1': 
			//����ȡ���
			withdraw();
			break;
		case '2':
			//���ò�ѯ����
			query();
			break;
		case '3':
			//�����޸����뺯��
			system("cls");
			changpwd();
			break;
		case '4':
			//����ת�˺���
			Transfer_Accounts();
			break;
		case '5':exitmenu();
		//default:welcome();
		default:
			break;
		}	
	}
}







