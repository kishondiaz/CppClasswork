#include<iostream>
using namespace std;

void displayArray(int array[], int size)
{
  for(int i = 0; i< size; i++)
    cout<<array[i]<<" ";
  cout<<endl;

}

void bubbleSort(int array[] ,  int size)
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
		displayArray(array, size);	
	}
	while(swap == true);
}


