/*glamour.h
  DavidMarcus and KishonDiaz
  September 20, 2014
  This is the driver for ttt.h and ttt.cpp
*/

#include<string>
#include <string.h>

using namespace std;

#ifndef GLAMOUR_H
#define GLAMOUR_H
struct Colors
{
	string textBlack,textRed,textGreen,
	textYellow,textBlue,textMagenta,
	textCyan,textWhite,textDefault,textColor,textCustom;
	
	string BGBlack,BGRed,BGGreen,
	BGYellow,BGBlue,BGMagenta,
	BGCyan,BGWhite,BGDefault,BGColor,BGCustom;
	
	Colors()
	{
		textBlack="30";
		textRed="31";
		textGreen="32";
		textYellow="33";
		textBlue="34";
		textMagenta="35";
		textCyan="36";
		textWhite="37";
		textDefault="39";
		textColor="39";
		
		BGBlack="40";
		BGRed="41";
		BGGreen="42";
		BGYellow="43";
		BGBlue="44";
		BGMagenta="45";
		BGCyan="46";
		BGWhite="47";
		BGDefault = "49";
		BGColor="49";
	}

};
const int MAX_SIZES = 3;
class Glamour
{
	private:
		char chalklines[MAX_SIZES][MAX_SIZES];
		string code,textColor,backColor;
		int position,a,b;

	public:
		Glamour()
		{
		
		}
		void centered(int);
		void colorOn(string,string);
		void colorOff();
		void colorChar(int,int,char[3][3],string);
		void colorNum(int,int,char[3][3],int[3][3],string);
		void changeColor(int,string,string);
		void winColorChar(int,int,char[3][3],string);
		void BackGround(string,int);
		void BackGround(int,string,string);
		void BackGround(string,string,string,int);
		void BGColorOff();
		void currentBGWinColor(string,string,int);
		void PlaySoundEffect(string);
		void SoundErrorCheck();
		void SetBackGround(string);
		int WhoIsLeading(int,int,int);
		string colorOn(int,int,char[3][3],string);
		string WhosColor(string,string,string,string,int);
		string leftCentered(int);
		string colorOnText(string,string,string,string);
		string strColorOff();
		string ColorOffWithBG(string);
		
		



};
#endif
