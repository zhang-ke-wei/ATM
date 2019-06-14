#include "ATM.h"

ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
ACCOUNT g_loginusers;       //保存加载到内存中的账号信息
int g_count;                //保存加载用户数量
int g_pos;                  //当前用户的下标

int main(void)
{
	if(init())
	{
		//初始化成功
		/*for (int i = 0; i < g_count; i++)
		{
			printf("%s\n", g_users[i].username);
			printf("%d\n", g_users[i].id);
			printf("%s\n", g_users[i].password);
			printf("%.2f\n", g_users[i].money);
		}*/
		if (loginview())
		{
			//登录成功
			//welcome();
			menu();
		}
		else
		{
			printf("登录失败！\n");
			return 0;
		}
	}
	else
	{
		printf("初始化失败！\n");
	}


//	if (UserMatching())
//	{
//		int a;
//		scanf("%d", &a);
//	//	system("CLS");
//	}
//	else
//	{
//		printf("谢谢使用!\n");
//		return 0;
//	}
	//system("pause");
	return 0;
}



/*int main(void)
{

	FILE *fp;
	fp = fopen("1001.txt", "a");
	if ("fp==NULL")
		printf("文件打开失败\n");
	else
	{
		time_t t;
		struct tm * lt;
		time(&t);             //获取时间。
		lt = localtime(&t);    //转为时间结构。
		fprintf(fp, "%d/%.2d/%.2d %.2d:%.2d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min);//输出结果
	}
	system("pause");
}*/

