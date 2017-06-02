// rand2.cpp 
// This program demonstrates random numbers between 2 values 
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
    
    // Display 100 random numbers in range min to max
    int min = 1, max = 5;
     
    for (int i=0; i<100; i++) { 
        cout << (min + rand() % max) << "  "; 
    } 
    cout << "\nOn this machine RAND_MAX = " << RAND_MAX << endl; 
    cout << endl; 
    return 0; 
}