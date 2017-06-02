//twoDimExample.cpp
//August 26, 2014
//This program demonstrates a two-dim array
#include<iostream>
using namespace std;

//return type: void
//parameters: 1 3 x 4 integer array
//Purpose: This function displays the values in a 3 x 4 int array
void DisplayArray(int[3][4]);

//return type: void
//parameters: 1 3 x 4 integer array, 2 ints(col and value)
//Purpose: This function modifies the values in a particular column to a particular value.
void ModifyColumn(int[3][4], int, int);

int main()
{
	int intArr[3][4] = {{2,3,3,4}, {2,34,4,5},{5,57,3,2}};
	
	//call DisplayArray
	cout<<"Initial values stored in the array:\n";
	DisplayArray(intArr);

	//call ModifyColumn to change all of the values in the 3rd column to 5
	ModifyColumn(intArr,3,5);
	
	//call DisplayArray
	cout<<"\nValues stored in the array after function call:\n";
	DisplayArray(intArr);

 return 0;
}
//Purpose: This function displays the values in a 3 x 4 int array
void DisplayArray(int arr[3][4])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 4; j++)
			{
			cout<<arr[i][j]<<" ";
			}
		cout<<endl;
	}
}

//Purpose: This function modifies the values in a particular column to a particular value.
void ModifyColumn(int arr[3][4], int col, int val)
{
	for(int i = 0; i < 3; i++)
	{
		arr[i][col - 1] = val;
	}

}
