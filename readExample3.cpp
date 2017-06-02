// readExample3.cpp
// This program demonstrates how to read in data from a file
// using a while loop

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    //Declare and initialize variables
    string first1, last1;
    float grade1, sum, average = 0.0;
    int count = 0;

    //Intro
    cout << "WELCOME TO THE STUDENT DATA PROCESSOR!\n\n";
    
    //Declare file pointer for input
    ifstream infile;
    
    //Open file for input
    infile.open("grades.txt", ios::in);
    
    ;
    while (infile >> first1 >> last1 >> grade1) {
        cout << first1 << " " << last1
            << ":\t" << grade1 << endl;
        sum += grade1;
        count++;
    }

    //Close file
    infile.close();

    //Calculate average
    average = sum / count;

    //Display average rounded to one decimal place
    cout << fixed << showpoint << setprecision(1);
    cout << "\nAverage Score: " << average << endl;

    return 0;
}
