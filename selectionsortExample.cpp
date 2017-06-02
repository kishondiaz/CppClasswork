#include<iostream>
using namespace std;

void displayArray(int array[], int size)
{
  for(int i = 0; i< size; i++)
    cout<<array[i]<<" ";
  cout<<endl;

}

void selectionSort(int array[], int size)
 {
    int startScan, minIndex, minValue;
    int pass = 0;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
       minIndex = startScan;
       minValue = array[startScan];
       for(int index = startScan + 1; index < size; index++)
       {
          if (array[index] < minValue)
         {
             minValue = array[index];
             minIndex = index;
          }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
      pass++;
      cout<<"After pass "<<pass<<": ";	
      displayArray(array, size);
  }
 }
const int SIZE = 7;
int main()
{
  //declare an array of integers
  int nums[SIZE] = {25,3,1,2,7,3,10};

  cout<<"Values in array: ";
  for(int i = 0; i < SIZE; i++)
	cout<<nums[i]<<" ";

  cout<<endl;
   
  //perform bubble sort
  selectionSort(nums, SIZE);

 
  return 0;
}
