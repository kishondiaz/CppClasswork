//Car.cpp This is the specification file to define the class functions.
#include "Car.h"

#include<iostream>
using namespace std;

	//getter (accessor) functions
	string Car::GetMake() //:: is the scope resolution operator
	{
		return make;
	}
	string Car::GetModel()
	{
		return model;
	}
	int Car::GetYear()
	{
		return year;
	}
	float Car::GetMileage()
	{
		return mileage;
	}
	
	//setter (mutator) functions
	void Car::SetMake(string mk)
	{
		make = mk;
	}
	void Car::SetModel(string mod)
	{
		model = mod;
	}
	
	void Car::SetYear(int yr)
	{
		year = yr;
	}
	//additional functions
	void Car::Drive(float miles) //this increases the mileage of the Car by a given amount
	{
		mileage += miles;
	}
	void Car::DisplayCar() //this function displays the info of the Car
	{
		cout<<"Make: "<<make<<endl;
		cout<<"Model: "<<model<<endl;
		cout<<"Year: "<<year<<endl;
		cout<<"Mileage: "<<mileage<<endl;
	
	}
	
	
