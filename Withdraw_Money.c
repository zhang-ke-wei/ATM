//#include <stdio.h>
//#include <windows.h>
//#include <stdlib.h>
//#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
//extern ACCOUNT g_loginusers;       //保存加载到内存中的账号信息
//extern int g_count;                //保存加载用户数量
//extern int g_pos;                  //当前用户的下标
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
//		printf("输入错误！请重新输入！\n");
//		goto aaa;
//	}
//	printf("正在取款请稍后.....\n");
//	Sleep(2000);//延时2000毫秒（模拟实际取款时的情景）
//	printf("取款成功！\n");
//	g_users[g_pos].money = g_loginusers.money;
//	a();
//}
//void options(void)
//{
//	system("cls");
//	printf("================\n");
//	printf("请选择取款额：\n");
//	printf("  1、100元\n");
//	printf("  2、200元\n");
//	printf("  3、500元\n");
//	printf("  4、1000元\n");
//	printf("  5、其他\n");
//	printf("================\n");
//}
//void Other()
//{
//	int Amount;
//	printf("请输入取款额：\n");
//	while (1)
//	{
//		scanf("%d", &Amount);
//		if (judgement(Amount))
//		{
//			g_loginusers.money -= Amount;
//			break;
//		}
//		else
//			printf("请重新输入！\n");
//	}
//}
////判断取款额是否合法,合法返回1.不合法返回0
//int judgement(int Amount)
//{
//	//取款额必须为整百数，小于余额，单次取款不得超过10000元
//	if (Amount <= 0 || Amount > g_loginusers.money || Amount % 100 != 0 || Amount > 10000)
//	{
//		printf("输入可能存在以下错误:\n1.非法额度\n2.非整百数！\n3.余额不足\n4.额度超过10000元\n");
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
//	printf("        1.返回主菜单   2.退出       \n");
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