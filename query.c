#include "ATM.h"

void query(void)
{
	system("cls");
	printf(">>2.查询<<");
	printf("===================\n");
	printf("用户id:%d\n",g_loginusers.id);
	printf("用户名:%s\n",g_loginusers.username);
	printf("账户余额:%.2f元\n",g_loginusers.money);
	printf("===================\n");
	printf("请按任意键返回主菜单！\n");
	getch();
}