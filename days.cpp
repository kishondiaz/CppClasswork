#include<iostream>
#include<string.h>
#include<cstdlib>
#include<iomanip>


const int DAYS = 365;
void getNumEmployees(int&);
int totalDaysMissed(int);
float averageDaysMissed(int,int);

using namespace std;



int main()
{
	int numEmployees = 0,daysMissed =0;
	float aveMissed = 0.0;

	system("clear");
	getNumEmployees(numEmployees);
	daysMissed = totalDaysMissed(numEmployees);
	aveMissed= averageDaysMissed(numEmployees,daysMissed);
	
	cout << setprecision(2) << fixed;
	cout <<"The averge amount of days missed by all employess is : " 
	<< aveMissed << endl; 
	
	
	


}
void getNumEmployees(int & numEmployees)
{
	cout << "how many employess work within the company: ";
	cin >> numEmployees;
	if(numEmployees < 1)
	{
		cout << "Needs to be more then 1 employee!\n"; 
	
	}


}
int totalDaysMissed(int numEmployees)
{
	int daysMissed= 0, missed = 0;
	cout << "Enter days employee missed\n";
	if(daysMissed < -1)
	{
		cout << "Invald input!\n";
	}
	else
	{
		for(int i=1;i <numEmployees+1 ; i++)
		{
			cout << "how many days did employee "<< i <<" missed: "; 
			cin >> missed;
			daysMissed += missed;
		
		}
	
	}
	return daysMissed; 
}
float averageDaysMissed(int numEmployees,int daysMissed)
{
	return ((float)daysMissed / (float)numEmployees );

}
