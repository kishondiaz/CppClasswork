// clearScreen.cpp
#include <cstdlib> // Needed for system() call
#include <iostream>
using namespace std;

// Choose the correct "clearScreen" command based on the O/S:

#ifdef CENTOS
#define clearScreen system("clear")
#elif defined OSX
#define clearScreen system("clear")
#elif defined UBUNTU
#define clearScreen system("clear")
#elif defined WINDOWS
#define clearScreen system("cls")
#endif

int main()
{
    // Call the clearScreen command:
    clearScreen;

    cout << "Hello clean screen!" << endl;
    return 0;
}
