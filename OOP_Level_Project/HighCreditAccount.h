/*
	HighCreditAccount.h
	version 0.9
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount :public NormalAccount
{
private:
	int specialRate;
public:
	//HighCreditAccount(int ID, int money, char* name, int rate, int special)
    HighCreditAccount(int ID, int money, String name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);	//원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0));	//특별이자 추가
	}
};
#endif // !__HIGHCREDIT_ACCOUNT_H__

