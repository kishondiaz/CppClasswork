/*Name:Kishon Diaz
  Files Name:BankAccount.h,BankAccount.cpp,BankAccountMain.cpp
  date:9/30/14
  program: test in how we build classes using .h,.cpp, and the Driver file(s).
*/
#include<string>
using namespace std;

#ifndef BANK_H
#define BANK_H

class BankAccount
{
	private:
		float balance, interestRate;
	
	public:
		BankAccount(float bal =0,float interst=0)
		{
			balance = bal;
			interestRate = interst;
		}
		SetInterestRate(float);
		GetInterestRate();
		GetBalance();
		
		void MakeDeposit(float);
		void MakeWithdrawal(float);
		void Compound();
		



};
#endif
