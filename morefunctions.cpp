//morefunctions.cpp
//August 26, 2014
//This function demonstrates some overloaded functions.
#include<iostream>
using namespace std;
//function prototypes
float Sum(float, float);

float Sum(float, float, float);



int main()
{
	cout<<"Sum(10,20) = "<<Sum(10,20)<<endl;
	cout<<"Sum(10.5,20.5) = "<<Sum(10.5,20.5)<<endl;
	cout<<"Sum(10,20,30) = "<<Sum(10,20,30)<<endl;
	cout<<"Sum(10.5,20.5,30.5) = "<<Sum(10.5,20.5, 30.5)<<endl;
return 0;
}
//function defs

float Sum(float x, float y)
{
	return x + y;
}

float Sum(float x, float y, float z)
{
	return x + y + z;
}

