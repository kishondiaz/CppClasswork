/*ttt.h
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
#include<string>

using namespace std;

#ifndef TTT_H
#define TTT_H


struct Player
{
	string name;
	char symbol;
	int currentScore;

};
struct SoundEfx
{
	
	string Buzzer,FF5Victory,
	ShortTrump,Suspense,
	TaDa,Tick,ClearingThroat,Swoosh,
	Sigh,LilGirlBye,SlowNo,ComeOnYouCanDoIt,Twikle,Please,
	Rock;
	SoundEfx()
	{
		Buzzer = "Buzzer2.ogg";
		FF5Victory = "final-fantasy-v-music-victory-fanfare.ogg";
		ShortTrump ="Short_triumphal_fanfare-John_Stracke-815794903.ogg";
		Suspense = "Incoming_Suspense-Maximilien_-1060577487.ogg";
		TaDa = "TaDa-SoundBible.com-1884170640.ogg";
		Tick = "Tick-DeepFrozenApps-397275646.ogg";
		ClearingThroat = "ThroatClearing-SoundBible.com-328410293.ogg";
		Swoosh = "Swoosh_3-SoundBible.com-1573211927.ogg";
		Sigh = "Sigh-SoundBible.com-1679973774.ogg";
		LilGirlBye = "ByeBye-SoundBible.com-1483442951.ogg";
		SlowNo = "No-SoundBible.com-402355541.ogg";
		ComeOnYouCanDoIt = "come-on-you-can-do-it.ogg";
		Twikle= "magic-chime-01.ogg";
		Please = "Please-SoundBible.com-1680096258.ogg";
	
	
	}

};
struct BGColors
{
	
	string bg,player1Color,player2Color,
		player1BGC,player2BGC,tieBGC;
		
	BGColors()
	{
	
	}


};
const int MAX_SIZE = 3;

class TicTacToe
{
	
	private:
		Player Player1;
		Player Player2;
		char chalklines[MAX_SIZE][MAX_SIZE];
		int tieGames;
		int RefBoard[MAX_SIZE][MAX_SIZE];
	public:
	        	
		TicTacToe()
		{
			Player1.name="Player 1";
			Player1.symbol='X';
			Player1.currentScore=0;
			Player2.name="Player 2";
			Player2.symbol='O';
			Player2.currentScore=0;
			tieGames=0;
			
		}
		void SetPlayer1();
		void SetPlayer2();
		void Reset();
		void ChoosePosition();
		void ChoosePosition2();
		int CheckForWinner();
		void Boarder();
		void WinnerBoarder(int);
		void DisplayScore(int &);
		void ResetTies();
	
		
		
		
};
#endif
