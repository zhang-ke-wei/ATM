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
		printf("输入错误！请重新输入！\n");
		goto aaa;
	}
	printf("正在取款请稍后.....\n");
	Sleep(2000);//延时2000毫秒（模拟实际取款时的情景）
	printf("取款成功！\n");
	g_users[g_pos].money = g_loginusers.money;
	printf("请取现金%d元\n",Amount);

	//Record(Withdraws, Amount);

}

void options(void)
{
	system("cls");
	printf("================\n");
	printf("请选择取款额：\n");
	printf("  1、100元\n");
	printf("  2、200元\n");
	printf("  3、500元\n");
	printf("  4、1000元\n");
	printf("  5、其他\n");
	printf("================\n");
}
int Other()
{
	int Amount;

	printf("请输入取款额：\n");
	while (1)
	{
		scanf("%d", &Amount);
		if (judgement(Amount))
		{
			g_loginusers.money -= Amount;
			break;
		}
		else
			printf("请重新输入！\n");
	}
	return Amount;
}

//判断取款额是否合法,合法返回1.不合法返回0
int judgement(int Amount)
{
	//取款额必须为整百数，小于余额，单次取款不得超过10000元
	if (Amount <= 0 || Amount > g_loginusers.money || Amount % 100 != 0 || Amount > 10000)
	{
		printf("输入可能存在以下错误:\n1.非法额度\n2.非整百数！\n3.余额不足\n4.额度超过10000元\n");
		return 0;
	}
	else
		return 1;
}
