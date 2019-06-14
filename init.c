#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
//extern ACCOUNT g_loginusers;       //保存当前登录的账号信息
//extern int g_count;                //保存加载用户数量
//extern int g_pos;                  //当前用户的下标

int init(void)//系统初始化，成功返回1；失败返回0
{
	char filename[] = "account.txt";
	char buf[128] = {0};
	char *rp=NULL;
	int pos=0;
	FILE *fp=NULL;

	fp = fopen(filename,"r");

	if(fp!=NULL)
	{
		//文件打开成功
		while(!feof(fp))
		{
			rp = fgets(buf,sizeof(buf),fp);
			if(rp!=NULL)//读取成功
			{
				if(pos<MAXUSER)
				{
					//保存数据
					g_users[pos] = convertaccount(buf);
					pos++;
				}
			}
		}
		g_count = pos;
		fclose(fp);
		return 1;
	}
	else
	{
		//文件打开失败
		printf("文件打开失败\n");
		return 0;
	}
}
//把字符串转换成结构类型
//字符串格式：id;uername;password;money;
ACCOUNT convertaccount(char *str)
{
	ACCOUNT ac;
	char *rp;
	if (str != NULL)
	{
		rp = strtok(str, ";");
		sscanf(rp, "%d", &ac.id);

		rp = strtok(NULL, ";");
		sscanf(rp, "%s", ac.username);

		rp = strtok(NULL, ";");
		sscanf(rp, "%s", ac.password);

		rp = strtok(NULL, ";");
		sscanf(rp, "%f", &ac.money);
	}

	return ac;
}
