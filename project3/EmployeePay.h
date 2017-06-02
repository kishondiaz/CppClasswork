/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#ifndef EMPLOYEEPAY_H
#define EMPLOYEEPAY_H
#include<string>
#include<iostream>
#include <math.h> 
#include <iomanip>
#include"Employee.cpp"


class EmployeePay:public Employee
{

	private:
		float annualPay, weeklyPay;
		bool isNegitve;
		string bgColor;
		Employee emp;
		Errors e;
		
	public:
		EmployeePay()
		{
			annualPay = 36000;
			if(annualPay <= -1)
			{
				emp.ErrorBox(40,30,"\033[31m"+GetError(10),bgColor,bgColor,10);
			}
			else
			{
				weeklyPay = (annualPay/52);
			}
			bgColor = e.bgColor = "4";
			
		}
		EmployeePay(string na, string ssn, string em,string dayhire, float anPay)
		:Employee(na,ssn,em,dayhire)
		{
			
			
			if(anPay <= -1)
			{
				emp.ErrorBox(40,30,"\033[31m"+GetError(10),bgColor,bgColor,10);
			}
			else
			{
				annualPay = anPay;
				weeklyPay = (annualPay/52);
			}
		}
		bool SetAnnualPay();
		bool IsSetAnnualPay(int);
		bool IsSetAnnualPay(float);
		void SetAnnualPay(float,string);
		void SetWeeklyPay(float);
		float GetAnnualPay();
		float GetWeeklyPay();
		void Display();
		

};
#endif /* EMPLOYEEPAY_H */





