#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
//extern ACCOUNT g_loginusers;       //保存当前登录的账号信息
//extern int g_count;                //保存加载用户数量
//extern int g_pos;                  //当前用户的下标

void changpwd(void)
{
	char oldpwd[10] = {0};
	char newpwd1[10] = {0};
	char newpwd2[10] = {0};

	printf(">>3.修改密码<<\n");
	printf("请输入旧密码：\n");
	scanf("%s",oldpwd);
	if(strcmp(oldpwd,g_loginusers.password)==0)
	{
		printf("请输入新密码\n");
		scanf("%s",newpwd1);

		printf("请再次输入新密码\n");
		scanf("%s",newpwd2);

		if(strcmp(newpwd1,newpwd2)==0)
		{
			strcpy(g_loginusers.password , newpwd1);
			//strcpy(g_users[g_count].password,g_loginusers.password);
			printf("密码修改成功！");
			return 1;
		}
		else
		{
			printf("密码输入不一致！\n");
		}
	}
	else
	{
		printf("密码输入错误！\n");
	}
	printf("请按任意键返回主菜单！\n");
	fflush(stdin);
	getchar();

}
