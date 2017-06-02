/*tttmain.cpp
  DavidMarcus and KishonDiaz
  September 20, 2014
  This is the driver for ttt.h and ttt.cpp
*/
  
/*WARNING***current configuation is used for a full
    sized terminal with out -ncurses getMaxXY function 
    to get the size of the terminal i cannot 
    adjust the centered functions Please use
    a full sized termal
 */

#include "ttt.cpp"
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*FUNCTION PROTOTYPES*/

void Centered(int);
/* 
  Name:Centered 
  return type: void
  parameters: 1 int
 /*purpose: Calls the center function from 
    Glamour class used to center the display
*/
void ColorBackGround();
/* 
  Name:Centered ColorBackGround
  return type: void
  parameters: none
 /*purpose: Calls the overloaded function BackGround(string,int)
            from the Glamour class used to color the background
            of the terminal using HEX Colors.
*/
void setBackGroundColor(string,string,string);
/*  
  Name:setBackGroundColor
  return type: void
  parameters: 3 strings
 /*purpose: Used to set the background color for the entire game
            using HEX Colors.
*/
void setPlayerColor(string,string);
/* 
  Name:setPlayerColor
  return type: void
  parameters: 2 strings
 /*purpose: Used to set the Colors of the players in the entire game
*/
void setPlayerBGColor(string,string);
/*
  Name:setPlayerBGColor  
  return type: void
  parameters: 2 strings
 /*purpose: Used to set the Colors of the players backgrounds 
    in the entire game
*/
void PlaysoundEffect(string);
/*  
  Name:PlaysoundEffect
  return type: void
  parameters: 1 string
 /*purpose: Calls the playsoundEffect function 
    from the Glamour class used to play sound effects
    can play music but not recommened to play
    music longer the 2 min
*/
string LeftCentered(int);
/* 
  Name:LeftCentered
  return type: void
  parameters: 1 int
 /*purpose: Calls the string leftCentered class from 
    the Glamour class and returns the output
    can be used as a string 
*/
string ColorText(string,string,string,string);
/* 
  Name:ColorText
  return type: string
  parameters: 3 strings
 /*purpose: Calls the string ColorText from the Glamour class
    and returns the output can be used as a string
*/


/*MAIN FUNCTION */
int main()
{
	int alternate=2;
	int currentWinner=-1,choice=0;
	string gameStart,bg,choices;
    
	TicTacToe PlayGame;
	
	//Sets Colors for the game	
	setBackGroundColor("236","1","37");
	setPlayerColor(color.textRed,"player1");
	setPlayerColor(color.textBlue,"player2");
	setPlayerBGColor(color.BGRed,"player1");
	setPlayerBGColor(color.BGBlue,"player2");
	setPlayerBGColor(color.BGYellow,"tie");
	bg = bgcolors.bg;
	//Checks Version of Sox player
	SoundErrorCheck();
	while(choice!=4)
	{	
	    //Displays color of background
		ColorBackGround();
		system("clear");
		Centered(PUSHDOWN);
		if(alternate==2)
		{
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("7","32","WELCOME TO TIC-TAC-TOE!!!\n\n\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","32","1 start a new match\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","34","2 quick match\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","36","3 show the scoreboard\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","31","4 exit\n\n",bg);
			getline(cin,choices);
		}
		else
		{
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("1;7","40","Please Make Your Selection.\n\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","32","1 start a new match\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","34","2 continue the current match\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","36","3 display the current score\n",bg);
			cout<<LeftCentered(PUSHLEFT)<<
			ColorText("4","31","4 exit\n\n",bg);
			getline(cin,choices);
		}
		
		choice = atoi(choices.c_str());
		
		if((choice < 1) or (choice > 4))
		{
			PlaysoundEffect(efx.Buzzer);
			system("clear");
			Centered(PUSHDOWN);
			cout<<LeftCentered(PUSHLEFT)
			<< "Invald choice please choose again\n";
			usleep(DELAY);
		}
		else if(choice==1)
		{
			PlaysoundEffect(efx.ShortTrump);
			system("clear");
			Centered(PUSHDOWN);
			PlayGame.SetPlayer1();
			PlayGame.SetPlayer2();
			PlayGame.Reset();
			PlayGame.ResetTies();
			alternate=2;
			
			Centered(PUSHDOWN-2);
			cout<<LeftCentered(PUSHLEFT);
			cout<<ColorText("4","32","Press enter to begin\n",bg);
			getline(cin,gameStart);
			PlaysoundEffect(efx.Suspense);
			usleep(DELAY*2);
			while(currentWinner<0)
			{
				
				PlayGame.Boarder();
				PlayGame.ChoosePosition();
				PlaysoundEffect(efx.Tick);
				currentWinner=PlayGame.CheckForWinner();
				cout << currentWinner;
				if(currentWinner<0)
				{
					PlayGame.Boarder();
					PlayGame.ChoosePosition2();
					PlaysoundEffect(efx.Tick);
					currentWinner=PlayGame.CheckForWinner();
					
				}
			}
			PlaysoundEffect(efx.FF5Victory);
			PlayGame.WinnerBoarder(currentWinner);
			PlayGame.DisplayScore(currentWinner);
			alternate++;
			
		}
		else if(choice == 2)
		{
			
			PlaysoundEffect(efx.ShortTrump);
			PlayGame.Reset();
			while(currentWinner<0)
			{
				if((alternate%2)==0)
				{
					PlayGame.Boarder();
					PlayGame.ChoosePosition();
					PlaysoundEffect(efx.Tick);
					currentWinner=PlayGame.CheckForWinner();
					if(currentWinner<0)
					{
						PlayGame.Boarder();
						PlayGame.ChoosePosition2();
						PlaysoundEffect(efx.Tick);
						currentWinner=PlayGame.CheckForWinner();
					
					}
				}
				else
				{
					PlayGame.Boarder();
					PlayGame.ChoosePosition2();
					PlaysoundEffect(efx.Tick);
					currentWinner=PlayGame.CheckForWinner();
					if(currentWinner<0)
					{
						PlayGame.Boarder();
						PlayGame.ChoosePosition();
						PlaysoundEffect(efx.Tick);
						currentWinner=PlayGame.CheckForWinner();
					
					}
				}
			}
			PlaysoundEffect(efx.TaDa);
			PlayGame.WinnerBoarder(currentWinner);
			PlayGame.DisplayScore(currentWinner);
			alternate++;
			
		}
		else if(choice ==3)
		{
		    
			PlaysoundEffect(efx.Twikle);
			PlayGame.DisplayScore(currentWinner);
		
		}
			
			
		else if(choice ==4)
		{	
			PlaysoundEffect(efx.LilGirlBye);
			system("clear");
			Centered(PUSHDOWN);
			cout<<LeftCentered(PUSHLEFT);
			cout << "Thanks for playing!!\n\n";
			usleep(DELAY*2);
			break;
		}
			
			
	}
	
	makePretty.BGColorOff();
	return 0;
}

/*MAINS FUNCTIONS*/


void Centered(int pushDown)
{
	makePretty.centered(pushDown);
	
}
 /*purpose: Calls the center function from 
    Glamour class used to center the display
*/
void ColorBackGround()
{
	
	makePretty.BackGround();	   

}
/*purpose: Calls the overloaded function BackGround(string,int)
            from the Glamour class used to color the background
            of the terminal using HEX Colors.
*/
void setBackGroundColor(string strHexColor,string strCode, string strText)
{
	makePretty.SetBackGround(strHexColor+";"+strCode+";"+strText);
	bgcolors.bg = "48;5;"+strHexColor+";"+strCode+";"+strText;
}
 /*purpose: Used to set the background color for the entire game
            using HEX Colors.
*/
void setPlayerColor(string playerTextColor,string whichPlayer)
{
	if(whichPlayer == "player1")
		bgcolors.player1Color=playerTextColor;
	else
	if(whichPlayer == "player2")
		bgcolors.player2Color=playerTextColor;
	

}
 /*purpose: Used to set the Colors of the players in the entire game
*/
void setPlayerBGColor(string playerBGColor,string whichPlayer)
{
	if(whichPlayer == "player1")
		bgcolors.player1BGC=playerBGColor;
	else
	if(whichPlayer == "player2")
		bgcolors.player2BGC=playerBGColor;
	else
	if(whichPlayer == "tie")
		bgcolors.tieBGC = playerBGColor;
}
/*purpose: Used to set the Colors of the players backgrounds 
    in the entire game
*/
void PlaysoundEffect(string playSoundLocation)
{
	makePretty.PlaySoundEffect(playSoundLocation);

}
/*purpose: Calls the playsoundEffect function 
    from the Glamour class used to play sound effects
    can play music but not recommened to play
    music longer the 2 min
*/
string LeftCentered(int pushLeft)
{
	return makePretty.leftCentered(pushLeft);
}
/*purpose: Calls the string leftCentered class from 
    the Glamour class and returns the output
    can be used as a string 
*/
string ColorText(string code,string color,string text,string BackGround)
{
	return makePretty.colorOnText(code,color,text,BackGround);
}
/*purpose: Calls the string ColorText from the Glamour class
    and returns the output can be used as a string
*/


