// writeExample.cpp
// This program demonstrates how to write text to a file.

#include<fstream>
using namespace std;

int main()
{
    //declare a file pointer
    ofstream outfile; //ofstream is a file pointer used for output to a file
    
    //open file "grades.txt" for output
    outfile.open("grades.txt", ios::out); //out will point to the beginning of the file
                            //if the file does not exist, it will get created
                            //if the file already exists, it will be overwritten
    //write to file
    outfile << "Mike Jones 96\n";
    outfile << "John Smith 88\n";
    outfile << "Jen Davis 94\n";
    
    //close file
    outfile.close();
    
    

 return 0;
}
