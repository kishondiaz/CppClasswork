//morefunctions2.cpp
//August 26, 2014
//This function demonstrates a function with default values.
#include<iostream>
using namespace std;
//function prototypes
float Sum(float = 0, float = 0, float = 0);




int main()
{	cout<<"Sum() = "<<Sum()<<endl;
	cout<<"Sum(10) = "<<Sum(10)<<endl;
	cout<<"Sum(10,20) = "<<Sum(10,20)<<endl;
	cout<<"Sum(10.5,20.5) = "<<Sum(10.5,20.5)<<endl;
	cout<<"Sum(10,20,30) = "<<Sum(10,20,30)<<endl;
	cout<<"Sum(10.5,20.5,30.5) = "<<Sum(10.5,20.5, 30.5)<<endl;
return 0;
}
//function defs

float Sum(float x, float y, float z)
{
	return x + y + z;
}

