//Book.h
//This header file defines the Book data type.

#include "Author.h"

#include<string>
using namespace std;

struct Book
{
	//properties
	Author bookAuthor;
	string title;
	int copyDate;
	
	//constructor
	Book()
	{
		title = "mybook";
		copyDate = 2014;
	}
};
