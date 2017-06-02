#include<iostream>
using namespace std;

void displayArray(int array[], int size)
{
  for(int i = 0; i< size; i++)
    cout<<array[i]<<" ";
  cout<<endl;

}

void bubbleSort(int array[] , int size)
{
	bool swap;
	int temp;
	int pass = 0;
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
		pass++;
		//display array after each pass thorugh loop
		cout<<"After pass "<<pass<<": ";
		displayArray(array, size);	
	}
	while(swap == true);
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
  bubbleSort(nums, SIZE);

 
  return 0;
}
