#include "ATM.h"

void withdraw(void)
{
		int n;
		int Amount;
			options();
		aaa:scanf("%d", &n);
	switch (n)
	{
	case 1:
		Amount = 100;
		g_loginusers.money -= 100;
		break;
	case 2:
		Amount = 200;
		g_loginusers.money -= 200;
		break;
	case 3:
		Amount = 500;
		g_loginusers.money -= 500;
		break;
	case 4:
		Amount = 1000;
		g_loginusers.money -= 1000;
		break;
	case 5:
		Amount = Other();
		break;
	default:
		printf("����������������룡\n");
		goto aaa;
	}
	printf("����ȡ�����Ժ�.....\n");
	Sleep(2000);//��ʱ2000���루ģ��ʵ��ȡ��ʱ���龰��
	printf("ȡ��ɹ���\n");
	g_users[g_pos].money = g_loginusers.money;
	printf("��ȡ�ֽ�%dԪ\n",Amount);

	//Record(Withdraws, Amount);

}

void options(void)
{
	system("cls");
	printf("================\n");
	printf("��ѡ��ȡ��\n");
	printf("  1��100Ԫ\n");
	printf("  2��200Ԫ\n");
	printf("  3��500Ԫ\n");
	printf("  4��1000Ԫ\n");
	printf("  5������\n");
	printf("================\n");
}
int Other()
{
	int Amount;

	printf("������ȡ��\n");
	while (1)
	{
		scanf("%d", &Amount);
		if (judgement(Amount))
		{
			g_loginusers.money -= Amount;
			break;
		}
		else
			printf("���������룡\n");
	}
	return Amount;
}

//�ж�ȡ����Ƿ�Ϸ�,�Ϸ�����1.���Ϸ�����0
int judgement(int Amount)
{
	//ȡ������Ϊ��������С��������ȡ��ó���10000Ԫ
	if (Amount <= 0 || Amount > g_loginusers.money || Amount % 100 != 0 || Amount > 10000)
	{
		printf("������ܴ������´���:\n1.�Ƿ����\n2.����������\n3.����\n4.��ȳ���10000Ԫ\n");
		return 0;
	}
	else
		return 1;
}
