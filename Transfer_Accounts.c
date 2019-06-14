/**************************
          4.转账
**************************/
#include "ATM.h"
void transferring(int pos);

void Transfer_Accounts(void)//转账
{
	int Transfer_accountsID;
	//int TAA;//Transfer_Accounts_Amount(转账金额）
	int pos;
	system("cls");
	printf(">>4.转账<<\n");
	printf("请输入转入账号：\n");
	while (1)
	{

		scanf("%d", &Transfer_accountsID);
		pos = SearchValidUser(Transfer_accountsID);
		if (pos == -1)
			printf("该用户不存在！请重新输入！\n");
		else
		{
			transferring(pos);
			break;
		}
	}
	printf("请按任意键返回主菜单！\n");
	getch();
	welcome();
}

void transferring(int pos)
{
	int TAA;//Transfer_Accounts_Amount(转账金额）
	printf("请输入转账金额：\n");
	while (1)
	{
		scanf("%d", &TAA);
		if (TAA <= 0 || TAA > g_loginusers.money || TAA > 2000)
		{
			printf("输入可能存在以下错误:\n1.非法额度\n2.余额不足\n3.额度超过2000元\n请重新输入！\n");
		}
		else
		{
			printf("转账信息：\n");
			printf("================\n");
			printf("转账id:%d\n", g_users[pos].id);
			printf("转账用户名:%s\n", g_users[pos].username);
			printf("转账金额:%d元\n", TAA);
			printf("================\n");
			printf("确认请按1，返回请按2\n");
			switch (getch())
			{
			case '1':
				g_users[pos].money += TAA;
				g_loginusers.money -= TAA;
				printf("转账成功！");
				//Transfer_Accounts_Record(pos, TAA);
				printf("您目前的余额为%f元。\n", g_loginusers.money);
				break;
			case '2':break;
			default:break;
			}
			break;
		}
	}
}