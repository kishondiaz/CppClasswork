#include<iostream>
using namespace std;
void displayArray(int arr[], int size)
{
  for(int i = 0; i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

}
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


int main()
{
  //declare an array of integers
  int nums[14] = {2,3,6,3,7,10,8,12,20, 16,15,28,30,27};
  //declare a variable for position
  int position = 0;
  int usernum;

  cout<<"Array values: "<<endl;
  displayArray(nums, 14);
  
  //perform a bubble sort to order numbers
  bubbleSort(nums, 14);
  cout<<"Ordered Array values: "<<endl;
  displayArray(nums, 14);

  cout<<"Enter a number to search for: ";
  cin>>usernum;

  //perform binary search
  //search for the number 20
  position = binarySearch(nums, 14, usernum);
  
  if(position!=-1)
    cout<<"Your number was found in position "<<position<<endl;
  else
    cout<<"Your number was not found.\n";



  return 0;

}






