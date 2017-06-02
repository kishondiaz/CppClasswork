//structExample3.cpp
//Sept 2, 2014
//This program demonstrates the concept of nested structs.
//This version includes header files for the Author and Book structs.
#include "Book.h"
#include<iostream>
#include<string>
using namespace std;


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
	//declare an instance of an Author
	//create an object of type Author
	Author myAuthor;
	
	//declare an instance of a Book
	Book myBook;
	
	//call GetAuthor
	myAuthor = GetAuthor();
	
	//assign myAuthor to myBook
	myBook.bookAuthor = myAuthor;
	//call GetBook
	GetBook(myBook);
	
	//display myAuthor info
	cout<<"\nmyAuthor information:\n";
	cout<<"Author name: "<<myAuthor.firstName<<" "<<myAuthor.lastName<<endl;
	cout<<"Age: "<<myAuthor.age<<endl;
	
	//display myBook info
	cout<<"\nmyBook info: "<<endl;
	cout<<"Book title:\t"<<myBook.title<<endl;
	cout<<"Book author:\t"<<myBook.bookAuthor.firstName<<" "<<myBook.bookAuthor.lastName<<endl;
	cout<<"Date:\t\t"<<myBook.copyDate<<endl;

	
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
