/*
	AccountHandler.h
	version 0.8
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;
	int accNum;					//����� ACCOUNT ��
public:
	AccountHandler();
	void ShowMenu(void) const;		//�޴����
	void MakeAccount(void);		//���°����� ���� �Լ�
	void DepositMoney(void);	//�� ��
	void WithdrawMoney(void);	//�� ��
	void ShowAllAccInfo(void) const;	//�ܾ���ȸ
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};
#endif // !__ACCOUNT__HANDLER_H__

