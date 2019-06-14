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
	int id;                  //�û�id
	char username[10];       //�û���
	char password[10];       //�û�����
	float money;             //���
};
typedef struct accountinfo ACCOUNT;
extern ACCOUNT g_users[MAXUSER];   //ȫ�ֽṹ���飬�����û���Ϣ
extern ACCOUNT g_loginusers;       //���浱ǰ��¼���˺���Ϣ
extern int g_count;                //��������û�����
extern int g_pos;                  //��ǰ�û����±�

ACCOUNT convertaccount(char *str);    //���ַ���ת���ɽṹ����
int init(void);                       //��ʼ��

//int UserMatching(void);             //ƥ���û����ɹ�����1���������ﵽ���η���0��

int saveinfo(void);
void GetUserString(char *buf, ACCOUNT ac);

int loginview(void);                           //ʵ�ֵ�¼�Ĺ��ܣ��ɹ�����1 ��ʧ�ܷ���0
int SearchValidUser(int uid);                  //�����û�����id��ȫ�����ṹ���е�λ�ã��±꣩����δ�ҵ�����-1
int verify(int uid, char *password);           //�����û�����id��ȫ�����ṹ���е�λ�ã��±꣩����δ�ҵ�����-1
void welcome(void);
//int Withdraw_Money();
//void Main_Menu(void);
void menu(void);
void changpwd(void);                            //�޸�����
void update(void);                             //ˢ������
void exitmenu(void);
void query(void);

void withdraw(void);
void options(void);
int Other();
int judgement(int Amount);
void Transfer_Accounts(void);
#endif