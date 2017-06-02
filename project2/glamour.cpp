/*glamour.cpp
  DavidMarcus and KishonDiaz
  September 20, 2014
  This is the driver for ttt.h and ttt.cpp
*/
#include "glamour.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


Colors bgColor;

void Glamour::centered(int down)
{
	
	for(int i=0; i< down; i++)
	{
		cout << "\n";
	}

}
void Glamour::BackGround(string fullHexColorCodeAndTxtColor="\0",int Size=40)
{
	string text;
	if(fullHexColorCodeAndTxtColor!="\0")
		text =(fullHexColorCodeAndTxtColor);
	else
	   text =("48;5;"+bgColor.BGCustom+"m");
	for(int i=0;i<=Size;i++)
	{
		for(int j=0; j<=Size;j++)
		{
			cout << "\033["+text << "\n";
			
		}
	}


}
void Glamour::BackGround(int Size,string strCode,string strColor)
{
	bgColor.BGColor = strColor;
	string thisColor = bgColor.BGColor = strColor;
	string text = "\033["+strCode+";"+thisColor+"m ";
	for(int i=0;i<=Size;i++)
	{
		for(int j=0; j<=Size;j++)
		{
			cout << text;
		}
	}

}
void Glamour::BackGround(string strColor,string strCode,string strText,int Size)
{
	
	string text =("48;5;"+strColor+";"+strCode+";"+strText+"m");
	for(int i=0;i<=Size;i++)
	{
		for(int j=0; j<=Size;j++)
		{
			cout << "\033["+text << "\n";
			
		}
	}


}
void Glamour::BGColorOff()
{	
	int size = 40;
	for(int i=0;i<=size;i++)
	{
		for(int j=0; j<=size;j++)
		{
			cout << "\033[0m" << endl;
			
		}
	}
	system("clear");
}
void Glamour::currentBGWinColor(string strCode,string bgs,int size=40)
{
	string text;
	text = "\033["+strCode+";"+bgs+"m \n";
	
	for(int i=0;i<=size;i++)
	{
		for(int j=0; j<=size;j++)
		{
			cout << text;
		}
	}
	strCode = "0";
	cout << "\033["+strCode+";37;"+bgs+"m ";

}
void Glamour::colorChar(int i,int j,char chalklines[3][3],string BackGround = "49")
{
	if(BackGround == "49")
	{
		if(chalklines[i][j] == ' ')
		{
			cout<<' ';
		}
		else if(chalklines[i][j] == 'X')
		{
			printf("\033[1;31m%c\033[0m",'X');
		}
		else
		if(chalklines[i][j] == 'O')
		{
			printf("\033[1;34m%c\033[0m",'O');
		}
	}
	else
	{
		if(chalklines[i][j] == ' ')
		{
			cout<<' ';
		}
		else if(chalklines[i][j] == 'X')
		{
			printf("\033[1;31m%c\033[0m",'X');
			cout << "\033["+BackGround+"m";
		}
		else
		if(chalklines[i][j] == 'O')
		{
			printf("\033[1;34m%c\033[0m",'O');
			cout << "\033["+BackGround+"m";
		}
	
	}

}
void Glamour::changeColor(int player,string whichPlayer,string Background = "49")
{
	if(Background == "49")
	{
		if(whichPlayer == "player1")
			printf("\033[1;31m%d \033[0m",player);
		else if(whichPlayer == "player2")
			printf("\033[1;34m%d \033[0m",player);
		else if(whichPlayer == "tie")
			printf("\033[22;33m%d \033[0m",player);
	}
	else
	{
		if(whichPlayer == "player1")
		{
			printf("\033[1;31m%d \033[0m",player);
			cout << "\033["+Background+"m";
	
		}
		else if(whichPlayer == "player2")
		{
			printf("\033[1;34m%d \033[0m",player);
			cout << "\033["+Background+"m";
		}
		else if(whichPlayer == "tie")
		{
			printf("\033[22;33m%d \033[0m",player);
			cout << "\033["+Background+"m";
		}
	
	
	}

}
void Glamour::colorNum(int i,int j,char chalklines[3][3] ,int RefBoard[3][3],string BackGround = "49")
{
	
	if(BackGround == "49")
	{
		if(chalklines[i][j] == ' ')
		{
			//printf("%d",RefBoard[i][j]);
		}
		else if(chalklines[i][j] == 'X')
		{
			printf("\033[1;31m%d\033[0m",RefBoard[i][j]);
		}
		else
		if(chalklines[i][j] == 'O')
		{
			printf("\033[1;34m%d\033[0m",RefBoard[i][j]);
		}
	}
	else
	{
		if(chalklines[i][j] == ' ')
		{
			//printf("%d",RefBoard[i][j]);
		}
		else if(chalklines[i][j] == 'X')
		{
			printf("\033[1;41m ");
			cout << "\033["+BackGround+"m";
		}
		else
		if(chalklines[i][j] == 'O')
		{
			//printf("\033[1;34m ");
			cout << "\033[1;44m ";
		}
		
		cout << "\033["+BackGround+"m";
	
	}

}
void Glamour::colorOn(string strCode, string strColor)
{
	cout << "\033["+strCode+";"+strColor+"m";

}
void Glamour::colorOff()
{	
	cout << "\033[0m";
}
void Glamour::winColorChar(int i,int j,char chalklines[3][3],string Background = "49")
{
	bool isPlayer;
	
	if(chalklines[i][j]=='X' and sizeof(chalklines[i][j] == 3))
		isPlayer = true;	
	else if(chalklines[i][j]=='O'and sizeof(chalklines[i][j] == 3))
		isPlayer = false;
	
	if(Background == "49")
	{
		if(isPlayer == true)
		{
			if(chalklines[i][j]== ' ')
				cout<<' ';
			else
			if((chalklines[i][j]=='X') and sizeof(chalklines[i][j] == 3)
			and(chalklines[i][j] != 'O'))
				printf("\033[1;41m%c\033[0m",'X');
			
			else
			if((chalklines[i][j]=='O')
				and chalklines[i][j] !='X')
				printf("%c",'O');
		}
		else
		{
			if(chalklines[i][j]== ' ')
				cout<<' ';
			
			else
			if((chalklines[i][j]=='O') and sizeof(chalklines[i][j] == 3)
			and(chalklines[i][j] != 'X'))
				printf("\033[1;44m%c\033[0m",'O');
		
			else
			if((chalklines[i][j]=='X')
				and chalklines[i][j] !='O')
				printf("%c",'X');
		}
	}
	else
	{
	
		if(isPlayer == true)
		{
			if(chalklines[i][j]== ' ')
				cout<<' ';
			else
			if((chalklines[i][j]=='X') and sizeof(chalklines[i][j] == 3)
			and(chalklines[i][j] != 'O'))
			{
				printf("\033[1;41m%c\033[0m",'X');
				cout << "\033["+Background+"m";
			}
			else
			if((chalklines[i][j]=='O')
			and chalklines[i][j] !='X')
			{
				printf("%c",'O');
			}
		}
		else
		{
			if(chalklines[i][j]== ' ')
				cout<<' ';
			
			else
			if((chalklines[i][j]=='O') and sizeof(chalklines[i][j] == 3)
			and(chalklines[i][j] != 'X'))
			{
				printf("\033[1;44m%c\033[0m",'O');
				cout << "\033["+Background+"m";
			}
			else
			if((chalklines[i][j]=='X')
				and chalklines[i][j] !='O')
				printf("%c",'X');
		}
	
	
	
	}

}

int Glamour::WhoIsLeading(int PlayerOne,int PlayerTwo,int Tie)
{
	static int passedInt =0;
	if(PlayerOne ==0 and PlayerTwo ==0 and Tie == 0)
	{
		passedInt=0;
	
	}
	else
	if(PlayerOne>PlayerTwo)
	{
		passedInt = 1;
	}
	else if(PlayerTwo>PlayerOne)
	{
		
		passedInt = 2;
	}
	else if((PlayerOne==PlayerTwo)or(PlayerTwo==PlayerOne))
	{
		passedInt = 3;
	}
	else
	{
		passedInt = 4;
	}
	
	return passedInt;


}
void Glamour::PlaySoundEffect(string soundLocation)
{
	string play = "play -q "+soundLocation+" &";
	system(play.c_str());


}
void SoundErrorCheck()
{
	system("play --version ");

}
void Glamour::SetBackGround(string bgHexColorAndCodeAndTextColor)
{

	bgColor.BGCustom = bgHexColorAndCodeAndTextColor;

}
string Glamour::colorOn(int i,int j,char chalklines[3][3],string code)
{
	string colorText;
	
		if(chalklines[i][j] == ' ')
		{
			
		}
		else if(chalklines[i][j] == 'X')
		{
			//printf("\033[1;31m%c\033[0m",'X');
			colorText = "\033["+code+";31m";
		}
		else
		if(chalklines[i][j] == 'O')
		{
			//printf("\033[1;34m%c\033[0m",'O');
			colorText = "\033["+code+";34m";
		}

	return colorText;
}
string Glamour::leftCentered(int left)
{
	string text;
	for(int i=0; i< left; i++)
	{
		cout << "\t";
	}
	return text;

}
string Glamour::colorOnText(string strCode,string strColor, string text, string BackGround="49")
{
	string colorText;
	if(BackGround =="49")
	{
		colorText =  "\033["+strCode+";"+strColor+"m"+text+"\033[0m";
	}
	else
	{
	
		colorText =  "\033["+strCode+";"+strColor+"m"+text+"\033[0m"+"\033["+BackGround+"m";
	}
	return colorText;
		
	
}
string Glamour::strColorOff()
{
	string text;
	cout << "\033[0m";
	return text;

}
string Glamour::ColorOffWithBG(string BackGround="49")
{
	string text;
	if(BackGround == "49")
	   cout<<"\033[0m";
	else
	   cout<<"\033[0m\033["+BackGround+"m";
	return text;

}
string Glamour::WhosColor(string player1Color,string player2Color,string tieColor,string BackGround = "49", int inLead=0)
{
	string whoToColor;
 
	
	switch(inLead)
	{
		case 0:
			whoToColor = BackGround;
			break;
		case 1:
			whoToColor = player1Color;
			break;
		case 2:
			whoToColor = player2Color;
			break;
		case 3:
			whoToColor = tieColor;
			break;
		
	
	}
	return whoToColor;
	

}
