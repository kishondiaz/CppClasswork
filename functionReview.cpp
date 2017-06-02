//functionReview.cpp
//Michelle Levine
//August 26, 2014
//This program is a review of functions, arrays and file reading/writing.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//function prototypes
//return type: void
//parameters: none
//purpose: This function displays an intro.
void DisplayIntro();

//return type: string
//parameters: none
//purpose: This function prompts for and returns a name.
string GetName();

//return type: void
//parameters: 1 string by value
//purpose: This function greets the user by name.
void DisplayGreeting(string);

//return type: void
//parameters: 1 int by reference
//purpose: This function prompts the user for an age.
void GetAge(int&);

//return type: void
//parameters: 1 string by value, 1 int by value
//purpose: This function displays the user info
void DisplayInfo(string, int);

//return type: int
//parameters: 1 file pointer for input by ref, 1 array of ints
//purpose: This function reads in some grades from a file and populates the array
//with the grades.  It also keeps track of the count of grades in the file and returns that value.
int ReadInGrades(ifstream&, int[]);

//return type: void
//parameters: 1 array of ints, 1 int(number of values)
//purpose: This function displays the values in an array.
void DisplayValues(const int[], int); //const indicates that no changes will be (can be) made to the array

const int MAX_SIZE = 10;
int main()
{	//declare a file pointer for input
	ifstream infile;

	//declare an array of integers
	int userGrades[MAX_SIZE] = {0};
	
	//declare variables
	string userName;
	int userAge = 0;
	int numGrades = 0;
	
	//call(invoke) DisplayIntro function
	DisplayIntro();
	
	//call GetName function
	userName = GetName();
	
	//call DisplayGreeting
	DisplayGreeting(userName);
	
	DisplayGreeting("Bob");
	
	//call GetAge
	GetAge(userAge);
	
	//call DisplayInfo
	DisplayInfo(userName, userAge);
	
	//call ReadInGrades
	numGrades = ReadInGrades(infile, userGrades);
	
	//call DisplayGrades
	DisplayValues(userGrades, numGrades);

 return 0;
}

//function definitions
//purpose: This function displays an intro.
void DisplayIntro()
{
	cout<<"WELCOME TO MY PROGRAM!!\n\n";
}
//purpose: This function prompts for and returns a name.
string GetName()
{	//declare a local variable
	string tempName;
	
	//prompt for name
	cout<<"Enter a name: ";
	cin>>tempName;
	
	return tempName;
}

//purpose: This function greets the user by name.
void DisplayGreeting(string tempName)
{
	cout<<"Hello "<<tempName<<endl;
}

//purpose: This function prompts the user for an age.
void GetAge(int &tempAge)
{
	cout<<"Enter your age: ";
	cin>>tempAge;
}

//purpose: This function displays the user info
void DisplayInfo(string tempName, int tempAge)
{
	cout<<"Name:\t"<<tempName<<endl;
	cout<<"Age:\t"<<tempAge<<endl;
}

//purpose: This function reads in some grades from a file and populates the array
//with the grades.  It also keeps track of the count of grades in the file and returns that value.
int ReadInGrades(ifstream &filein, int arr[])
{
	//declare local counter
	int count = 0;
	
	//open file for input
	filein.open("grades.txt", ios::in);
	
	//read in the first grade (priming read)
	filein>>arr[count];
	
	while(filein)
	{
		//increment count
		count++;
		
		//read in the next value
		filein>>arr[count];
	}
	
	//close file
	filein.close();
	
	return count;
	
}

//purpose: This function displays the values in an array.
void DisplayValues(const int arr[], int num)
{
	for(int i = 0; i < num; i++)
	{
	cout<<"Grade "<<i + 1<<":"<<arr[i]<<endl;
	}
	
}
