/**************************
          4.ת��
**************************/
#include "ATM.h"
void transferring(int pos);

void Transfer_Accounts(void)//ת��
{
	int Transfer_accountsID;
	//int TAA;//Transfer_Accounts_Amount(ת�˽�
	int pos;
	system("cls");
	printf(">>4.ת��<<\n");
	printf("������ת���˺ţ�\n");
	while (1)
	{

		scanf("%d", &Transfer_accountsID);
		pos = SearchValidUser(Transfer_accountsID);
		if (pos == -1)
			printf("���û������ڣ����������룡\n");
		else
		{
			transferring(pos);
			break;
		}
	}
	printf("�밴������������˵���\n");
	getch();
	welcome();
}

void transferring(int pos)
{
	int TAA;//Transfer_Accounts_Amount(ת�˽�
	printf("������ת�˽�\n");
	while (1)
	{
		scanf("%d", &TAA);
		if (TAA <= 0 || TAA > g_loginusers.money || TAA > 2000)
		{
			printf("������ܴ������´���:\n1.�Ƿ����\n2.����\n3.��ȳ���2000Ԫ\n���������룡\n");
		}
		else
		{
			printf("ת����Ϣ��\n");
			printf("================\n");
			printf("ת��id:%d\n", g_users[pos].id);
			printf("ת���û���:%s\n", g_users[pos].username);
			printf("ת�˽��:%dԪ\n", TAA);
			printf("================\n");
			printf("ȷ���밴1�������밴2\n");
			switch (getch())
			{
			case '1':
				g_users[pos].money += TAA;
				g_loginusers.money -= TAA;
				printf("ת�˳ɹ���");
				//Transfer_Accounts_Record(pos, TAA);
				printf("��Ŀǰ�����Ϊ%fԪ��\n", g_loginusers.money);
				break;
			case '2':break;
			default:break;
			}
			break;
		}
	}
}