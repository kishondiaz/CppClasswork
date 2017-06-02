/*TimeMain.cpp
  Kishon Diaz
  Date: September 26, 2014
  This program converts standard time to military
  time.*/
  
#include "Time.cpp"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	Time time1;
	int hr=0,min=0;
	cout << "\nDefault time\n";
	time1.PrintTime();
	cout << "Enter the the time you want to convert.\n";
	cout << "hours ";
	cin >> hr;
	cout << "minutes ";
	cin >> min;
	time1.SetTime(hr,min,"am");
	if(time1.GetHour() >= 0 and time1.GetHour() <= 12)
	{
		time1.SetAmPm(" ");
		
		if(time1.GetHour() == 12)
			time1.SetHour(hr=00);
		else
			time1.SetHour(hr+=12);
		
	}
	else
	if(time1.GetHour() > 12 and time1.GetHour() <=24)
	{
		
		if(time1.GetHour() == 24)
			time1.SetHour(hr=12);
		else
		{
			hr +=12;
			hr-=24;
			time1.SetHour(hr);
			
		}
		 time1.SetAmPm("pm");
			
	}

	time1.PrintTime();
	cout << endl;

}
