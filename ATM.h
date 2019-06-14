#ifndef __ATM_H__
#define __ATM_H__
#define MAXUSER 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

struct accountinfo
{
	int id;                  //用户id
	char username[10];       //用户名
	char password[10];       //用户密码
	float money;             //余额
};
typedef struct accountinfo ACCOUNT;
extern ACCOUNT g_users[MAXUSER];   //全局结构数组，保存用户信息
extern ACCOUNT g_loginusers;       //保存当前登录的账号信息
extern int g_count;                //保存加载用户数量
extern int g_pos;                  //当前用户的下标

ACCOUNT convertaccount(char *str);    //把字符串转换成结构类型
int init(void);                       //初始化

//int UserMatching(void);             //匹配用户，成功返回1；密码错误达到三次返回0；

int saveinfo(void);
void GetUserString(char *buf, ACCOUNT ac);

int loginview(void);                           //实现登录的功能，成功返回1 ，失败返回0
int SearchValidUser(int uid);                  //返回用户输入id在全局数结构组中的位置（下标），若未找到返回-1
int verify(int uid, char *password);           //返回用户输入id在全局数结构组中的位置（下标），若未找到返回-1
void welcome(void);
//int Withdraw_Money();
//void Main_Menu(void);
void menu(void);
void changpwd(void);                            //修改密码
void update(void);                             //刷新数据
void exitmenu(void);
void query(void);

void withdraw(void);
void options(void);
int Other();
int judgement(int Amount);
void Transfer_Accounts(void);
#endif