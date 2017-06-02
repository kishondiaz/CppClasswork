// appendExample.cpp
// This program demonstrates how to append a file.

#include<fstream>
#include<iostream>
using namespace std;

int main()
{    //declare variables
    string first, last;
    float grade = 0.0;
    
    //declare a file pointer
    ofstream outfile; //ofstream is a file pointer used for output to a file
    
    //intro 
    cout << "WELCOME TO THE STUDENT DATA COLLECTOR!\n\n";
    
    //prompt for info
    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "Enter grade: ";
    cin >> grade;    
    
    //open file "grades.txt" for appending
    outfile.open("grades.txt", ios::app); //app will point to the end of the file
                            //if the file does not exist, it will get created the first time
                            //if the file already exists, it will be appended
    //write to file
    outfile << first << " " << last << " " << grade << endl;
    
    
    //close file
    outfile.close();

    return 0;
}
