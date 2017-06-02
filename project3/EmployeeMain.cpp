/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#include"HourlyPay.cpp"
#include"glamour.cpp"
#include<iostream>
#include <unistd.h>
#include<stdlib.h>
#include<string>
#include<sstream>
#include<cstring>
#include <sys/ioctl.h>
#include<iomanip>


using namespace std;

void startCursorWindow();
void endCursorWindow();
void paycheckBoarder(int,int,int,int,string,string);
void PrintCheck(HourlyPay,string,int);
void PrintTextBox(int,int);
void InputBox(int,int,int,int,string&,string,string);
void mvprint(int,int,string,string,string);
void StartBackGroundColor(Glamour,string);
void ColorBackground(string);
string intToString(float);

Glamour makepretty;

int main()
{	
	bool isname=false,isemployeenum=false,issocial=false,isdate=false,
		 isannual=false,ishours=false;
	float newAnnualPay=0,newHours=0;
	int errs=0;
	string newName="",newEmployNum="",newSocial="",newDate="",newAnStr ="",
		   newhours="",thisHr="",setDays = "",strErr;
	string bgColor ="4";
	
	HourlyPay employeew;
	
	/*
		struct winsize is a structure from 	#include <sys/ioctl.h>
		ioctl is used to get the size of the terminal and passed into 
		the struct winsize then using the stringstream to convert the int 
		row and column into strings 
	*/
	
	
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	
	
	stringstream ssrow,sscol,print;
	sscol << w.ws_col;
	ssrow << w.ws_row;
	string srow = ssrow.str(),
	scol = sscol.str();
	//this const is used to record size of the terminal before 
	// it was resized
	const string CURRENT_ROW_SIZE = ssrow.str(),
	CURRENT_COL_SIZE = sscol.str();
	int row = atoi(srow.c_str()) ,
	col = atoi(scol.c_str());
	//This is the end of getting the window size and converting it to string
	
	/*This is used to start the coloring process of the background of the 
		terminal this is from my glamour class that i made.
	*/
	makepretty.BackGround(bgColor);
	
	/*This is used to resize the terminal making it bigger if the 
		terminal is smaller or as small as 48X180 and if it is bigger 
		it does nothing leaving it at the current size. 
	*/

	if(row < 48 and col < 180)
	{	cout << "\e[8;150;180t";
	}
	else
		cout << "";
		
	startCursorWindow();
	

	/*This is just to dispay the names for the editboxes i have created*/
	
	mvprint(48,10,"Employee Full Name:",bgColor,bgColor);
	mvprint(88,10,"Employee Number:",bgColor,bgColor);
	mvprint(48,13,"Social Security #:",bgColor,bgColor);
	mvprint(88,13,"Date Hired :",bgColor,bgColor);
	mvprint(48,16,"Annual Salary: ", bgColor,bgColor);
	mvprint(88,16,"Hours Worked: ",bgColor,bgColor);
	employeew.ErrorBox(40,30,"This is an ErrorBox all errors will appear here."
	,bgColor,bgColor,0);
	while(newName == "" or isname == false)
	{
		InputBox(67,10,4,30,newName,"Full Name",bgColor);

		if(newName == "")
			isname = false;
		else
			isname = true;
				
		employeew.SetName(newName);
	}
	while(isemployeenum == false or newEmployNum == "")
	{
		InputBox(104,10,4,30,newEmployNum,"xxx-L","7");
			isemployeenum = employeew.SetEmployeeNum(newEmployNum);
			if(isemployeenum == false or newEmployNum == "")
				isemployeenum = false;
			else
			{
				isemployeenum = true;
				employeew.ErrorBox(40,30,"",bgColor,bgColor,0);
			}
	}
	while(issocial == false or newSocial == "")
	{
		InputBox(67,13,4,30,newSocial,"xxx-xx-xxxx",bgColor);
			issocial = employeew.SetSocial(newSocial);
			 if(issocial == false)
			 	issocial = false;
			 else
			 {
			 	issocial=true;
			 	employeew.ErrorBox(40,30,"",bgColor,bgColor,0);
			 }
	}
	while(isdate == false or newDate =="")
	{
		InputBox(104,13,4,30,newDate,"xx/xx/xxxx","7");
			isdate=employeew.SetDayHire(newDate);
			if(isdate == false)
		 		isdate=false;
			 else
			 {
			 	isdate=true;
			 	employeew.ErrorBox(40,30,"",bgColor,bgColor,0);
			 }
	}
	newAnStr = intToString(newAnnualPay);
	while(isannual == false or newAnStr =="0"or newAnStr == "")
	{
		InputBox(67,16,4,30,newAnStr,"35000.00","7");
		
			isannual = employeew.IsSetAnnualPay(newAnnualPay);
			print << isannual;
			newAnnualPay = atoi(newAnStr.c_str());
			employeew.SetAnnualPay(newAnnualPay);
			if(isannual == false)
		 		isannual =false;
			 else
			 {
			 	isannual=true;
			 	employeew.ErrorBox(40,30,"",bgColor,bgColor,0);
			 }
	}

	InputBox(104,16,4,30,thisHr,"40hr","7");
	
	newHours = atoi(thisHr.c_str());
	
	employeew.SetHoursWorked(40);
	
		
	

	if(issocial== true and isemployeenum == true
	and employeew.SetAnnualPay() == true)
	{
		
		PrintCheck(employeew,bgColor,newHours);
		
	}
	else
	{
		cerr << "Invald input";
	
	}
	
	mvprint(60,46,"\033[1;33mPress Enter!",bgColor,bgColor);
	
	/*this ends the widow clearing the terminal*/
	
	endCursorWindow();
	cin.get();
	
	/* this clears the color returning it to normal*/
	
	makepretty.BGColorOff();
	/*this resizes the terminal back to its orginal size*/
	cout << "\e[8;"+CURRENT_ROW_SIZE+";"+CURRENT_COL_SIZE+"t";
	
	return 0;
}

void paycheckBoarder(int x,int y,int row, int col,string Fbg,string bk ="0")
{
	string boarder[100][100] = {};
	stringstream sX;
	sX << y;
	cout << "\033["+sX.str()+"H";
	
	for (int i = 0; i < row; i += 1)
	{
		cout.width(x);
		for (int j = 0; j < col; j += 1)
		{
			if(j<=0 or j>=col-1)
			{
				boarder[i][j] = " ";
				cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
			}
			else if(i<=0 or i>=row-1)
			{
				boarder[i][j] = " ";
				cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
			}
			else
			{
				boarder[i][j] = "\033[2;48;5;"+bk+"m \033[0m";
				cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
			}
		}
		cout << endl;
	}
	
	
}
void PrintTextBox(int x,int y)
{

	string boarder[100][100] = {};
	stringstream sX;
	sX << y;
	
	string bk = "7",inthis;
	int row = 4;
	int col = 30;
	
	cout << "\033["+sX.str()+"H";
		
	
	for (int i = 0; i < row; i += 1)
	{
		cout.width(x);
		for (int j = 0; j < col; j += 1)
		{
			if(j<=0 or j>=col-1)
			{
				boarder[i][j] = " ";
				cout << boarder[i][j]<<"\033[41m";
			}
			else if(i<=0 or i>=row-1)
			{
				boarder[i][j] = " ";
				cout << boarder[i][j]<<"\033[41m";
			}
			else
			{
				boarder[i][j] = "\033[2;48;5;"+bk+"m \033[0m";
				cout << boarder[i][j]<<"\033[41m";
			}
		}
		cout <<"\033[41m"<< endl;
	}

}
void startCursorWindow()
{
	cout << "\033[1J";

}
void endCursorWindow()
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	stringstream ss;
	ss << w.ws_col;
	
	cout<<"\033["+ss.str()+"E\033[0m";

}
void mvprint(int x,int y,string text,string Fgb="0",string bg = "49")
{
	stringstream sx,sy;
	sx << x;sy<<y;
	
	if(bg == "49")
	{
		cout<<"\033["+sy.str()+";"+sx.str()+"H"+text;
	}
	else
	{
		
		cout<<"\033[48;5;"+bg+";30m"+
		"\033["+sy.str()+";"+sx.str()+"H"+text+"\033[48;5;"+Fgb+"m";
			
	}
		
}
void InputBox(int x,int y,int row,int col,string & intext,string hint,string bk="0")
{
	string underline[100][100]={};
	stringstream sx,sy;
	sx << x;sy<<y;

	row = row-1;
	col = col-1;
	cout<<"\033[30;48;5;7m\033["+sy.str()+";"+sx.str()+"H____________\033[0m";
	do{
		cout<<"\033[4;38;5;8;48;5;7m\033["+sy.str()+";"+sx.str()+"H"+hint+"   ";
		cout<<"\033["+sy.str()+";"+sx.str()+"H";
		getline(cin,intext);
	}while(intext == "");

	if(intext == intext)
		cout<<"\033[4;30;48;5;7m\033["+sy.str()+";"+sx.str()+"H           ";
	cout<<"\033[4;30;48;5;7m\033["+sy.str()+";"+sx.str()+"H"+intext;
	cout<<"\033[0m";

}

void PrintCheck(HourlyPay employee,string Fbg,int hours)
{
	stringstream numberToString,numberToStrings;
	float paid=0;
	float numHrs = hours;
	
	string strNum;
	ColorBackground(Fbg);
	
	if(numHrs <=40)
	{
		paid = (employee.GetHourlyPay()*numHrs)*2; 
		numberToString << paid;
		strNum = numberToString.str();
	
	}
	else
    if(numHrs >40 or numHrs <=59)
	{
		paid = (employee.GetOverTimePay()*numHrs)*2;
		numberToString << paid;
		strNum = numberToString.str();
	}
	else
	{	numberToString << float(employee.GetHoursWorked());
		strNum = numberToString.str();
		mvprint(48,40,"\033[1;37mCannot be Over 60 Hours to many Hours "+strNum+"Hrs","1");
		
	}
	paycheckBoarder(40,20,20,100,Fbg,"7");
	ColorBackground(Fbg);	
	mvprint(48,23,"Employee Name: "+employee.GetName(),Fbg,"7");
	mvprint(100,23,"Date Hired: "+employee.GetDayHired(),Fbg,"7");
	mvprint(48,25,"Employee number: "+employee.GetEmployeeNum(),Fbg,"7");
	mvprint(100,25,"Employee SSN: "+employee.GetSocial(),Fbg,"7");
	mvprint(48,27,"BI-Weekly Pay: $"+strNum,Fbg,"7");
	mvprint(73,30,"Namico Corperation Ink",Fbg,"7");
	mvprint(43,36,"Employeer Signature: ",Fbg,"7" );
	mvprint(63,36,"_________________________",Fbg,"7" );
	mvprint(90,36,"Employee Signature: ",Fbg,"7" );
	mvprint(109,36,"_________________________",Fbg,"7" );
	mvprint(48,38,"000-1233846-9984727199390218391837329-82323978",Fbg,"7");	
	
}

void StartBackGroundColor(Glamour makepretty,string color)
{
	makepretty.BackGround(color);
}
void ColorBackground(string color)
{
	for (int i = 0; i <40; i += 1)
	{
		for ( int j = 0; j <40; j += 1)
		{

			cout << "\033[48;5;"+color+"m ";
		}
	}
}
string intToString(float num)
{
	string numtoText;
	stringstream ss;
	ss << num;
	numtoText = ss.str();
	return numtoText;

}

