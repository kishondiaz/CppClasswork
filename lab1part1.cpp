/*lab1part1.cpp
  Kishon Diaz
  August 26, 2014
  This program is from the lab1 excerise*/
  
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>


/*FUNCTION PROTOTYPES*/
/*  
  return type:
  parameters:
  purpose:
*/


using namespace std;

/*FUNCTION PROTOTYPES*/
/*  
  return type: void
  parameters: 1 ifstream and 2 ints one is pass by reference
 /*purpose: it retrives data from a txt file, the score,
  		   and its lengths.
*/
void GetData(ifstream&, int[],int&);
/*  
  return type: void
  parameters: 1 ifstream and 2 ints one is pass by reference
 /*purpose: it accepts the score read from the file, the length,
  		   and, sets grades over 60 to true.		   
*/
void ProcessPass(bool[],int[],int,string[]);

void StarsDisplay(string[]);

string ColorText(int,int,int,string);

void ColorNum(int,int,string&,string&);

int main()
{
	const int MAX_SIZE = 100;
	string pass[MAX_SIZE];
	int scores[MAX_SIZE];      //Array containing students' scores 
	bool passing[MAX_SIZE]={true};    // Boolean array
	int length = 0;       //Holds the actual number of students in a course
	int code=0,color=0;
	string stars[MAX_SIZE];
	ifstream infile;
	
	GetData(infile,scores,length);
	
	ProcessPass(passing,scores,length,pass);
	
	StarsDisplay(stars);
	cout << endl;
	cout << "\t"<<"STUDENT SCORE"<<"\t"<<"\n";
	StarsDisplay(stars);
	cout << endl;
	for(int i = 0; i < length; i++)
	{
		if(pass[i] == "passed" )
		{
		  code = 1,color = 32;	
		  pass[i] = ColorText(code,color,length,pass[i]);
		 cout<<"\t"<<scores[i] <<"\t"<<  pass[i] << endl;
		 
		}
	}
	for(int i = 0; i < length; i++)
	{
		if(pass[i] == "failed" )
		{
		 	code = 1,color = 31;	
		  	pass[i] = ColorText(code,color,length,pass[i]);
		 	cout<<"\t"<<scores[i] <<"\t"<< pass[i] << endl;
		 
		}
	}
	cout<<endl;
	infile.close();

	return 0;
}
/*purpose: it retrives data from a txt file, the score,
  		   and its lengths.
*/
void GetData(ifstream &infile, int scores[],int &length)
{
	
	infile.open("lab1data.txt", ios::in);
	
	infile >> scores[length];
	while(infile)
	{
		length++;
		
		infile >> scores[length];
	}
	infile.close();
}
/*purpose: it accepts the score read from the file, the length,
  		   and, sets grades over 60 to true.		   
*/
void ProcessPass(bool passing[],int scores[],int length,string pass[])
{
	for(int i=0;i<length;i++)
	{
		if(scores[i] < 60 and scores[i] >= !60 )
			passing[i] = false;
		else
			passing[i] = true;
		
		if(passing[i] == true)
			pass[i] = "passed";
		else
			pass[i] = "failed";	
	}
}
void StarsDisplay(string stars[])
{
	for(int i=0; i< 40; i++)
	{
		stars[i] = "*";
		cout << stars[i];
	}
}
void colorNum(int code, int color,string & sCode,string & sColor)
{

	switch(code)			
	{
		case 0:
		sCode = "0";
		break;
		case 1:
		sCode = "1";
		break;
		case 2:
		sCode = "2";
		break;
		case 3:
		sCode = "3";
		break;
		case 4:
		sCode = "4";
		break;
		case 5:
		sCode = "5";
		break;
		case 6:
		sCode = "6";
		break;
		case 7:
		sCode = "7";
		break;
	}
	if(color >=30 and color < 39)
	{
		switch(color)
		{
			case 30:
			sColor="30";
			break;
			case 31:
			sColor="31";
			break;
			case 32:
			sColor="32";
			break;
			case 33:
			sColor="33";
			break;
			case 34:
			sColor="34";
			break;
			case 35:
			sColor="35";
			break;
			case 36:
			sColor="36";
			break;
			case 37:
			sColor="37";
			break;
			case 38:
			sColor="38";
			break;
			case 39:
			sColor="39";
			break;
		}
		
	}



}
string ColorText(int code,int color,int length,string text)
{
	string sCode;
	string sColor;
	colorNum(code,color,sCode,sColor);
	
	if(text == text)
		text ="\033["+sCode+";"+sColor+"m"+ text+"\033[0m";
	return text;
}
