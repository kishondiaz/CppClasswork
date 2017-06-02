//structExample4.cpp
//Sept 2, 2014
//This program demonstrates the concept of nested structs.
//This version adds a new struct.
#include "Book.h"
#include<iostream>
#include<string>
using namespace std;
const int SIZE = 2;
struct Library
{
	//attributes
	string name;
	//array of Books
	Book bookArray[SIZE];
};
//function prototypes
//return type: Author
//parameters: none
//Purpose: This function prompts the user for a single Author.
Author GetAuthor();

//return type: void
//parameters: 1 Book by ref
//Purpose: This function prompts the user for a single Book.
void GetBook(Book&);

int main()
{
	//declare an instance of a Library
	Library myLibrary;
	
	//assign a name to myLibrary
	myLibrary.name = "BC_LIBRARY";
	
	//prompt for the info for all the Books in myLibrary
	for(int i = 0; i < SIZE; i++)
	{
		GetBook(myLibrary.bookArray[i]);
	}

	//display the author and title of the 1st Book
	cout<<"\nFirst Book Author: "<<myLibrary.bookArray[0].bookAuthor.firstName<<" "<<myLibrary.bookArray[0].bookAuthor.lastName<<endl;
	cout<<"First Book Title: "<<myLibrary.bookArray[0].title<<endl;
	
	
return 0;
}

//Purpose: This function prompts the user for a single Author.
Author GetAuthor()
{
	//declare a local variable
	Author tempAuthor;
	
	//prompt for first name
	cout<<"Enter the author's first name: ";
	cin>>tempAuthor.firstName;
	
	//prompt for last name
	cout<<"Enter the author's last name: ";
	cin>>tempAuthor.lastName;
	
	//prompt for age
	cout<<"Enter the author's age: ";
	cin>>tempAuthor.age;
	
	return tempAuthor;

}

//Purpose: This function prompts the user for a single Book.
void GetBook(Book &tempBook)
{	cout<<"Enter the book's title: ";
	cin>>tempBook.title;
	
	//call GetAuthor prompt for the book's author
	tempBook.bookAuthor = GetAuthor();
	
	cout<<"Enter the copyright date: ";
	cin>>tempBook.copyDate;
	
}
