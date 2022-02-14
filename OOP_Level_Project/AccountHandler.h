/*
	AccountHandler.h
	version 0.7
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];			//ACCOUNT 저장을 위한 배열
	int accNum;					//저장된 ACCOUNT 수
public:
	AccountHandler();
	void ShowMenu(void) const;		//메뉴출력
	void MakeAccount(void);		//계좌개설을 위한 함수
	void DepositMoney(void);	//입 금
	void WithdrawMoney(void);	//출 금
	void ShowAllAccInfo(void) const;	//잔액조회
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};
#endif // !__ACCOUNT__HANDLER_H__

