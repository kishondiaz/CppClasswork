// readExample1.cpp
// This program demonstrates how to read in data from a file

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    //Declare and initialize variables
    string first1, last1, first2, last2, first3, last3;
    float grade1 = 0.0, grade2 = 0.0, grade3 = 0.0, average = 0.0;

    //Declare file pointer for input
    ifstream infile;
    
    //Open file for input
    infile.open("grades.txt", ios::in);
    
    //Read in three records and store data in variables
    infile >> first1 >> last1 >> grade1;
    infile >> first2 >> last2 >> grade2;
    infile >> first3 >> last3 >> grade3;
    
    //Close file
    infile.close();
    
    //Intro
    cout << "WELCOME TO THE STUDENT DATA PROCESSOR!\n\n";
    
    //Display formatted data 
    cout << first1 << " " << last1 << ":\t" << grade1 << endl;
    cout << first2 << " " << last2 << ":\t" << grade2 << endl;
    cout << first3 << " " << last3 << ":\t" << grade3 << endl;
    
    //Calculate average
    average = (grade1 + grade2 + grade3) / 3;

    //Display average rounded to one decimal place
    cout << fixed << showpoint << setprecision(1);
    cout << "\nAverage Score: " << average << endl;

    return 0;
}