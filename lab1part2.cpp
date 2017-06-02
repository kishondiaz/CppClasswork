#include<iostream>

using namespace std;

void AssignN(char[10][10]);

void DrawN(char[10][10]);

const int MAX_SIZE = 10;

int main()
{
	char getNs[MAX_SIZE][MAX_SIZE] = {0};
	for(int i=0; i<MAX_SIZE; i++)
	{
		for(int j=0; j<MAX_SIZE; j++)
		{
			char getNs[MAX_SIZE][MAX_SIZE] = {0};
		}
	}
	//char getNs[MAX_SIZE][MAX_SIZE] = {''};
	
	AssignN(getNs);
	DrawN(getNs);

	return 0;
}

void AssignN(char getNs[MAX_SIZE][MAX_SIZE])
{
	for(int i=0; i< MAX_SIZE; i++)
	{
		for(int j=0; j<MAX_SIZE;j++)
		{
			if(j ==0 || j == 9)
				getNs[i][j] = 'N';
			else if(i==j)
				getNs[i][j] = 'N';
			else
				getNs[i][j] = ' ';
		}
	}
}
void DrawN(char getNs[MAX_SIZE][MAX_SIZE])
{
	//cout << getNs[7][3] << " ";
	for(int i=0; i< MAX_SIZE; i++) 
	{
		for(int j=0; j< MAX_SIZE; j++)
			cout<< getNs[i][j]<< "";
		cout << endl;	
	}
	
	cout << endl;
}
