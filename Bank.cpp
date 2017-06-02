#include "Bank.h"
#include <iostream>

using namespace std;
	BankAccount::SetInterestRate(float interst)
	{
			interestRate = interst;
	}
	BankAccount::GetInterestRate()
	{
			return interestRate;
	}
	BankAccount::GetBalance()
	{
	
			return balance;
	
	}
	void BankAccount::MakeDeposit(float bal)
	{
			balance += bal;
	
	}
	void BankAccount::MakeWithdrawal(float bal)
	{
			balance -= bal;
	
	}
	void BankAccount::Compound()
	{
			
		balance *= (1 + interestRate); 
	}