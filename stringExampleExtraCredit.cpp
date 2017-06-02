//stringExample.cpp
//9/10/13
//This program demonstrates some string and c-string functions.

#include<cctype>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

//function prototypes
//return type: int
//parameters: 1 string
//Purpose: This function returns the number of words in a string.
int WordCount(string);

//function prototypes
//return type: int
//parameters: 1 c-string
//Purpose: This function returns the number of words in a c-string.
int WordCount(char[]);

//return type: int
//parameters: 2 strings
//Purpose: This function returns the number of occurences of the second
//string in the first string
int SubstringOccurrences(string, string);




int main()
{	//declare a string using a parameter constructor
	string phrase1("She sells sea shells by the sea shore");
	
	//declare a character string 
	char phrase2[] = "Peter Piper picked a peck of pickled peppers";

	cout<<"There are "<<WordCount(phrase1)<<" words in phrase1"<<endl;

	cout<<"There are "<<WordCount(phrase2)<<" words in phrase2"<<endl;
	
	cout<<"The word \"sea\" occurs at position "<<phrase1.find("sea")<<endl;
	cout<<"The word \"sea\" also occurs at position "<<phrase1.find("sea", 12)<<endl;
	
	//The following should produce an output equal to 2
	cout<<"The word \"sea\" occurs "<<SubstringOccurrences(phrase1, "sea")<<" times.\n";

 return 0;
}

int WordCount(string phrase)
{	//counter
	int count = 1;
	
	for(int i = 0; i < phrase.length(); i++)
	{
		if(isspace(phrase[i]))
			{
			count++;		
			}
	}
	
	return count;
}
//overloaded WordCount function
int WordCount(char phrase[])
{	//counter
	int count = 1;
	
	for(int i = 0; i < strlen(phrase); i++)
	{
		if(isspace(phrase[i]))
			{
			count++;		
			}
	}
	
	return count;
}

int SubstringOccurrences(string fullString, string subString)
{


}


