//Car.h This is the specification file for the Car class.
//Sept 16, 2014
#include<string>
using namespace std;

//define the Car class
//preprocessor directive to only define the class if it has not yet been defined
#ifndef CAR_H
#define CAR_H
class Car
{	
	private: //access specifier
		//data members(attributes)
		string make, model;
		int year;
		float mileage;

	public:
		//default constructor
		Car()
		{
		make = "Honda";
		model = "Accord";
		year = 2014;
		mileage = 0;
		}
		
		//overloaded parameter constructor
		Car(string mak, string mod, int yr, float mile)
		{
			make = mak;
			model = mod;
			year = yr;
			mileage = mile;
		}
		

	//getter (accessor) functions
	string GetMake();
	string GetModel();
	int GetYear();
	float GetMileage();
	
	//setter (mutator) functions
	void SetMake(string);
	void SetModel(string);
	void SetYear(int);
	
	//additional functions
	void Drive(float); //this increases the mileage of the Car by a given amount
	void DisplayCar(); //this function displays the info of the Car
	
};
#endif
