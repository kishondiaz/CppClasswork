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
      displayArray(array, size);
  }
 }
