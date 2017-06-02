/*Time.h
  Kishon Diaz
  Date: September 26, 2014
  This program converts standard time to military
  time.*/

#include<string>
using namespace std;

#ifndef TIME_H
#define TIME_H
class Time
{
	private://access specifier
		//data members(attributes)
		string amPm;
		int timeH,timeM;
		
	public:
		//default constructor
		Time()
		{
			timeH = 12;
			timeM = 01;
			amPm = "am";
		
		}
		//getter (accessor) functions
		void SetTime(int,int,string);
		void SetHour(int);
		void SetMinute(int);
		void SetAmPm(string);
		//setter (mutator) functions
		int GetHour();
		int GetMinute();
		//additional functions
		string GetAmPm();//this changes am or pm or empty space
		void PrintTime();

};
#endif
