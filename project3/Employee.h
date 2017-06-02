/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>


using namespace std;
struct Errors
{
	string errors[15] , bgColor;
	Errors()
	{
		errors[0] = "Please Enter social security"
					" number in this format xxx-xx-xxxx\n";
		errors[1] ="Cannot be less then 11 digits and dashes";
		errors[2] ="Cannot be greater then 11 digits and dashes";
		errors[3] ="Cannot have Letters in social security number!\n";
		errors[4] =	"Please Enter Employee"
					" number in this format xxx-L\n"
					"\t\t\tPlease Use Captial Letters A-M "
					"at the end of employee number ";
		errors[5] =	"Cannot be less then 3 digits and 1 Character please include dash";
		errors[6] =	"Cannot be greater then 3 digits and 1 Character";
		errors[7] ="too short";
		errors[8] ="too big";
		errors[9] ="wrong format";
		errors[10]="Cannot be Negitive";
		errors[11]="can not be over 60\n";
		
		bgColor ="4";

	
	}

};

class Employee
{
	private:
		string name,ssNumber,employeeNum,hireDate,errcheck[15],bgColor;
		unsigned int errnum;
		Errors e;
	public:
		Employee()
		{
			name = "Tim Scout";
			ssNumber ="000-00-0000";
			employeeNum ="000-L";
			hireDate ="10/26/2014";
			errnum = 0;
			bgColor = e.bgColor;
		
		}
		Employee(string na,string ssn,string em,string dayhired)
		{
		
			name=na;
			ssNumber=ssn;
			employeeNum = em;
			hireDate=dayhired;
		}
		
		void SetName(string);
		bool SetSocial();
		bool SetSocial(string);
		bool SetEmployeeNum();
		bool SetEmployeeNum(string&);
		bool SetDayHire(string&);
		bool ErrorCheck(int,bool);
		void SetDayHired(string);
		string GetName();
		string GetSocial();
		string GetEmployeeNum();
		string GetDayHired();
		string isHireDate(string);
		string GetError(int);
		void ErrorNumber(int);
		int GetErrorNumber();
		void Display();
		void mvprint(int,int,string,string,string);
		void PrintBox(int,int,int,int,string,string);
		void ErrorBox(int,int,string,string,string,int);

};
#endif
