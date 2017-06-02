#include<iostream>
#include<cstring>
#include<stdlib.h>
/*
   winnersearch.cpp
   September 10, 2014
   Kishon Diaz
  
*/

using namespace std;
/*FUNCTION PROTOTYPES*/

bool isVaildPassword(char[]);
/*  
  return type: bool
  parameters: 1 char array
 /*purpose: to get if the password is true or false;    		   
*/
int main()
{
	const int SIZE = 20;
	int count=0;
	char password[SIZE];
	for(int i=0;i<SIZE;i++)
		password[i]='\0';
    system("clear");
	bool isPass = isVaildPassword(password), running = true;
	
	
	while(count <= 3 or running)
	{
	    
	    if(isPass == false)
	    {
	        do
	        {
			    cout << "Try again\n\n";
			    running = false; 
			}
			while(running);
			isPass = isVaildPassword(password);
						
		}
        else
        {
		    cout << "\nPassword is set\n\n";
		    break;
		}
	}
}
/*
    purpose: to get if the password is true or false;    		   
*/

bool isVaildPassword(char password[])
{
    const int MIN_SIZE = 6;
	bool isPassTrue = true,isCap=false,islowered=false,isnumber=false;
	
	   
		
		cout << "Create a password must have at least 1 Capital letter,\n"
		<<"1 Lower case letter, and 1 number\n\n";
		cout << "Enter Password Here: ";
		cin>> password;
		int SIZE = strlen(password);

		if(strlen(password) < 6)
			cout << "Password must be at least 6 characters\n";
	    for(int i=0;i<SIZE;i++)
	    {
			if(isupper(password[i]))
			isCap= true;
			if(islower(password[i]))
			islowered=true;
			if(isdigit(password[i]))
			isnumber = true;
		}
		if(isCap == true &&islowered == true &&isnumber == true)
			isPassTrue = true;
		else
		{   system("clear");
		    cout <<  endl;
		    if(isCap == false)
		        cout << "Must have at least one Capaital letter in it\n";
		    if(islowered == false)
		        cout << "Must have at least one lower case letter in it\n";
		    if(isnumber == false)
		        cout << "Must have at least one number in it\n";
		    
			isPassTrue = false;
		}
		cin.get();
	return isPassTrue;	
}

