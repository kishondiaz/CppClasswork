//stringExample.cpp
//jan 24, 2014
//this program demonstrates the use of character, string and c-string functions

#include<cctype> //character functions
#include<string> //string functions
//#include<cstring>
#include<iostream>
using namespace std;

//return type: int
//parameters: 1 string by value
//Purpose: This function returns the number of words in a string
int WordCount(string);

//overload the WordCount function
//return type: int
//parameters: 1 character string
//Purpose: This function returns the number of words in a character string
int WordCount(char[]);

int main()
{
	//declare a c-string
	char phrase1[80] = "How much wood would a woodchuck chuck?";
	
	//declare a string
	string phrase2 = "She sells sea shells";
	
	int numWords = 0;
	
	strcat(phrase1, " if a woodchuck could chuck");
	cout<<phrase1<<endl;
	cout<<"\nLength of phrase1 = "<<strlen(phrase1)<<endl;
	
	cout<<"\nphrase1 = "<<phrase1<<endl;
	 
	cout<<"\nphrase2 = "<<phrase2<<endl;
	
	cout<<"\nThere are "<<WordCount(phrase1)<<" words in phrase1\n";
	cout<<"\nThere are "<<WordCount(phrase2)<<" words in phrase2\n";
	
	cout<<"\nThe string \"ells\" occurs at position "<<phrase2.find("ells")<<" in phrase2\n"; 
	cout<<"\nThe string \"ells\" also occurs at position "<<phrase2.find("ells", 6)<<" in phrase2\n";
	
	
 return 0;
}
//Purpose: This function returns the number of words in a string
int WordCount(string tempString)
{	
	int wordcount = 1;
	
	for(int i = 0; i < tempString.length(); i++)
	{
		if(isspace(tempString[i]))
			wordcount++;
	}
	
	return wordcount;
}

//Purpose: This function returns the number of words in a character string
int WordCount(char tempString[])
{
	int wordcount = 1;
	
	for(int i = 0; i < strlen(tempString); i++)
	{
		if(isspace(tempString[i]))
			wordcount++;
	}
	
	return wordcount;

}

