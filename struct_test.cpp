/*Name:Kishon Diaz
  File Name:courseTest.cpp
  date:9/30/14
  program: test in how to build structs and utilize them
*/


#include<iostream>
#include<string>
using namespace std;

struct Course
{
	string title,id;
	int referenceNum =0,credits=0;
	
	Course()
	{
		title = "Course Title";
		id = "Course Id";
		referenceNum = 0;
		credits = 0;
	
	}
};
struct Professor
{
	string firstName, lastName;
	int roomNum;
	Course courseList[5];
	
	Professor()
	{
		firstName = "Johnny";
		lastName = "Smithe";
		roomNum = 0;
		courseList[5];
	}

};
void GetCourse(Course&);
void GetProfessor(Professor&);

int main()
{
	Professor bestProfessor;
	
	GetProfessor(bestProfessor);
	
	cout << "Professor Name: " <<bestProfessor.firstName 
	<< bestProfessor.lastName <<  endl;
	cout << "Room Number:\t "<<bestProfessor.roomNum << endl
	<<endl;
	
	cout << "Course Title \t\t Course Id \t\t refNumber \t\t Credits\n";
	cout << "----------------------------------------------------------\n";
	
	for(int i=0;i<5;i++)
	{
		cout << bestProfessor.courseList[i].title<<"\t\t"
		<< bestProfessor.courseList[i].id<<"\t\t"
		<< bestProfessor.courseList[i].referenceNum<<"\t\t"
		<<bestProfessor.courseList[i].credits<<"\n";
	}


}

void GetCourse(Course & course)
{
	cout << "What is the Course this Professor Teaches!\n";
	cin >> course.title;
	cout << "What is the Course Id of the of Class?\n";
	cin >> course.id;
	cout << "What is the Reference number of the class?\n";
	cin >> course.referenceNum;
	cout << "What is the Value of Credits for the class?\n"
	cin >> course.credits;
	

}
void GetProfessor(Professor & professor)
{
	Course thisCourse;
	cout << "What is the professor's first name\n";
	cin >> professor.firstName;
	cout << "What is the professor's last name\n";
	cin >> professor.lastName;
	cout << "What room is the professor in\n";
	cin >> professor.roomNum;
	GetCourse(thisCourse);
	
	for(int i=0; i< 5;i++)
	{
		courseList[i]= thisCourse;
		
	}

	
}