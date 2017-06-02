/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#include "HourlyPay.h"


void  HourlyPay::SetHourlyPay(float hrPay)
{
	hourlyPay = hrPay;
}
bool HourlyPay::SetHoursWorked()
{
	bool isOverUnder60 = false;


	if(totalHRWorked <= 40 or totalHRWorked <=59)
	{
		
		hourlyPay = GetWeeklyPay()/totalHRWorked;
		isOverUnder60 = true;
	}
	
	if(totalHRWorked >=40 and totalHRWorked <=59)
	{
		overTimePay = hourlyPay;
		isOverUnder60 = true;
	}
	else
	{
		isOverUnder60 = false;
		emp.ErrorBox(40,30,"\033[31m"+GetError(11),bgColor,bgColor,11);
	}
	return isOverUnder60;

}
bool HourlyPay::SetHoursWorked(int HrWorked)
{
	bool isOverUnder60 = false;
	
	if(HrWorked <=40)
	{
		hourlyPay = GetWeeklyPay()/HrWorked;
		totalHRWorked = HrWorked;
		isOverUnder60 = true;
	}
	else
	if(HrWorked >40 and HrWorked <=59)
	{

		overTimePay = hourlyPay*1.5;
		totalHRWorked = HrWorked;
		isOverUnder60 = true;
	}
	else
	{
		isOverUnder60 = false;
		emp.ErrorBox(40,30,"\033[31m"+GetError(11),bgColor,bgColor,11);
	}
	return isOverUnder60;

}
float HourlyPay::GetHourlyPay()
{
	return hourlyPay;
}
float HourlyPay::GetOverTimePay()
{
	return overTimePay;
}
int HourlyPay::GetHoursWorked()
{
	return totalHRWorked;
}
float HourlyPay::GetOverTimeWeeklyPay()
{
	return GetWeeklyPay();

}
void HourlyPay::Display()
{

	EmployeePay::Display();
	cout << "Hourly Pay: "<< GetHourlyPay()<<endl;
	cout << "Over TimePay: "<< GetOverTimePay()<<endl;
	cout << "OverTime Weekly pay: "<<GetOverTimeWeeklyPay()<<endl;
	cout << "Hours Worked: "<< GetHoursWorked()<<endl;

}
