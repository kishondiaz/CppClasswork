//CarMain.cpp  This is the driver program to test the class.
//Sept 16, 2014

#include "Car.cpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	//declare an instance of a Car called car1 using the default constructor
	Car car1;
	string userMake, userModel;
	
	int userYear = 0;
	float userMile = 0.0;
	
	//display the car1 info
	cout<<"car1 info:\n";
	car1.DisplayCar();
	
	
	//prompt the user for some car info
	cout<<"\n\nEnter a car make: ";
	cin>>userMake;
	cout<<"Enter a car model: ";
	cin>>userModel;
	cout<<"Enter a car year: ";
	cin>>userYear;
	cout<<"Enter the mileage: ";
	cin>>userMile;
	
	//declare another instance of a Car using the information the user gave me
	Car car2(userMake, userModel, userYear, userMile);
	
	
	//display the car1 info
	cout<<"car2 info:\n";
	car2.DisplayCar();
	
	//set the info for car1 to the user's info
	cout<<"\nChanging the make of car1 to the user's info...\n";
	
	car1.SetMake(userMake);
	//display the car1 info
	cout<<"car1 info:\n";
	car1.DisplayCar();
	
	
	
	
	
	
	


return 0;
}
