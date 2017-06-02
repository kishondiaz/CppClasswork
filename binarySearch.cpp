#include<iostream>
using namespace std;


void bubbleSort(int array[] , int size)
{
	bool swap;
	int temp;
	
	do
	{	
		 swap = false;
		for(int count = 0; count < (size -1 ); count++)
		{
			if(array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count+1];
				array[count+1] = temp;
				swap = true;
			}
		}
	}
	while(swap == true);
}
int binarySearch(int array[], int size, int value)
{      int count = 0;
       int first = 0,             // First array element
       last = size - 1,       // Last array element
       middle,                // Mid point of search
       position = -1;         // Position of search value
      bool found = false;        // Flag

   while (!found && first <= last)
   {
      middle = (first + last) / 2;     // Calculate mid point
      if (array[middle] == value)      // If value is found at mid
      {
         found = true;
         position = middle;
      }
      else if (array[middle] > value)  // If value is in lower half
         last = middle - 1;
      else
         first = middle + 1;           // If value is in upper half
      count++;
      cout<<"Count: "<<count<<endl;
   }
   return position;
}


