// rand1.cpp
// From Pr3-25-rand - Page 129 
// This program demonstrates random numbers. 
#include <iostream> 
#include <cstdlib>   // rand and srand 
#include <ctime>     // For the time function 
using namespace std; 
 
int main() 
{ 
    // Get the system time. 
    unsigned seed = time(0); 
    
    // Seed the random number generator. 
    srand(seed); 
    
    // Display 100 random numbers. 
    for (int i=0; i<100; i++) { 
        cout << rand() << "  "; 
    } 
    cout << endl; 
    return 0; 
}