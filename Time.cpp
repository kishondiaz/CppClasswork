/*Time.cpp
  Kishon Diaz
  Date: September 26, 2014
  This program converts standard time to military
  time.*/
//Time.cpp This is the specification file to define the class functions.
#include "Time.h"

#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

	//getter (accessor) functions
	int Time::GetHour()
	{
		return timeH;
	
	}
	int Time::GetMinute()
	{
		return timeM;
		
	}
	string Time::GetAmPm()
	{
		return amPm;
	}
	//setter (mutator) functions
	void Time::SetTime(int hr,int mi,string ap)
	{
		timeH = hr;
		timeM = mi;
		amPm = ap;
	}
	void Time::SetHour(int hr)
	{
	
		timeH = hr;
	
	}
	void Time::SetMinute(int mi)
	{
		timeM = mi;
	
	}
	//additional functions
	void Time::SetAmPm(string ap)//this changes am or pm or empty space 
	{
		amPm = ap;
	
	}
	void Time::PrintTime()
	{
			
		std::cout.precision(2);
		std::cout<<std::setw(2)
		<< std::setfill('0')<<timeH 
		<< ":"<<std::setw(2)
		<< std::setfill('0')<<timeM<<amPm;
		cout << endl;
	
	}
