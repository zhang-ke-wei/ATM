#include "ATM.h"

void query(void)
{
	system("cls");
	printf(">>2.��ѯ<<");
	printf("===================\n");
	printf("�û�id:%d\n",g_loginusers.id);
	printf("�û���:%s\n",g_loginusers.username);
	printf("�˻����:%.2fԪ\n",g_loginusers.money);
	printf("===================\n");
	printf("�밴������������˵���\n");
	getch();
}