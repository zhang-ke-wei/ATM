//#include <stdio.h>
//#include <windows.h>
//#include <stdlib.h>
//#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
//extern ACCOUNT g_loginusers;       //������ص��ڴ��е��˺���Ϣ
//extern int g_count;                //��������û�����
//extern int g_pos;                  //��ǰ�û����±�
//void options(void);
//void Other();
//int judgement(int Amount);
//void a(void);
//
//int Withdraw_Money()
//{
//	options();
//	int n;
//		aaa:scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		g_loginusers.money -= 100;
//		break;
//	case 2:
//		g_loginusers.money -= 200;
//		break;
//	case 3:
//		g_loginusers.money -= 500;
//		break;
//	case 4:
//		g_loginusers.money -= 1000;
//		break;
//	case 5:
//		Other();
//		break;
//	default:
//		printf("����������������룡\n");
//		goto aaa;
//	}
//	printf("����ȡ�����Ժ�.....\n");
//	Sleep(2000);//��ʱ2000���루ģ��ʵ��ȡ��ʱ���龰��
//	printf("ȡ��ɹ���\n");
//	g_users[g_pos].money = g_loginusers.money;
//	a();
//}
//void options(void)
//{
//	system("cls");
//	printf("================\n");
//	printf("��ѡ��ȡ��\n");
//	printf("  1��100Ԫ\n");
//	printf("  2��200Ԫ\n");
//	printf("  3��500Ԫ\n");
//	printf("  4��1000Ԫ\n");
//	printf("  5������\n");
//	printf("================\n");
//}
//void Other()
//{
//	int Amount;
//	printf("������ȡ��\n");
//	while (1)
//	{
//		scanf("%d", &Amount);
//		if (judgement(Amount))
//		{
//			g_loginusers.money -= Amount;
//			break;
//		}
//		else
//			printf("���������룡\n");
//	}
//}
////�ж�ȡ����Ƿ�Ϸ�,�Ϸ�����1.���Ϸ�����0
//int judgement(int Amount)
//{
//	//ȡ������Ϊ��������С��������ȡ��ó���10000Ԫ
//	if (Amount <= 0 || Amount > g_loginusers.money || Amount % 100 != 0 || Amount > 10000)
//	{
//		printf("������ܴ������´���:\n1.�Ƿ����\n2.����������\n3.����\n4.��ȳ���10000Ԫ\n");
//		return 0;
//	}
//	else
//		return 1;
//}
//
//
//
//void a(void)
//{
//	printf("        1.�������˵�   2.�˳�       \n");
//	int a;
//	scanf("%d", &a);
//	switch (a)
//	{
//	case 1:Main_Menu();
//		break;
//	case 2:exit(0);
//		break;
//	}
//}