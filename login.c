#include "ATM.h"
//extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
//extern ACCOUNT g_loginusers;       //保存加载到内存中的账号信息
//extern int g_count;                //保存加载用户数量
//extern int g_pos;                  //当前用户的下标

//实现登录的功能，成功返回1 ，失败返回0
int loginview(void)
{
	int uid;
	int r,times;
	char password[50] = {0};
	printf("请输入用户ID：\n");
	scanf("%d",&uid);
	printf("请输入密码：\n");
	scanf("%s",password);

	r=verify(uid,password);
	times = 1;

	while((r==0)&&(times<3))
	{
		printf("用户或密码名输入错误！\n");
		printf("请输入用户ID：\n");
	    scanf("%d",&uid);
		getchar();
	    printf("请输入密码：\n");
	    scanf("%s",password);

	    r=verify(uid,password);
	    times++;
	}
	if (times == 3)
	{
		printf("密码输入错误三次，您的账户已被锁定，目前无法登录，请持身份证到柜台解除锁\n");
		printf("谢谢合作！\n");
		printf("请按任意键退出！\n");
		getch();
	}
	return r;

}

//验证成功返回1；失败返回0；
int verify(int uid,char *password)
{
	int valid = 0;
	int pos=-1;

	pos = SearchValidUser(uid);

	if(pos>=0)
	{
		if(strcmp(password, g_users[pos].password)==0)
			{
			valid = 1;
			g_loginusers=g_users[pos]; 
			g_pos = pos;
			}
		
	}
	return valid;
}

//返回用户输入id在全局数结构组中的位置（下标），若未找到返回-1
int SearchValidUser(int uid)
{
	int pos = -1;
	int i;
	for(i=0;i<g_count;i++)
	{
		if(uid==g_users[i].id)
		{

				pos = i;
				break;

		}
	}
	return pos;
}

void welcome(void)
{
	system("cls");
	printf("欢迎使用ATM机！\n");
	printf("********************************\n");
	printf("*         请选择服务项         *\n");
	printf("*          1、取款             *\n");
	printf("*          2、余额查询         *\n");
	printf("*          3、修改密码         *\n");
	printf("*          4、转账             *\n");
	printf("*          5、退出             *\n");
	printf("********************************\n");
}

void menu(void)
{
	char ch;
	welcome();
	while(ch = getch())
	{
		switch (ch)
		{
		case '1': 
			//调用取款函数
			withdraw();
			break;
		case '2':
			//调用查询函数
			query();
			break;
		case '3':
			//调用修改密码函数
			system("cls");
			changpwd();
			break;
		case '4':
			//调用转账函数
			Transfer_Accounts();
			break;
		case '5':exitmenu();
		//default:welcome();
		default:
			break;
		}	
	}
}







