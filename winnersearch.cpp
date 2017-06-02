#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iomanip>
/*
   winnersearch.cpp
   September 10, 2014
   Kishon Diaz
    
*/
using namespace std;
/*FUNCTION PROTOTYPES*/

void OrderByName(string[],float[],int);
/*  
  return type: void
  parameters: 1 string array,1 float array, 1 int 
 /*purpose: to arrange the name array in alphabetical order     		   
*/
void OrderByScore(string[], float[],int);
/*  
  return type: void
  parameters: 1 string array,1 float array,1 int
 /*purpose: to arrange the scores array from 
   highest to lowest order.    	   
*/
void GetFile(ifstream&,string[],float[],int&);
/*  
  return type: void
  parameters: 1 ifstream,1 string array,1 float array, 1 int 
 /*purpose: to get the info from file     		   
*/
void PrintArray(string[],float[],int);
/*  
  return type: void
  parameters: 1 string array,1 float array, 1 int 
 /*purpose: to print out the info from the file     		   
*/

int SearchForWinner(string&,string[],float[],int);
/*  
  return type: int
  parameters: 1 string array, 1 float array, 1 int
 /*purpose: Returns an integer, which represents
   the position in the array in which the value
   is found.    
*/

int main()
{
    
    const int INITIAL_SIZE = 100;
    string names[INITIAL_SIZE],name[INITIAL_SIZE];
    string wrongName;
    float scores[INITIAL_SIZE] = {0.0};
    for(int i=0;i<INITIAL_SIZE;i++)
        scores[i] = 0.0;
    int count = 0,positions=0;
    bool running = true;
    
    ifstream infile;
    
    GetFile(infile,names,scores,count);
   
   
    OrderByScore(names,scores,count);
    cout << endl;
    OrderByName(names,scores,count);
    cout << endl;
   
    positions = SearchForWinner(wrongName,names,scores,count);
    
    if(positions!=-1)
        cout<<"Search found "<<names[positions]<< endl;
    else if(positions == -1)
        cout<<wrongName<<" not found" << endl;
         
    infile.close();
    return 0;
}

/*
    purpose: to arrange the name array in alphabetical order     		   
*/
void OrderByName(string names[],float scores[],int size)
{
    int scanning = 0, minIndex = 0, minValue = 0;
    int pass = 0;
    string startA;
    for(scanning=0;scanning<(size - 1);scanning++)
    {
        minIndex = scanning;
        minValue = scores[scanning];
        startA = names[scanning];
        for(int index=scanning +1; index < size; index++)
        {
            if(names[index] < startA)
            {
                startA = names[index];
                minValue = scores[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[scanning];
        scores[minIndex] = scores[scanning];
        names[scanning] = startA;
        scores[scanning] = minValue;  
    }
    cout << "\033[1;3;34mUsing selection sort\033[0m\n";
    PrintArray(names,scores,size);
}
/*
   purpose: to arrange the scores array from 
   highest to lowest order.    	   
*/
void OrderByScore(string names[], float scores[],int size)
{
    bool swapping;
    int temp=0, passThrough=0;
    string reOrder;
    cout << "\033[1;3;34mUsing Bubble Sort\033[0m\n";
    do
    {
        passThrough++;
        swapping = false;
        for(int count=0; count < (size -1); count++)
        {
            if(scores[count] < scores[count + 1])
            {
                temp = scores[count];
                reOrder = names[count];
                scores[count] = scores[count+1];
                names[count] = names[count +1];
                scores[count+1] = temp;
                names[count+1] = reOrder;
                swapping = true;
            }
        }
        cout <<"\033[1;4mPassThough\033[0m: "<< passThrough << endl;
        PrintArray(names,scores,size);
    }
    while(swapping == true);
}
 /*
    purpose: to get the info from file     		   
*/
void GetFile(ifstream & infile,string names[],float scores[],int &count)
{
    infile.open("winners.txt", ios::in);
   infile >> names[count] >> scores[count];
   while(infile )
   {
     count++;
     infile >> names[count] >> scores[count];           
    }
    infile.close(); 
    
    //Print orignal names from file
    cout << endl;
    cout << "\033[1;3;34mStarting Names From File:\033[0m\n";
    PrintArray(names,scores,count);
    
}
/*
    purpose: to print out the info from the file     		   
*/
void PrintArray(string names[],float scores[],int count)
{
    for(int i=0;i<count;i++)
          cout <<names[i]<<" "<<scores[i] <<"\n";
    cout << endl; 
}
/*
   purpose: Returns an integer, which represents
   the position in the array in which the value
   is found.    
*/
int SearchForWinner(string & wrongName,string names[],float scores[],int size)
{
    int count = 0;
    int first = 0, last =(size-1),
    middle ,position = -1;
    string value,strPosition;
    bool found = false;
    
    cout << "\033[1;4;34mEnter a name to search\033[0m\n";
    cin >> value;
    
    while(!found && first <= last)
    {
        count++;
        middle = (first + last)/2;
        if(names[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if(names[middle] > value)
            last = middle -1;
        else
            first = middle + 1; 
    }
     switch(position)
     {
        case 0:
            strPosition= "first position";
            break;
        case 1:
            strPosition="st";
            break;
        case 2:
            strPosition="nd";
            break;
        case 3:
            strPosition="rd";
            break;
        default:
            strPosition="th";
            break;
     }
     if(position == -1)
        wrongName = value;
     else if(position == 0)
        cout <<"Index " << position<<" = "<<strPosition<<"\n";
     else
     {
        cout <<"Index " << position<<" = "<<position<<strPosition
        <<" position";
        cout << endl;
     }
    return position;
}

