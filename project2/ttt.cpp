/*ttt.cpp
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

#include"ttt.h"

#include"glamour.cpp"
#include<string>
#include<unistd.h>
#include<cstdlib>
#include<iostream>
#include<ctype.h>

using namespace std;

Glamour makePretty;
Colors color;
BGColors bgcolors;
SoundEfx efx;

//constants used overall in the game
//DELAY is used for usleep 
const int DELAY = 1000000;
/*
    PUSHLEFT is used to move the displayed text to the left
    PUSHDOWN is used to move the displayed text to the center
             terminal
    VARDW is used for a variation variable to adjust the center
          of a text in the terminal 
*/
const int PUSHLEFT = 10,PUSHDOWN = 20, VARDW=10;



void TicTacToe::Boarder()
{
	int i,j;
	int count=1;
	string bg = bgcolors.bg;
	

	for(i=0;i<MAX_SIZE;i++)
	{
		for(j=0;j<MAX_SIZE;j++)
		{
			RefBoard[i][j]=count;
			count++;
		}	
	}
	system("clear");
	makePretty.centered(PUSHDOWN);
	for(i=0;i< 2;i++)
	{	cout<<makePretty.leftCentered(PUSHLEFT);
		for(j=0;j<2;j++)
		{
			cout << makePretty.colorOn(i,j,chalklines,"9")
			<<RefBoard[i][j];	
			cout<<makePretty.ColorOffWithBG(bg)<<" | ";	
		}
	cout << makePretty.colorOn(i,j,chalklines,"9")
	<<RefBoard[i][j];
	cout<<makePretty.ColorOffWithBG(bg)<<endl;
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"---------"<<endl;	
	}
	cout<<makePretty.leftCentered(PUSHLEFT);
	j=0;
	cout << makePretty.colorOn(i,j,chalklines,"9")
	<<RefBoard[i][j];
	cout<<makePretty.ColorOffWithBG(bg)<<" | ";
	j++;
	cout << makePretty.colorOn(i,j,chalklines,"9")
	<<RefBoard[i][j];
	cout<<makePretty.ColorOffWithBG(bg)<<" | ";
	j++;
	cout << makePretty.colorOn(i,j,chalklines,"9")
	<<RefBoard[i][j];
	cout<<makePretty.ColorOffWithBG(bg)
	<<endl<<endl<<endl;
	
	for(i=0;i< 2;i++)
	{
		cout<<makePretty.leftCentered(PUSHLEFT);
		for(j=0;j<2;j++)
		{
			makePretty.colorChar(i,j,chalklines,bg);
			cout<<" | ";			
		}
	makePretty.colorChar(i,j,chalklines,bg);
	cout<<endl;
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"---------"<<endl;	
	}
	cout<<makePretty.leftCentered(PUSHLEFT);
	j=0;
	makePretty.colorChar(i,j,chalklines,bg);
	cout<<" | ";
	j++;
	makePretty.colorChar(i,j,chalklines,bg);
	cout<<" | ";
	j++;
	makePretty.colorChar(i,j,chalklines,bg);
	cout<<"\n\n";


}
void TicTacToe::ChoosePosition()
{
	string thisPosition, escape;
	string bg = bgcolors.bg,
	player1Color = bgcolors.player1Color;
	int position=0,a=0,b=0,runAwayLoopEscape = 0;
	static int counts = 0;
	bool update = false;
	while(update == false)
	{	
		cout << thisPosition << position;
		cout<<makePretty.leftCentered(PUSHLEFT-1);
		cout<<makePretty.colorOnText("1",player1Color,Player1.name,bg)
		<<", where would you like to place your "<<Player1.symbol<<"?\n";
		cout<<makePretty.leftCentered(PUSHLEFT);
		getline(cin,thisPosition);
		position = atoi(thisPosition.c_str());
		while(position <1 or position >9)
		{
			if(thisPosition == "\0")
			{
				runAwayLoopEscape++;
				
			}
			cout << endl;
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.Sigh);
			usleep(DELAY*2);
			makePretty.PlaySoundEffect(efx.SlowNo);
			cout<<makePretty.leftCentered(PUSHLEFT-1);
			cout << "Invald selection, please choose again.\n\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			getline(cin,thisPosition);
			if(thisPosition == "")
			{
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "Cannot be Blank\n";
				
			}
			if(runAwayLoopEscape == 3)
			{
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "You have ether pressed enter to fast\n" ;
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout<<"or enter to many times\n";
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout<<"Please Wait!!\n\n";
				usleep(DELAY*2);
				runAwayLoopEscape =0;
			}	
			position = atoi(thisPosition.c_str());
			
		}
		
			if(position ==1)
			{
				a=0;
				b=0;
			}
			else if(position == 2)
			{
				a=0;
				b=1;
			}
			else if(position == 3)
			{
				a=0;
				b=2;
			}
			else if(position == 4)
			{
				a=1;
				b=0;
			}
			else if(position == 5)
			{
				a=1;
				b=1;
			}
			else if(position == 6)
			{
				a=1;
				b=2;
			}
			else if(position == 7)
			{
				a=2;
				b=0;
			}
			else if(position == 8)
			{
				a=2;
				b=1;
			}
			else if(position == 9)
			{
				a=2;
				b=2;
			}

			if(chalklines[a][b]== ' ')
			{
				chalklines[a][b] = Player1.symbol;
				update = true;
			}
			else
			{
				makePretty.PlaySoundEffect(efx.ComeOnYouCanDoIt);
				cout<<makePretty.leftCentered(PUSHLEFT-1);
				cout << "Space is already taken, please choose again.\n\n";
				update = false;	
			}
		
	}

}
void TicTacToe::ChoosePosition2()
{
	string thisPosition;
	string bg = bgcolors.bg,
	player2Color = bgcolors.player2Color;
	int position=0,a=0,b=0,runAwayLoopEscape=0;
	static int counts = 0;
	bool update = false;
	while(update == false)
	{
		
		cout<<makePretty.leftCentered(PUSHLEFT-1);
		cout<<makePretty.colorOnText("1",player2Color,Player2.name,bg)
		<<", where would you like to place your "<<Player2.symbol<<"?\n";
		cout<<makePretty.leftCentered(PUSHLEFT);
		getline(cin,thisPosition);
		position = atoi(thisPosition.c_str()); 
		while(position <1 or position >9)
		{
			if(thisPosition == "\0")
			{
				runAwayLoopEscape++;
				
			}
			cout << endl;
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.Sigh);
			usleep(DELAY*2);
			makePretty.PlaySoundEffect(efx.SlowNo);
			cout<<makePretty.leftCentered(PUSHLEFT-1);
			cout << "Invald choose please choose again\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			getline(cin,thisPosition);
			if(thisPosition == "")
			{
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "Cannot be Blank\n";
			}
			if(runAwayLoopEscape == 3)
			{
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "You have ether pressed enter to fast\n" ;
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout<<"or enter to many times\n";
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout<<"Please Wait!!\n\n";
				usleep(DELAY*2);
				runAwayLoopEscape =0;
			}	
		    position = atoi(thisPosition.c_str());
		}
		
			if(position ==1)
			{
				a=0;
				b=0;
			}
			else if(position == 2)
			{
				a=0;
				b=1;
			}
			else if(position == 3)
			{
				a=0;
				b=2;
			}
			else if(position == 4)
			{
				a=1;
				b=0;
			}
			else if(position == 5)
			{
				a=1;
				b=1;
			}
			else if(position == 6)
			{
				a=1;
				b=2;
			}
			else if(position == 7)
			{
				a=2;
				b=0;
			}
			else if(position == 8)
			{
				a=2;
				b=1;
			}
			else if(position == 9)
			{
				a=2;
				b=2;
			}

			if(chalklines[a][b]== ' ')
			{
				chalklines[a][b] = Player2.symbol;
				update = true;
			}
			else
			{
				makePretty.PlaySoundEffect(efx.ComeOnYouCanDoIt);
				cout<<makePretty.leftCentered(PUSHLEFT-1);
				cout << "Space is already taken, please choose again.\n\n";
				update = false;	
			}
		
	}
}
void TicTacToe::Reset()
{
	for(int i=0; i<MAX_SIZE; i++)
		{
			for(int j=0; j<MAX_SIZE; j++)
				chalklines[i][j]= ' ';
		}
		
}
	
void TicTacToe::DisplayScore(int &currentWinner)
{
	static string bgs,whosColor;
	string prompt,bg = bgcolors.bg,
	player1BGC=bgcolors.player1BGC,
	player2BGC=bgcolors.player2BGC,
	tieBGC = bgcolors.tieBGC;
	string dashes = "------------------------------------------\n";
	int p1=0,p2=0,tie=0;
	static int whosInLead = 0;
	
	if(currentWinner==1)
	{	
		Player1.currentScore++;
		p1 = Player1.currentScore;
	}	
	else if(currentWinner==2)
	{	
		Player2.currentScore++;
		p2 = Player2.currentScore;
	}
	else if(currentWinner==3)
	{	
		tieGames++;
		tie = tieGames;
	}
	whosInLead = makePretty.WhoIsLeading(p1,p2,tie);
	whosColor = makePretty.WhosColor(player1BGC,player2BGC,tieBGC,bg,whosInLead);
	makePretty.centered(PUSHDOWN-VARDW);
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<makePretty.colorOnText("1","41","Player 1 Wins\t",bg)<<
	makePretty.colorOnText("1","44","Player 2 Wins\t",bg)<<
	makePretty.colorOnText("22","43","Tie Games\n",bg);
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<makePretty.colorOnText("22",whosColor,dashes,bg);
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"      ";
	makePretty.changeColor(Player1.currentScore,"player1",bg);
	cout<<"         \t";
	makePretty.changeColor(Player2.currentScore,"player2",bg);
	cout<<"\t   ";
	makePretty.changeColor(tieGames,"tie",bg);
	cout<<endl<<endl;
	if(Player1.currentScore==0 and Player2.currentScore==0 and tieGames==0)
	{
		bgs = bg;
	 	prompt = "What would you expect the Game just started\n\n";
	 	Player1.currentScore = 0;
	 	Player2.currentScore = 0;
			
	}
	else
	if(Player1.currentScore>Player2.currentScore)
	{
		bgs = player1BGC;
		prompt = Player1.name+" is in the lead, c'mon "+Player2.name+"\n\n";
	}
	else if(Player2.currentScore>Player1.currentScore)
	{
		bgs = player2BGC;
		prompt = Player2.name+" is winning, is everything ok "+Player1.name+" ???\n\n";

	}
	else if(Player1.currentScore==Player2.currentScore or
			Player2.currentScore==Player1.currentScore)
	{
		bgs = color.BGCyan;
		prompt = "COME ON YOU GUYS CAN DO BETTER THEN THAT!!!\n\n";
	
	}
	else
	{
		bgs = tieBGC;
		prompt = "close game!!!\n\n";
	}
	
	usleep(DELAY*4);
	makePretty.currentBGWinColor("22",bgs);
	system("clear");
	makePretty.centered(PUSHDOWN);
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout << prompt;
	usleep(DELAY*2);

currentWinner=-1;
}

int TicTacToe::CheckForWinner()
{
int currentwinner=-1;

if(((chalklines[0][0]=='X') and (chalklines[0][1]=='X') and (chalklines[0][2]=='X'))or
((chalklines[1][0]=='X') and (chalklines[1][1]=='X') and (chalklines[1][2]=='X'))or
((chalklines[2][0]=='X') and (chalklines[2][1]=='X') and (chalklines[2][2]=='X'))or
((chalklines[0][0]=='X') and (chalklines[1][0]=='X') and (chalklines[2][0]=='X'))or
((chalklines[0][1]=='X') and (chalklines[1][1]=='X') and (chalklines[2][1]=='X'))or
((chalklines[0][2]=='X') and (chalklines[1][2]=='X') and (chalklines[2][2]=='X'))or
((chalklines[0][0]=='X') and (chalklines[1][1]=='X') and (chalklines[2][2]=='X'))or
((chalklines[2][0]=='X') and (chalklines[1][1]=='X') and (chalklines[0][2]=='X')))
{
	if(Player1.symbol=='X')	
	{
		currentwinner=1;
	}
	else
	{
		currentwinner=2;
	}
}
else if(((chalklines[0][0]=='O')and(chalklines[0][1]=='O')and(chalklines[0][2]=='O'))or
((chalklines[1][0]=='O') and (chalklines[1][1]=='O') and (chalklines[1][2]=='O'))or
((chalklines[2][0]=='O') and (chalklines[2][1]=='O') and (chalklines[2][2]=='O'))or
((chalklines[0][0]=='O') and (chalklines[1][0]=='O') and (chalklines[2][0]=='O'))or
((chalklines[0][1]=='O') and (chalklines[1][1]=='O') and (chalklines[2][1]=='O'))or
((chalklines[0][2]=='O') and (chalklines[1][2]=='O') and (chalklines[2][2]=='O'))or
((chalklines[0][0]=='O') and (chalklines[1][1]=='O') and (chalklines[2][2]=='O'))or
((chalklines[2][0]=='O') and (chalklines[1][1]=='O') and (chalklines[0][2]=='O')))
{
	if(Player1.symbol=='O')	
	{
		currentwinner=1;
	}
	else
	{
		currentwinner=2;
	}
}
else if(((chalklines[0][0]=='O')or(chalklines[0][0]=='X'))
and((chalklines[0][1]=='O')or(chalklines[0][1]=='X'))
and((chalklines[0][2]=='O')or(chalklines[0][2]=='X'))
and((chalklines[1][0]=='O')or(chalklines[1][0]=='X'))
and((chalklines[1][1]=='O')or(chalklines[1][1]=='X'))
and((chalklines[1][2]=='O')or(chalklines[1][2]=='X'))
and((chalklines[2][0]=='O')or(chalklines[2][0]=='X'))
and((chalklines[2][1]=='O')or(chalklines[2][1]=='X'))
and((chalklines[2][2]=='O')or(chalklines[2][2]=='X')))
{
	currentwinner=3;
}
else
{
	currentwinner=-1;
}
return currentwinner;
}
void TicTacToe::WinnerBoarder(int currentWinner)
{
	
	int i,j;
	int VarDw=10;
	string bg = bgcolors.bg,
	player1Color = bgcolors.player1Color,
	player2Color = bgcolors.player2Color;
	
	system("clear");
	makePretty.centered(PUSHDOWN-VARDW);
	for(i=0;i< 2;i++)
	{
		cout<<makePretty.leftCentered(PUSHLEFT+1);
		for(j=0;j<2;j++)
		{
			
			makePretty.winColorChar(i,j,chalklines,bg);
			cout<<" | ";			
		}
	makePretty.winColorChar(i,j,chalklines,bg);
	cout<<endl;
	cout<<makePretty.leftCentered(PUSHLEFT+1);
	cout<<"---------"<<endl;	
	}
	cout<<makePretty.leftCentered(PUSHLEFT+1);
	j=0;
	makePretty.winColorChar(i,j,chalklines,bg);
	cout<<" | ";
	j++;
	makePretty.winColorChar(i,j,chalklines,bg);
	cout<<" | ";
	j++;
	makePretty.winColorChar(i,j,chalklines,bg);
	cout<<endl;
	makePretty.centered(PUSHDOWN-VARDW);
	if(currentWinner==1)
	{
		cout<<makePretty.leftCentered(PUSHLEFT);
		cout<<"Good job "
		<<makePretty.colorOnText("1",player1Color,Player1.name,bg)<<"!\n\n";
	}
	else if(currentWinner==2)
	{
		cout<<makePretty.leftCentered(PUSHLEFT);
		cout<<"Good game "
		<<makePretty.colorOnText("1",player2Color,Player2.name,bg)<<"!\n\n";
	}
	else
	{
		cout<<makePretty.leftCentered(PUSHLEFT);
		cout<<"This game was a tie.\n\n";
		cout<<makePretty.leftCentered(PUSHLEFT);
		cout<<"You are both really good or you are both really bad!!!Step it up!\n\n";
	}
}

void TicTacToe::SetPlayer1()
{
	string tempName,escapeLoop;
	string coloredName,thisPlayer,bg = bgcolors.bg,
	player1Color = bgcolors.player1Color;
	
	int counts=0;
	char symbol;
	bool valid=false; 
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"Player1, please enter your name: \n";
	cout<<makePretty.leftCentered(PUSHLEFT);
	getline(cin,tempName);
	makePretty.PlaySoundEffect(efx.Swoosh);
	while(tempName == "" or tempName == " " or tempName == "\n")
	{
		if(tempName == "" or tempName == " " or tempName == "\n")
		{	escapeLoop = tempName;
			cout << endl;
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.SlowNo);
			cout<<makePretty.leftCentered(PUSHLEFT);
			cout<<"Entry can not be empty!!\n\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			cout<<"Please fill in a name\n\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			getline(cin,tempName);
			
			++counts;
		}
		switch(counts)
		{
			case 3:
			{
				system("clear");
				makePretty.centered(PUSHDOWN);
				break;
			}
			case 6:
			{
				system("clear");
				makePretty.PlaySoundEffect(efx.ComeOnYouCanDoIt);
				cout<<makePretty.leftCentered(PUSHLEFT);
				makePretty.centered(PUSHDOWN);
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "Really you don't know your name psssssh!!!\n\n";
				break;
			}
			case 7:
			{ 	
				if(tempName=="\0")
				{
					system("clear");
					makePretty.centered(PUSHDOWN);
					counts =0;
				}
				else
					escapeLoop ="a";
		
				if(escapeLoop == "a")
				{
					system("clear");
					makePretty.centered(PUSHDOWN);
					cout<<makePretty.leftCentered(PUSHLEFT);
					cout << "I Knew you could do it Good Job!!";
					usleep(DELAY);
					system("clear");
					makePretty.centered(PUSHDOWN);
					
				}
				break;
			}
		}
		
	}
	thisPlayer = Player1.name=tempName;
	coloredName = makePretty.colorOnText("1",player1Color,thisPlayer,bg);
	cout<<endl;
	cout<<makePretty.leftCentered(PUSHLEFT-1);
	cout<<""<<coloredName<<", would you like to be X or O? Please enter your choice.\n";
	cout<<makePretty.leftCentered(PUSHLEFT-1);
	cin.get(symbol);
	makePretty.PlaySoundEffect(efx.Swoosh);
	while(valid==false)
	{
		if((symbol=='X')or(symbol=='x'))
		{
			Player1.symbol='X';
			valid=true;
		}		
		else if((symbol=='O')or(symbol=='o'))
		{
			Player1.symbol='O';
			valid=true;
		}
		else
		{
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.ClearingThroat);
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.Sigh);
			cout<<endl;
			cout<<makePretty.leftCentered(PUSHLEFT-1);
			cout<<"Invalid selection. For this game, you should choose X or O.\n\n";
			
			usleep(DELAY);
			cout<<endl;
			cout<<makePretty.leftCentered(PUSHLEFT-1);
			cout<<coloredName<<", would you like to be X or O? Please enter your choice.\n";
			cout<<makePretty.leftCentered(PUSHLEFT-1);
			cin.get(symbol);
			
		}		
	}
	Player1.currentScore=0;
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"Thank you "<<coloredName<<". Good Luck!\n\n";
}
void TicTacToe::SetPlayer2()
{
	string tempName,escapeLoop;
	string coloredNameP1,colorNameP2,
	thisPlayerP1,thisPlayerP2,bg = bgcolors.bg,
	player1Color = bgcolors.player1Color,
	player2Color = bgcolors.player2Color;
	
	int counts =0;
	char symbol;
	
	if(Player1.symbol=='X')
	{
		symbol='O';
	} 
	else
	{
		symbol='X';
	}
	cin.ignore(5,'\n');
	usleep(DELAY);
	makePretty.PlaySoundEffect(efx.Swoosh);
	system("clear");
	makePretty.centered(PUSHDOWN);
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"Player2, please enter your name:\n";
	cout<<makePretty.leftCentered(PUSHLEFT);
	getline(cin,tempName);
	cout<<"\n";
	while(tempName == "" or tempName == " " or tempName == "\n")
	{
		if(tempName == "" or tempName == " " or tempName == "\n")
		{ 
			cout << endl;
			usleep(DELAY);
			makePretty.PlaySoundEffect(efx.SlowNo);
			cout<<makePretty.leftCentered(PUSHLEFT);
			cout<<"Entry can not be empty!!\n\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			cout<<"Please fill in a name\n\n";
			cout<<makePretty.leftCentered(PUSHLEFT);
			getline(cin,tempName);
			
			++counts;	
		}
		switch(counts)
		{
			case 3:
			{
				system("clear");
				makePretty.centered(PUSHDOWN);
				break;
			}
			case 6:
			{
				system("clear");
				makePretty.PlaySoundEffect(efx.ComeOnYouCanDoIt);
				cout<<makePretty.leftCentered(PUSHLEFT);
				makePretty.centered(PUSHDOWN);
				cout<<makePretty.leftCentered(PUSHLEFT);
				cout << "Really you don't know your name psssssh!!!\n\n";
				break;
			}
			case 7:
			{ 	
				if(tempName=="\0")
				{
					system("clear");
					makePretty.centered(PUSHDOWN);
					counts =0;
				}
				else
					escapeLoop ="a";
		
				if(escapeLoop == "a")
				{
					system("clear");
					makePretty.centered(PUSHDOWN);
					cout<<makePretty.leftCentered(PUSHLEFT);
					cout << "I Knew you could do it Good Job!!\n\n";
					usleep(DELAY);
					system("clear");
					makePretty.centered(PUSHDOWN);
				}
				break;
			}
		}
		
	}
	makePretty.PlaySoundEffect(efx.Swoosh);
	
	thisPlayerP1 = Player1.name;
	thisPlayerP2 = Player2.name=tempName;
	
	coloredNameP1 = makePretty.colorOnText("1",player1Color,thisPlayerP1,bg);
	colorNameP2 = makePretty.colorOnText("1",player2Color,thisPlayerP2,bg);
	
	cout<<makePretty.leftCentered(PUSHLEFT-1);
	cout<<colorNameP2<<", "<<coloredNameP1<<" chose "<<Player1.symbol
	<<". You will be "<<symbol<<" in this game.\n\n";
	cout<<makePretty.leftCentered(PUSHLEFT);
	cout<<"Good luck "<<colorNameP2<<"!\n";
	Player2.symbol=symbol;
	Player2.currentScore=0;
	usleep(DELAY);
}

void TicTacToe::ResetTies()
{
	tieGames=0;
}


