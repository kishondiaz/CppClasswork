/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#include"EmployeePay.h"
#include<iomanip>
using namespace std;


bool EmployeePay::SetAnnualPay()
{
	bool notNegtive = false,checkGood= false;
	if(annualPay <= -1)
	{
		notNegtive = false;
		cout << "Cannot be Negitive\n";
	}
	else
	{
		notNegtive = true;
	
		weeklyPay = (annualPay/52);
	}
	if(notNegtive == true)
	{
		checkGood = true;
	}
	else
	{
		checkGood = false;
	}
	return checkGood;
}
bool EmployeePay::IsSetAnnualPay(int anPay)
{
	bool notNegtive = false,checkGood= false;
	if(anPay <= -1)
	{
		notNegtive = false;
		cout << "Cannot be Negitive\n";
	}
	else
	{
		annualPay = anPay;
		notNegtive = true;
		weeklyPay = (annualPay/52);
	}
	if(notNegtive == true)
	{
		checkGood = true;
	}
	else
	{
		checkGood = false;
	}
	return checkGood;

}
bool EmployeePay::IsSetAnnualPay(float anPay)
{
	bool notNegtive = false,checkGood= false;
	if(anPay <= -1)
	{
		notNegtive = false;
		cout << "Cannot be Negitive\n";
	}
	else
	{
		annualPay = anPay;
		notNegtive = true;
		weeklyPay = (annualPay/52);
	}
	if(notNegtive == true)
	{
		checkGood = true;
	}
	else
	{
		checkGood = false;
	}
	return checkGood;
}
void  EmployeePay::SetAnnualPay(float anPay,string none="0")
{

	if(anPay <= -1)
	{
		cout << "Cannot be Negitive\n";
	}
	else
	{
		annualPay = anPay;
		weeklyPay = (annualPay/52);
	}

}
void EmployeePay::SetWeeklyPay(float anPay)
{
	weeklyPay = (anPay/52);

}
float EmployeePay::GetAnnualPay()
{

	return annualPay;

}								
float EmployeePay::GetWeeklyPay()
{
	
	
	return weeklyPay;

}
void EmployeePay::Display()
{
	Employee::Display();
	cout << "Annual Pay: "<< GetAnnualPay()<< endl;
	cout << "Weekly Pay: "<<GetWeeklyPay()<< endl;
}

