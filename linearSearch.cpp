#include<iostream>
using namespace std;
void displayArray(int arr[], int size)
{
  for(int i = 0; i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

}
int linearSearch(int list[], int numElems, int value)
{   int index = 0;      // Used as a subscript to search array
    int position = -1;  // To record position of search value   
    bool found = false; // Flag to indicate if value was found   
    int count = 0;
    while (index < numElems && !found)   
    {      
    if (list[index] == value) // If the value is found      
       {
        found = true; // Set the flag 
        position = index; // Record the value's subscript      
       }
    index++; // Go to the next element   
    count++;
    cout<<"Count: "<<count<<endl;
    }
    return position; // Return the position, or -1
}

int main()
{
  //declare an array of integers
  int nums[15] = {2,3,6,3,7,10,8,12,20, 16,15,28,30,27,40};
  //declare a variable for position
  int position = 0;
  int usernum;

  cout<<"Array values: "<<endl;
  displayArray(nums, 15);
  cout<<"Enter a number to search for: ";
  cin>>usernum;
  //perform linear search
  //search for the number 20
  position = linearSearch(nums, 15, usernum);
  
  if(position!=-1)
    cout<<"Your number was found in position "<<position<<endl;
  else
    cout<<"Your number was not found.\n";



  return 0;

}






