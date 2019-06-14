#include <stdio.h>
#include <stdlib.h>
#include "ATM.h"
extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
extern int g_count;                //保存加载用户数量

int UserMatching(void)
{
	int id;
	char username[MAXUSER];  //用户名
	char password[MAXUSER];   //用户密码
	printf("请输入用户名和密码\n");
	int i,k;
	for(k=0;k<3;k++)  //最多输入3次
	{
		scanf("%s", username);
		//getchar();
		scanf("%s", password);
		for (i = 0; i < MAXUSER; i++)
		{
			if ((strcmp(username, g_users[i].username) == 0) && (strcmp(password, g_users[i].password) == 0))
			{
				system("CLS");
				printf("登录成功\n");
				printf("欢迎使用***银行自助服务\n");
				break;
			}
		}
		if (i == MAXUSER)
		{
			printf("账号或密码输入错误，请重新输入\n");
		}
		else
			break;
	}
	if (k==3)
	{
		printf("密码输入错误3次，您的账户已被锁定,\n请持本人身份证到本行柜台办理挂失!\n");
		return 0;
	}
	return 1;
}