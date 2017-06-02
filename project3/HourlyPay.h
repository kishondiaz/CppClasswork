/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#ifndef HOURLYPAY_H
#define HOURLYPAY_H
#include"EmployeePay.cpp"


class HourlyPay:public EmployeePay
{
	private:
		float hourlyPay,overTimePay;
		int totalHRWorked;
		bool isOverUnder60; 
		string bgColor;
		EmployeePay emp;
		Errors e;		
		
	public:
		HourlyPay()
		{
			totalHRWorked = 40;

			if(totalHRWorked <= 40 or totalHRWorked <=59)
			{
				hourlyPay = GetWeeklyPay()/totalHRWorked;
				isOverUnder60 = false;
			}
			
			if(totalHRWorked >=40 and totalHRWorked <=59)
			{
				overTimePay = hourlyPay*1.5;
				isOverUnder60 = false;
			}
			bgColor=e.bgColor = "4";
			
		}
		HourlyPay(string sa,string ssn, string em,
		string dateHired, int anPay, int timework)
		:EmployeePay(sa,ssn,em,dateHired,anPay)
		{
			
			totalHRWorked = timework;
			
			if(totalHRWorked <= 40 or totalHRWorked <=59)
			{
				hourlyPay = GetWeeklyPay()/totalHRWorked;
				isOverUnder60 = false;
			}
			
			if(totalHRWorked > 40 or totalHRWorked <=59)
			{
				overTimePay = hourlyPay*1.5;
				isOverUnder60 = false;
			}
			else
			{
				isOverUnder60 = true;
				emp.ErrorBox(40,30,"\033[31m"+GetError(11),bgColor,bgColor,11);
			}
			
				
		}
		void SetHourlyPay(float);
		void SetOverTimePay(float);
		bool SetHoursWorked();
		bool SetHoursWorked(int);
		float GetHourlyPay();
		float GetOverTimePay();
		int GetHoursWorked();
		float GetOverTimeWeeklyPay();
		void Display();

};
#endif 

