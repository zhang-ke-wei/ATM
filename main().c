#include"atm.h"
 ACCOUNT account_all[MAXUSERS];
 int usersnumber;
 ACCOUNT account_copy;

ACCOUNT account_all[MAXUSERS];
 int usersnumber;

void main()
{
	if(init())
	{
		printf("��ʼ���ɹ�\n");
		if(login())
		{
				menu();
		}
	}

}