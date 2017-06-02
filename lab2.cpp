#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
/*
   lab2.cpp
   September 5, 2014
   Kishon Diaz
   This program is a practice program on how to use 
   structs.
*/

using namespace std;
/*
    Golbal Constant inteager used for
    the for loops for the test scores
*/ 
const int TEST_SCORES_MAXSIZE = 3;
/*
    Struct FullName used to hold the first name,
    middle initial, and last name of the student
    in this program.
*/
struct FullName
{

    string  firstName, lastName;
    char midInitial;
        
     
    FullName()
    {  
        firstName;
        lastName;
        midInitial;
    }
};
/*
    struct Student used to retrive
    and hold the Full name of student,
    an array named test to hold the test
    scores of the student, the combined
    average of the test scores, and the 
    letter grade values of the student.
*/    
struct Student
{
    FullName name;
    float tests[TEST_SCORES_MAXSIZE],average;
    char lettergrade;
    
    Student()
    {
        name;
        tests;
        average;
        lettergrade;
    }
    
};
/*
    struct Prompts is a very simple struct 
    used to prompt for the first name response
    of the student, last name response of the 
    student, and the middle initial response
    for the student.
*/
struct Prompts
{
    string firstname;
    string lastname;
    string middleiniti;
    
    Prompts()
    {
        firstname = "Students first name";
        lastname = "Students last name";
        middleiniti = "Students middle initial";
       
    
    }
    


};
struct Colors
{
    int black,red,green,yellow,blue,
    magenta,cyan,white;
    
    
    Colors()
    {
        black = 30;
        red = 31;
        green = 32;
        yellow = 33;
        blue = 34;
        magenta = 35;
        cyan=36;
        white = 37;
        
    }
   

};
struct Code
{
    int resetNormal,bold;
    
    Code()
    {
        resetNormal = 0;
        bold = 1;
    }


};
/*FUNCTION PROTOTYPES*/
/*  
  return type: float
  parameters: 1 const float array
 /*purpose: to get the average of the test scores 
   from the student.    
  		   
*/

float DetermineAverage(const float[3]);
/*  
  return type: char
  parameters: 1 const float
 /*purpose: to get the character letter of the 
   students score whether if its a A,B to grade 
   score F    
*/

char DetermineLetterGrade(float);
/*  
  return type: Student
  parameters: none
 /*purpose: to retrieve the information 
   that is stored in the Stuent struct,
   and to store it temporarly     
*/
Student GetData();
/*  
  return type: void
  parameters: 1 const Student
 /*purpose: to print out what was stored in
   the student struct that was created.   
*/
void PrintStudent(const Student);
/*  
  return type: void
  parameters: 2 ints' 2 string references
 /*purpose: to change the 2 ints into their
   desegnated code and color for escape operater.   
*/
void ColorNum(int,int,string&,string&);

/*  
  return type: string
  parameters: 3 ints' 1 string
 /*purpose: to change the color of the text in
   its paramenters.   
*/
string ColorText(int,int,int,string);
/*  
  return type: string
  parameters: 2 ints' 1 char
 /*purpose: overloaded function to change the 
   color of the character in its paramenters.   
*/
string ColorText(int,int,char);

int main()
{
    //How many students in class
    const int CLASS_SIZE = 24, INDEXED_STUDENT = 1;
    //The amount array of students in class
    
    system("clear");
    Student roster[CLASS_SIZE];
    
    
    roster[CLASS_SIZE-INDEXED_STUDENT] = GetData();
    
    system("clear");
    PrintStudent(roster[CLASS_SIZE-INDEXED_STUDENT]);
    cout << endl;
    /*
    
    //for loop used to get the student info
    for(int i=0; i< CLASS_SIZE; i++)
        roster[i] = GetData();
    /*for loop used to show on the screen the
      the results of the student struct 
     */
     /*
    for(int i=0; i< CLASS_SIZE; i++)
        PrintStudent(roster[i]);
        */
    return 0;

}
float DetermineAverage(const float average[3])
{
    float newave = 0.0;
    
    for(int i=0;i<TEST_SCORES_MAXSIZE;i++)
        newave += average[i] / TEST_SCORES_MAXSIZE;    
    return newave;

    
    
} 
/*purpose: to get the average of the test scores 
   from the student.      		   
*/

char DetermineLetterGrade(float testgrade)
{
    char grade = ' ';
    
    if(testgrade >= 101 or testgrade <= -1)
    {
        if(testgrade <=-1)
            cout << "Grades must be at least 0 between and 100\n";
        else
           cout << "Current Grading rubic not set past 100\n";
    }
    else if(testgrade >= 90 and testgrade <= 100)
         grade = 'A';
    else if(testgrade >= 80 or testgrade >= 89)
         grade = 'B';
    else if(testgrade >= 70 or testgrade >= 79)
        grade = 'C';
    else if(testgrade >=60 or testgrade >= 69)
        grade = 'D';
    else
        grade = 'F';
 
    return grade;


}
/*purpose: to get the character letter of the 
   students score whether if its a A,B to grade 
   score F    
*/
Student GetData()
{
    float ave = 0.0;
    Prompts prompt;
    Student student;
    cout << prompt.firstname << endl;
    cin >> student.name.firstName;
    cout << prompt.lastname << endl;
    cin >> student.name.lastName;
    cout << prompt.middleiniti << endl;
    cin >> student.name.midInitial;
    system("clear");
    for(int i=0; i<TEST_SCORES_MAXSIZE; i++)
    {
        /*
            switch case used to determine the first,second,third
            suffix after the number of test.
        */
        switch(i)
        {
            case 0:
                cout << "What is the students'" << i+1 << "st " << 
                "test score\n";
                break;
            case 1:
                 cout << "What is the students'" << i+1 << "nd " << 
                "test score\n";
                break;
            default:
                 cout << "What is the students'" << i+1 << "rd " << 
                "test score\n";
                 break;
         }
         //Get student test scores store it in sturct student test
        cin >> student.tests[i];    
    }
    /*Get the average from DetermineAverage fuction
      stroe it in the student.average sturct dot member operater. 
     */
    student.average = DetermineAverage(student.tests);
    /*Gets the letter grade from DetermineLetterGrade function
      and stores it in student.lettergrade sturct dot member operater
    */
    student.lettergrade = DetermineLetterGrade(student.average);

    return student;



}
/*purpose: to print out what was stored in
   the student struct that was created.   
*/
void PrintStudent(const Student student)
{
    char change;
    string text;
    Colors color;
    Code code;
    change = student.lettergrade;
    switch(change)
    {
        case'F':
            text = ColorText(code.bold,color.red,student.lettergrade);
            break;
        case'D':
            text = ColorText(code.bold,color.red,student.lettergrade);
            break;
        case'C':
            text = ColorText(code.bold,color.yellow,student.lettergrade);
            break;
        default:
            text = ColorText(code.bold,color.green,student.lettergrade);
            break;
    }
   
    cout << "Student Name:\t"<< student.name.firstName << " "
    << student.name.midInitial << ". "<< student.name.lastName << endl;
    for(int i=0;i<TEST_SCORES_MAXSIZE;i++)
        cout <<"Test "<< i+1 <<":\t\t\t"<<student.tests[i] << endl;
    cout << setprecision(2) << fixed;
    cout << "Average:\t\t" << student.average << endl;
    cout << "Final Grade:\t\t" << text << endl;
    
    

}
/*purpose: to change the 2 ints into their
   desegnated code and color for escape operater.   
*/
void colorNum(int code, int color,string & sCode,string & sColor)
{
    /*List: codes and colors found here
      en.wikipedia.org/wiki/ANSI_escape_code#graphics   
    */
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

/*purpose: to change the color of the text in
   its paramenters.   
*/
string ColorText(int code,int color,string text)
{
	string sCode;
	string sColor;
	colorNum(code,color,sCode,sColor);
	
	if(text == text)
		text ="\033["+sCode+";"+sColor+"m"+ text+"\033[0m";
	return text;
}
/*purpose: overloaded function to change the 
   color of the character in its paramenters.   
*/
string ColorText(int code,int color,char cText)
{
	string sCode,sColor,text,change;
	colorNum(code,color,sCode,sColor);
	/*purpose: to get the char and change it to 
	  its string counter part.   
    */
	switch(cText)
	{
	    case 'A':
	        change = "A";
	        break; 
	    case 'B':
	        change = "B";
	        break; 
	    case 'C':
	        change = "C";
	        break; 
	    case 'D':
	        change = "D";
	        break; 
	    case 'F':
	        change = "F";
	        break; 
	}
	
	if(text == text)
		text ="\033["+sCode+";"+sColor+"m"+ change+"\033[0m";
	return text;
}
