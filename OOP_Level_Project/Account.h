/*
	Account.h
	version 0.9
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accID;					//°èÁÂ¹øÈ£
	int balance;				//ÀÜ¾×
	String cusName;
  //char* cusName;				//°í°´ÀÌ¸§
public:
	Account(int ID, int money, String name);
	//Account(int ID, int money, char* name);
	//Account(const Account& ref);
	//Account& operator=(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	//~Account();
};
#endif
