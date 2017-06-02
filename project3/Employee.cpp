/*
	Name: Kishon Diaz
	Date: 12/2/14
*/
#include "Employee.h"
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include <unistd.h>

using namespace std;

	void Employee::SetName(string na)
	{
		name=na;
	}
	bool Employee::SetSocial()
	{
		int Size = strlen(ssNumber.c_str()),count=0;
		string enterCheck = "Try again: ";
			
		bool isAlpha = false,
		isDigit = false,isPunct=false,
		isDigi = false, isPunc = false, 
	    isBad = false, checkGood = false;
		
		for(int i=0;i<Size;i++)
		{
			if(isalpha(ssNumber[i]))
		 		isAlpha = true;
			if(isdigit(ssNumber[i]))
				isDigit=true;
			if(ispunct(ssNumber[i]))
				isPunct = true;
		}
		
		if(strlen(ssNumber.c_str())< 11 or strlen(ssNumber.c_str()) > 11
		 and isDigit == true and isAlpha == false and isPunct == true)
		{
			if(strlen(ssNumber.c_str())< 11)
				ErrorBox(40,30,"\033[31m"+GetError(1),bgColor,bgColor,1);

			if(strlen(ssNumber.c_str()) > 11)
				ErrorBox(40,30,"\033[31m"+GetError(2),bgColor,bgColor,2);
				
			isBad = true;
		}
		else
		{
			if(isAlpha == true)
			{
				ErrorCheck(3,true);
				ErrorNumber(3);
				ErrorBox(40,30,"\033[31m"+GetError(3),bgColor,bgColor,3);
				isBad = true;
			}
			else
			{
				if(isDigit==true or isPunct== true)
				{
					for ( int i = 0;i < Size; i++)
					{
						if(i < 3 )
						{
							if(isdigit(ssNumber[i]))
								isDigi = true;
								
							else if(ispunct(ssNumber[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}
						}
						else if(i == 3 )
						{
							if(ispunct(ssNumber[i]))
								isPunc = true;
							else if(isdigit(ssNumber[i]))
								isBad = true;
							else
							{
								isBad = false;
								isPunc = false;
							}
							
						}
						else if(i <=5)
						{
							if(isdigit(ssNumber[i]))
								isDigi = true;
							else if(ispunct(ssNumber[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}	
						}
						else if(i ==6 and !i <6)
						{
							if(ispunct(ssNumber[i]))
								isPunc = true;	
							else if(isdigit(ssNumber[i]))
								isBad = true;
							else
							{
								isBad = false;
								isPunc = false;
							}
						}
						else if(i <=10)
						{
							if(isdigit(ssNumber[i]))
								isDigi = true;
							else if(ispunct(ssNumber[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}
						}
					}
					
					if(isBad == true)
						isBad = true;
						
					else
					{
						if(isDigi == true or isPunc == true)
							checkGood = true;
						else
						{
							checkGood = false;
							isBad = false;
						}
					}
			
				}
				
			}
			if(isBad == true)
			{
				checkGood = false;
				ErrorCheck(0,true);
				ErrorBox(40,30,"\033[31m"+GetError(0),bgColor,bgColor,0);
				ssNumber = "";	
			}
		}
		return checkGood;	
	}
	bool Employee::SetSocial(string ssn)
	{
		int Size = strlen(ssn.c_str()),count=0;
			
		bool isAlpha = false,
		isDigit = false,isPunct=false,
		isDigi = false, isPunc = false, 
	    isBad = false, checkGood = false;
		
		for(int i=0;i<Size;i++)
		{
			if(isalpha(ssn[i]))
		 		isAlpha = true;
			if(isdigit(ssn[i]))
				isDigit=true;
			if(ispunct(ssn[i]))
				isPunct = true;
		}
		
		if(strlen(ssn.c_str())< 11 or strlen(ssn.c_str()) > 11 and isDigit == true and isAlpha == false and isPunct == true)
		{
			if(strlen(ssn.c_str())< 11)
				ErrorBox(40,30,"\033[31m"+GetError(1),bgColor,bgColor,1);
				
			if(strlen(ssn.c_str()) > 11)
				ErrorBox(40,30,"\033[31m"+GetError(2),bgColor,bgColor,2);
				
			isBad= true;	
		}
		else
		{
			if(isAlpha == true)
			{
				ErrorBox(40,30,"\033[31m"+GetError(3),bgColor,bgColor,3);
				isBad = true;
			}
			else
			{
				if(isDigit==true or isPunct== true)
				{
					ssNumber = ssn;

					for ( int i = 0;i < Size; i++)
					{
						if(i < 3 )
						{
							if(isdigit(ssn[i]))
								isDigi = true;
								
							else if(ispunct(ssn[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}
						}
						else if(i == 3 )
						{
							if(ispunct(ssn[i]))
								isPunc = true;

							else if(isdigit(ssn[i]))
								isBad = true;
							else
							{
								isBad = false;
								isPunc = false;
							}
							
						}
						else if(i <=5)
						{
							if(isdigit(ssn[i]))
								isDigi = true;

							else if(ispunct(ssn[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}	
						}
						else if(i ==6 and !i <6)
						{
							if(ispunct(ssn[i]))
								isPunc = true;

							else if(isdigit(ssn[i]))
								isBad = true;
							else
							{
								isBad = false;
								isPunc = false;
							}
						}
						else if(i <=10)
						{
							if(isdigit(ssn[i]))
								isDigi = true;
								
							else if(ispunct(ssn[i]))
								isBad = true;
							else
							{
								isBad = false;
								isDigi = false;
							}
						}
					}
					
					if(isBad == true)
						isBad = true;

					else
					{
						if(isDigi == true or isPunc == true)
							checkGood = true;
						else
						{
							checkGood = false;
							isBad = false;
						}
					}
			
				}
				
			}
			if(isBad == true)
			{
				checkGood = false;
				ErrorBox(40,30,"\033[31m"+GetError(0),bgColor,bgColor,0);
				ssNumber = "";	
			}
		}
		return checkGood;	
	}
	
	bool Employee::SetEmployeeNum()
	{
		int Size = strlen(employeeNum.c_str()),count=0;
		string enterCheck = "Try again: ";
		char strArray[] = "ABCDEFGHIJKLM";
			
		bool isAlpha = false,
		isDigit = false,isPunct=false,
		isDigi = false, isPunc = false,
		isAlph = false,isBad = false, 
		checkGood = false;
	    
	    for(int i=0;i<Size;i++)
		{
			if(isalpha(employeeNum[i]))
		 		isAlpha = true;
			if(isdigit(employeeNum[i]))
				isDigit=true;
			if(ispunct(employeeNum[i]))
				isPunct = true;
		}
		if(strlen(employeeNum.c_str())< 5 or strlen(employeeNum.c_str()) > 5 and 
		isDigit == true and isAlpha == true and isPunct == true)
		{
			if(strlen(employeeNum.c_str())< 5)
			{
				ErrorCheck(5,true);
				ErrorNumber(5);
				ErrorBox(40,30,"\033[31m"+GetError(5),bgColor,bgColor,5);
			}
	
			if(strlen(employeeNum.c_str()) > 5)
			{
				ErrorCheck(6,true);
				ErrorNumber(6);
				ErrorBox(40,30,"\033[31m"+GetError(6),bgColor,bgColor,6);
			}
			
			isBad = true;
		
		}
		else
		{
			if(isDigit == true and isAlpha == true and isPunct == true)
			{	
				employeeNum = employeeNum;			
				for (int i = 0; i < Size; i += 1)
				{
					if(i < 3)
					{
						if(isdigit(employeeNum[i]))
							isDigi = true;	
							
						else if(ispunct(employeeNum[i]) or isalpha(employeeNum[i]))
							isBad = true;
						else
						{
							isBad = false;
							isDigi = false;
							isAlph = false;
						}
					
					}
					else if (i == 3)
					{
						if(ispunct(employeeNum[i]))
							isPunc = true;	
						else if(isdigit(employeeNum[i]))
							isBad = true;
						else
						{
							isBad = false;
							isPunc = false;
						}
							
					}	
					else if (i <= 4)
					{
						if(islower(employeeNum[i]))
								isBad = true;
						else
						{
							if(isalpha(employeeNum[i]))
							{
								switch(employeeNum[i])
								{
									case 'A': 
										isAlph = true;
										break;
									case 'B': 
										isAlph = true;
										break;
									case 'C': 
										isAlph = true;
										break;
									case 'D': 
										isAlph = true;
										break;
									case 'E': 
										isAlph = true;
										break;
									case 'F': 
										isAlph = true;
										break;
									case 'G': 
										isAlph = true;
										break;
									case 'H': 
										isAlph = true;
										break;
									case 'I': 
										isAlph = true;
										break;
									case 'J': 
										isAlph = true;
										break;
									case 'K': 
										isAlph = true;
										break;
									case 'L': 
										isAlph = true;
										break;
									case 'M': 
										isAlph = true;
										break;
									default:
										isBad = true;
								}
							}
							else if(isdigit(employeeNum[i]) or ispunct(employeeNum[i]))
								isBad = true;
							else
							{
								isBad = false;
								isPunc = false;
							}
							
						}
					}
					if(isBad == true)
					{
		
						isBad ==  true;
		
					}
					else
					{
					
						if(isAlph == true and isDigi == true and isPunc == true)
							checkGood = true;
					
					}
				}
			}
			else
				isBad = true;
		}
		if(isBad == true)
		{
			checkGood = false;
			ErrorCheck(4,true);
			ErrorNumber(4);
			ErrorBox(40,30,"\033[31m"+GetError(4),bgColor,bgColor,4);
		}
		
		return checkGood;
		
	}
	
	bool Employee::SetEmployeeNum(string & em)
	{
	
		int Size = strlen(em.c_str()),count=0;
		string enterCheck = "Try again: ";
		char strArray[] = "ABCDEFGHIJKLM";
			
		bool isAlpha = false,
		isDigit = false,isPunct=false,
		isDigi = false, isPunc = false,
		isAlph = false,isBad = false, 
		checkGood = false;
		
		 for(int i=0;i<Size;i++)
		{
			if(isalpha(em[i]))
		 		isAlpha = true;
			if(isdigit(em[i]))
				isDigit=true;
			if(ispunct(em[i]))
				isPunct = true;
		}
		if(strlen(em.c_str())< 5 or strlen(em.c_str()) > 5 and 
		isDigit == true and isAlpha == true and isPunct == true)
		{
			
			if(strlen(em.c_str())< 5)
			{	
				ErrorBox(40,30,"\033[31m"+GetError(5),bgColor,bgColor,5);
			}
			if(strlen(em.c_str()) > 5)
			{	
				ErrorBox(40,30,"\033[31m"+GetError(6),bgColor,bgColor,6);	
			}
			
			isBad = true;
		
		}
		else
		{
			if(isDigit == true and isAlpha == true and isPunct == true)
			{	
				employeeNum = em;			
				for (int i = 0; i < Size; i += 1)
				{
					if(i < 3)
					{
						if(isdigit(em[i]))
						{	
							isDigi = true;
			
						}
						else if(ispunct(em[i]) or isalpha(em[i]))
						{
							isBad = true;
						}
						else
						{
							isBad = true;
						}
					}
					else if (i == 3)
					{
						if(ispunct(em[i]))
						{
							isPunc = true;	
						}
						else if(isdigit(em[i]))
							isBad = true;
						else
						{
							isBad = true;
						}
							
					}
					else if (i <= 4)
					{
						if(islower(em[i]))
						{
							isBad = true;
						}
						else
						{
							if(isalpha(em[i]))
							{
								switch(em[i])
								{
									case 'A': 
										isAlph = true;
										break;
									case 'B': 
										isAlph = true;
										break;
									case 'C': 
										isAlph = true;
										break;
									case 'D': 
										isAlph = true;
										break;
									case 'E': 
										isAlph = true;
										break;
									case 'F': 
										isAlph = true;
										break;
									case 'G': 
										isAlph = true;
										break;
									case 'H': 
										isAlph = true;
										break;
									case 'I': 
										isAlph = true;
										break;
									case 'J': 
										isAlph = true;
										break;
									case 'K': 
										isAlph = true;
										break;
									case 'L': 
										isAlph = true;
										break;
									case 'M': 
										isAlph = true;
										break;
									default:
										isBad = true;
								}
								
							}
							else if(isdigit(em[i]) or ispunct(em[i]))
								isBad = true;
							else
							{	
								isBad = true;

							}
						
						 }
						
					  }
				  }
			   }
			   else
			   {
			   
			   	 isBad = true;
			   }
		  }
	
		if(isBad == true)
		{
			checkGood = false;
			
			ErrorBox(40,30,"\033[31m"+GetError(4),bgColor,bgColor,4);
		}
		if(isAlph == true and isDigi == true and isPunc == true)
		{
			checkGood = true;
		}
		return checkGood;
		
		
	}
	bool Employee::SetDayHire(string & date)
	{
		int Size = strlen(date.c_str());
		bool isDateRight = true,isPuncRight=true,isPunc2Right=true,
		isDigit=false,isAlpha =false, isBad = false,checkGood=false;
		char charPunc ='\0',charPunc2 ='\0';
		string month,day,year,punc,punc2;
	
		for(int i=0;i<Size;i++)
		{
			if(isdigit(date[i]))
				isDigit = true;
			if(isalpha(date[i]))
				isAlpha = true;
		}
	
		if(isAlpha == true)
		{

				if(Size < 11 or Size > 11 and isDigit == false and isAlpha == true)
				{
					for (int i = 0; i < Size; i += 1)
					{
						if(isdigit(date[i]))
						{
							isBad = true;
						}
						else
							isBad== false;
					
					}
					if(isBad == false)
					{
						if(Size < 11)
						{	
							ErrorCheck(7,true);
							ErrorNumber(7);
							ErrorBox(40,30,"\033[31m"+GetError(7),bgColor,bgColor,7);
						}
						if(Size > 11)
						{	
							ErrorCheck(8,true);
							ErrorNumber(8);
							ErrorBox(40,30,"\033[31m"+GetError(8),bgColor,bgColor,8);
						}
					}
					isBad = true;
				}
				for (int i = 0; i < Size; i += 1)
				{
			
					if(i < 3)
					{
						if(isalpha(date[i]))
						{
						
							month += date[i];
						}
						else
							isBad = true;
						
					}
					else if(i == 3)
					{
						if(ispunct(date[i]))
						{
							punc = date[i]; 
						}
						else
							isBad = true;
						if(punc == "," or punc == "-")
						{
							punc = punc[0];
							isDateRight = true;
						}
						else
						{
							isBad = true;
						}		
				
					}
					else if(i <= 5)
					{
						if(isdigit(date[i]))
						{
							day +=  date[i];
						}
						else
							isBad = true;
					}
					else if( i ==6)
					{
						if(ispunct(date[i]))
						{
							punc2 = date[i]; 
						}
						else
							isBad = true;
						
						if(punc2 == "," or punc2 == "-")
						{
							punc2 = punc2[0];
							isDateRight = true;
						}
						else
						{
							isBad = true;
						}		
					}
					else if(i <= 11)
					{
						if(isdigit(date[i]))
						{
							year +=  date[i];
						}
						else
							isBad = true;
					}
				}
				if(punc == punc2)
				{
					isDateRight = true;
			
				}
				else
					isBad = true;
		
			}
			else
			{
				if(isDigit == true)
				{
					for(int i=0;i<Size;i++)
					{
						if(i < 2)
						{
							if(isdigit(date[i]))
							{
								month += date[i];
								isDateRight = true;
							}
							else
								isBad = true;

						}
						else
						if(i==2)
						{
							if(ispunct(date[i]))
							{
								punc += date[i];
								isDateRight = true;
							}
							else
							{
								isBad = true;
							}
							if(punc == "/" or punc == "-")
							{
								punc = punc[0];
							}
							else
							{
								isBad = true;
							}	
						}
						else
						if(i>2 and i<5)
						{
							day+= date[i];
							isDateRight = true;
						}
						else
						if(i==5)
						{
							if(ispunct(date[i]))
							{
								punc2 = date[i];
								isDateRight = true;
							}
							else
							{
								isBad = true;
							}
							if(punc2 == "/" or punc2 == "-")
							{
								punc2 = punc2[0];
								isDateRight = true;
							}
							else
							{
								isBad = true;
								
							}
							
						}
						else
						if(i>=6)
						{
							if(isdigit(date[i]))
							{
								year+=date[i];
								isDateRight = true;
							}
							else
								isBad=true;
							
						}
					}
					if(strlen(year.c_str()) < 4 and strlen(month.c_str()) <=2 and strlen(month.c_str()) <=2)
					{
						isDateRight = false;
	
					}
				
				}
				else
				{
					isBad = true;
	
				}
			}
			if(punc == punc2)
					{
						isDateRight = true;
					}
					else
					{
						isBad = true;
					}
					if(year == "\0")
					{
						isDateRight = false;
						
					}
					if(isDateRight == true)
					{
						for(int i=0;i<Size;i++)
						{
							if(isdigit(month[i]) and isdigit(day[i]) and isdigit(year[i]))
								isDigit = true;
							if(isdigit(month[i]) or isdigit(day[i]) or isdigit(year[i]))
								isAlpha = true;
						}
				
						if(isDigit = true)
							date = month+punc+day+punc+year;
						else
							isBad = true;	
					}
					else
					{
						date = "";
						isBad = true;
					}
			if(isDateRight == true)
			{
				checkGood = true;
			
			}
		
			if(isBad == true)
			{
				
				ErrorCheck(9,true);
				ErrorNumber(9);
				ErrorBox(40,30,"\033[31m"+GetError(9),bgColor,bgColor,9);
				checkGood = false;
			}
	
		hireDate=date;
		return checkGood;
	}
	void Employee::SetDayHired(string dateHired)
	{
		
		hireDate=isHireDate(dateHired);
	}
	string Employee::GetName()
	{
		return name;
	}
	string Employee::GetSocial()
	{
		return ssNumber;
	}
	string Employee::GetEmployeeNum()
	{
		return employeeNum;
	}
	string Employee::GetDayHired()
	{
		return hireDate;
	}
	string Employee::isHireDate(string date)
	{
		int Size = strlen(date.c_str());
		bool isDateRight = true,isPuncRight=true,isPunc2Right=true,
		isDigit=false,isAlpha =false, isBad = false;
		char charPunc ='\0',charPunc2 ='\0';
		string month,day,year,punc,punc2;
	
		for(int i=0;i<Size;i++)
		{
			if(isdigit(date[i]))
				isDigit = true;
			if(isalpha(date[i]))
				isAlpha = true;
		}
	
		if(isAlpha == true)
		{

				if(Size < 11 or Size > 11 and isDigit == false and isAlpha == true)
				{
					for (int i = 0; i < Size; i += 1)
					{
						if(isdigit(date[i]))
						{
							isBad = true;
						}
						else
							isBad== false;
					
					}
					if(isBad == false)
					{
						if(Size < 11)
						{	
							ErrorCheck(7,true);
							ErrorBox(40,30,"\033[31m"+GetError(7),bgColor,bgColor,7);
						}
						if(Size > 11)
						{
							ErrorCheck(8,true);
							ErrorBox(40,30,"\033[31m"+GetError(8),bgColor,bgColor,8);
						}
											
					}
					isBad = true;
				}
				for (int i = 0; i < Size; i += 1)
				{
			
					if(i < 3)
					{
						if(isalpha(date[i]))
						{
						
							month += date[i];
						}
						else
							isBad = true;
						
					}
					else if(i == 3)
					{
						if(ispunct(date[i]))
						{
							punc = date[i]; 
						}
						else
							isBad = true;
						if(punc == "," or punc == "-")
						{
							punc = punc[0];
							isDateRight = true;
						}
						else
						{
							isBad = true;
						}		
				
					}
					else if(i <= 5)
					{
						if(isdigit(date[i]))
						{
							day +=  date[i];
						}
						else
							isBad = true;
					}
					else if( i ==6)
					{
						if(ispunct(date[i]))
						{
							punc2 = date[i]; 
						}
						else
							isBad = true;
						
						if(punc2 == "," or punc2 == "-")
						{
							punc2 = punc2[0];
							isDateRight = true;
						}
						else
						{
							isBad = true;
						}		
					}
					else if(i <= 11)
					{
						if(isdigit(date[i]))
						{
							year +=  date[i];
						}
						else
							isBad = true;
					}
				}
				if(punc == punc2)
				{
					isDateRight = true;
			
				}
				else
					isBad = true;
		
			}
			else
			{
				if(isDigit == true)
				{
					for(int i=0;i<Size;i++)
					{
						if(i < 2)
						{
							if(isdigit(date[i]))
							{
								month += date[i];
								isDateRight = true;
							}
							else
								isBad = true;

						}
						else
						if(i==2)
						{
							if(ispunct(date[i]))
							{
								punc += date[i];
								isDateRight = true;
							}
							else
							{
								isBad = true;
							}
							if(punc == "/" or punc == "-")
							{
								punc = punc[0];
							}
							else
							{
								isBad = true;
							}	
						}
						else
						if(i>2 and i<5)
						{
							day+= date[i];
							isDateRight = true;
						}
						else
						if(i==5)
						{
							if(ispunct(date[i]))
							{
								punc2 = date[i];
								isDateRight = true;
							}
							else
							{
								isBad = true;
							}
							if(punc2 == "/" or punc2 == "-")
							{
								punc2 = punc2[0];
								isDateRight = true;
							}
							else
							{
								isBad = true;
								
							}
							
						}
						else
						if(i>=6)
						{
							if(isdigit(date[i]))
							{
								year+=date[i];
								isDateRight = true;
							}
							else
								isBad=true;
							
						}
					}
					if(strlen(year.c_str()) < 4 and strlen(month.c_str()) <=2 and strlen(month.c_str()) <=2)
					{
						isDateRight = false;
	
					}
				
				}
				else
				{
					isBad = true;
	
				}
			}
			if(punc == punc2)
					{
						isDateRight = true;
					}
					else
					{
						isBad = true;
					}
					if(year == "\0")
					{
						isDateRight = false;
					
					}
					if(isDateRight == true)
					{
						for(int i=0;i<Size;i++)
						{
							if(isdigit(month[i]) and isdigit(day[i]) and isdigit(year[i]))
								isDigit = true;
							if(isdigit(month[i]) or isdigit(day[i]) or isdigit(year[i]))
								isAlpha = true;
						}
				
						if(isDigit = true)
							date = month+punc+day+punc+year;
						else
							isBad = true;	
					}
					else
					{
						date = "";
						isBad = true;
					}
		
			if(isBad == true)
			{
				ErrorCheck(9,true);
				ErrorBox(40,30,"\033[31m"+GetError(9),bgColor,bgColor,9);
				return "";
			}
	
	return date;
	
	}
	void Employee::Display()
	{
		cout.precision(2);
		cout << fixed;
		cout << "Employee Name: "<< GetName()+"\n";
		cout << "Employee Social Security Number: "<< GetSocial()+"\n";
		cout << "Employee Number: "<< GetEmployeeNum()+"\n"; 
		cout << "Employee Hired Date: "<< GetDayHired()+"\n";	
		
	}
	bool Employee::ErrorCheck(int err,bool errorout = false)
	{
		Errors e;	
		if(errorout == false)
		{
		
			errorout = false;
		}
		else
		{
			for (int i = 0; i < 15; i += 1)
			{
				if(err <= 15)
				{
					errcheck[i] = e.errors[err];
				
				}
			
			}
			errorout = true;
		}
		
		errnum = err;
		return errorout;
	
	}
	string Employee::GetError(int err=0)
	{
		return errcheck[err];
	
	}
	void Employee::ErrorNumber(int err)
	{
		errnum	= err;
	
	}
	int Employee::GetErrorNumber()
	{
		return errnum;
	}
	void Employee::ErrorBox(int x,int y,string text,string Fbg,string bg,int err)
	{
		for (unsigned int i = 0; i < 20; i += 1)
		{
			cout << "\033[48;5;4m";
	
		}
		ErrorCheck(err,true);
		PrintBox(x-8,y-5,20,100,Fbg,"7");
		mvprint(x-8,y-5,"ERRORS",Fbg,"7");
		mvprint(x,y,text,Fbg,"7");
	
	}
	void Employee::PrintBox(int x,int y,int row,int col,string Fbg,string bk)
	{

		string boarder[100][100] = {};
		stringstream sX;
		sX << y-1;
		cout << "\033["+sX.str()+"H";
		
		row = row -1;
		col = col-1;
		for (int i = 0; i < row; i += 1)
		{
			cout.width(x-1);
			for (int j = 0; j < col; j += 1)
			{
				if(j<=0 or j>=col-1)
				{
					boarder[i][j] = " ";
					cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
				}
				else if(i<=0 or i>=row-1)
				{
					boarder[i][j] = " ";
					cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
				}
				else
				{
					boarder[i][j] = "\033[2;48;5;"+bk+"m \033[0m";
					cout << boarder[i][j]<<"\033[48;5;"+Fbg+"m";
				}
			}
			cout << endl;	
		}
	}
	void Employee::mvprint(int x,int y,string text,string Fgb,string bg="49")
	{
		stringstream sx,sy;
		sx << x;sy<<y;
	
		if(bg == "49")
		{
			cout<<"\033["+sy.str()+";"+sx.str()+"H"+text;
		}
		else
		{
			cout<<"\033[48;5;"+bg+";30m"+
			"\033["+sy.str()+";"+sx.str()+"H"+text+"\033[48;5;"+Fgb+"m";	
		}
		
	}
	

