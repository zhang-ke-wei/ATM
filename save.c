#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
//extern ACCOUNT g_loginusers;       //保存当前登录的账号信息
//extern int g_count;                //保存加载用户数量
//extern int g_pos;                  //当前用户的下标

//将数据存入文件
int saveinfo(void)
{
	char buf[100] = {0};
	char filename[] = "account.txt";
	FILE *fp=NULL;
	int i;

	fp = fopen(filename,"w");

	if(fp!=NULL)
	{
		update();
		for(i=0;i<g_count;i++)
		{
			GetUserString(buf,g_users[i]);
			fputs(buf,fp);
		}
		fclose(fp);
		return 1;
	}
	else
	{
		printf("保存数据文件失败！\n");
		return 0;
	}

}
//字符串格式：id;uername;password;money;
void GetUserString(char *buf,ACCOUNT ac)
{
	if (buf != NULL)
		sprintf(buf, "%d;%s;%s;%.2f\n", ac.id, ac.username, ac.password, ac.money);
}

void update(void)
{
	g_users[g_pos] = g_loginusers;
}

void exitmenu(void)
{
	printf(">>5.退出<<\n");
	update();
	saveinfo();
	printf("按任意键退出程序...\n");
	fflush(stdin);
	getchar();
	exit(0);
}