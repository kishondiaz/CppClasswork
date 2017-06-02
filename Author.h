//Author.h
//header file
//The purpose of this header file is to define the Author data type.

#include<string>
using namespace std;

//define structs
struct Author
{	
	//properties(attributes)
	string firstName, lastName;
	int age;
	
	//constructor
	//This is a function with the same name as struct and no return type.
	//The purpose of the constructor is to initialize the data in the object to 
	//default values.
	Author()
	{
		firstName = "John";
		lastName = "Doe";
		age = 0;
	
	}

};
