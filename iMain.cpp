#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#define screenheight 1000
#define screenwidth 600

int r = 255, g = 255, b = 255;
int gameLevel = -1;
int maxgameLevel = 1;
int totalscore = 0;
int flag = 0; // to determine the levelscore should be count from beginning or current situation
int ifGamePlayed = 0;
int levelscore = 0; //-1 means homepage, 0 means levelIconsPage;
int add = 10;
int require = 70;
bool instructions = false;
bool leaderboard = false;
bool musicon = true;
bool wordplay = false;
bool namegiven = false;
bool levelcross = false;
bool levelfailed = false;
bool finalpage = false;
int backButtonX = 1280, backButtonY = 10;

char levelIconPic[10][30] = {"background\\level1.bmp", "background\\level2.bmp", "background\\level3.bmp", "background\\level4.bmp", "background\\level5.bmp", "background\\level6.bmp", "background\\level7.bmp", "background\\level8.bmp", "background\\level9.bmp", "background\\level10.bmp"};
char homepageIconPic[2][40] = {"background\\homepageIcon1.bmp", "background\\homepageIcon2.bmp"};
int wordNum = 1;
char word[30];
char mispelled[10][20];
int mispelledCount = 0;
char word1[10][30] = {"tsunami", "millennium", "freedom", "realistic", "intuitive", "conflict", "undergo", "calmness", "crucial", "hencemen"};
char word2[10][30] = {"propagate", "postulate", "ambigiously", "analogous", "criterion", "discrepancy", "convenient", "interpretation", "remarkable", "conservative"};
char word3[10][30] = {"fatal", "commentary", "quests", "shackle", "delimeter", "parallax", "fallacy", "annihilation", "faucet", "lieutenant"};
char word4[10][30] = {"cholera", "chaos", "psychology", "stretch", "ballet", "colonel", "schedule", "occasion", "villain", "dilate"};
char word5[10][30] = {"pneumonia", "neighbor", "vacuum", "privilege", "playwright", "calendar", "legacy", "accommodate", "island", "colleague"};
char word6[10][30] = {"pronunciation", "liquefy", "rhetoric", "committee", "corollary", "caribbean", "noticeable", "threshold", "leisure", "descendant"};
char word7[10][30] = {"individual", "acquaintance", "parachute", "concede", "saccharine", "pursue", "vicious", "parallel", "cemetery", "misspell"};
char word8[10][30] = {"commodities", "yacht", "curiosity", "euclidean", "arctic", "apparent", "echelon", "superintendent", "handkercheif", "nauseous"};
char word9[10][30] = {"encumber", "hypocrite", "conscientious", "minuscule", "sacrilegious", "exaggerate", "cancellation", "liaison", "magazine", "ascend"};
char word10[10][30] = {"philanthropic", "amoeba", "squirrel", "bourgeois", "entrepreneur", "hierarchy", "vengeance", "sherbet", "forethought", "Tantamount"};
char music1[10][20] = {"music\\1-1.wav", "music\\1-2.wav", "music\\1-3.wav", "music\\1-4.wav", "music\\1-5.wav", "music\\1-6.wav", "music\\1-7.wav", "music\\1-8.wav", "music\\1-9.wav", "music\\1-10.wav"};
char music2[10][20] = {"music\\2-1.wav", "music\\2-2.wav", "music\\2-3.wav", "music\\2-4.wav", "music\\2-5.wav", "music\\2-6.wav", "music\\2-7.wav", "music\\2-8.wav", "music\\2-9.wav", "music\\2-10.wav"};
char music3[10][20] = {"music\\3-1.wav", "music\\3-2.wav", "music\\3-3.wav", "music\\3-4.wav", "music\\3-5.wav", "music\\3-6.wav", "music\\3-7.wav", "music\\3-8.wav", "music\\3-9.wav", "music\\3-10.wav"};
char music4[10][20] = {"music\\4-1.wav", "music\\4-2.wav", "music\\4-3.wav", "music\\4-4.wav", "music\\4-5.wav", "music\\4-6.wav", "music\\4-7.wav", "music\\4-8.wav", "music\\4-9.wav", "music\\4-10.wav"};
char music5[10][20] = {"music\\5-1.wav", "music\\5-2.wav", "music\\5-3.wav", "music\\5-4.wav", "music\\5-5.wav", "music\\5-6.wav", "music\\5-7.wav", "music\\5-8.wav", "music\\5-9.wav", "music\\5-10.wav"};
char music6[10][20] = {"music\\6-1.wav", "music\\6-2.wav", "music\\6-3.wav", "music\\6-4.wav", "music\\6-5.wav", "music\\6-6.wav", "music\\6-7.wav", "music\\6-8.wav", "music\\6-9.wav", "music\\6-10.wav"};
char music7[10][20] = {"music\\7-1.wav", "music\\7-2.wav", "music\\7-3.wav", "music\\7-4.wav", "music\\7-5.wav", "music\\7-6.wav", "music\\7-7.wav", "music\\7-8.wav", "music\\7-9.wav", "music\\7-10.wav"};
char music8[10][20] = {"music\\8-1.wav", "music\\8-2.wav", "music\\8-3.wav", "music\\8-4.wav", "music\\8-5.wav", "music\\8-6.wav", "music\\8-7.wav", "music\\8-8.wav", "music\\8-9.wav", "music\\8-10.wav"};
char music9[10][20] = {"music\\9-1.wav", "music\\9-2.wav", "music\\9-3.wav", "music\\9-4.wav", "music\\9-5.wav", "music\\9-6.wav", "music\\9-7.wav", "music\\9-8.wav", "music\\9-9.wav", "music\\9-10.wav"};
char music10[10][20] = {"music\\10-1.wav", "music\\10-2.wav", "music\\10-3.wav", "music\\10-4.wav", "music\\10-5.wav", "music\\10-6.wav", "music\\10-7.wav", "music\\10-8.wav", "music\\10-9.wav", "music\\10-10.wav"};

char currentscore[10];
char wordcount[10];
char levelcount[10];
char totalscoreCount[10];
char scorer[30];
char gamelevel[5];

int idx = 0;
struct structLevelIcon
{
	int x, y;
};

struct hscore
{
	char name[30];
	int score;
} highscore[5];

structLevelIcon levelIcon[10];
void setHomepageIconCordinate();
void setLevelIconCordinate();
void newHighScore();
void readscore();
void iDraw()
{
	iClear();
	iSetColor(r, g, b);
	if (gameLevel > 0 && musicon)
	{
		PlaySound(0, 0, 0);
		musicon = false;
	}

	if (instructions)
	{
		iShowBMP(0, 0, "background\\instructions.bmp");
		
	}

	else if (leaderboard)
	{

		iShowBMP(0, 0, "background\\leaderboard.bmp");
		readscore();
	}
	else if (levelcross)
	{
		iShowBMP(0, 0, "background\\levelcrossed.bmp");
		iSetColor(255, 0, 0);
		iText(50, 335, "*** CORRECTION OF YOUR INCORRECT SPELLINGS ***", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 200, 125);
		if (mispelledCount == 0)
		{
			iText(75, 200, "WAHH!! NO INCORRECT SPELLING!", GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			for (int i = 0; i < mispelledCount; i++)

			{
				iText(150, 280 - 50 * i, mispelled[i], GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
		iSetColor(255, 255, 255);
	}
	else if (levelfailed)
	{
		iShowBMP(0, 0, "background\\levelfailed.bmp");
	}
	else if (finalpage)
	{
		iShowBMP(0, 0, "background\\finalpage.bmp");
	}
	else if (gameLevel == -1)
	{
		iShowBMP(0, 0, "background\\homepage.bmp");
		iRectangle(107, 54, 183, 20);
		iSetColor(0, 255, 255);
		iFilledRectangle(105, 40, 500, 40);
		iSetColor(0, 0, 0);
		iText(105, 52, "ENTER NICKNAME  : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 0, 0);
		iText(360, 52, scorer, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
	}

	else if (gameLevel == 0)
	{

		iShowBMP(0, 0, "background\\levelBackground.bmp");
		sprintf(gamelevel,"%d",maxgameLevel);
		iText(300,10,"YOUR CURRENT LEVEL IS : ",GLUT_BITMAP_HELVETICA_18);
		iText(550,10,gamelevel,GLUT_BITMAP_HELVETICA_18);
		for (int i = 0; i < 10; i++)
		{
			iShowBMP(levelIcon[i].x, levelIcon[i].y, levelIconPic[i]);
		}
	}
	else if (gameLevel > 0)
	{
		sprintf(currentscore, "%d", levelscore);
		sprintf(wordcount, "%d", wordNum);
		sprintf(levelcount, "%d", gameLevel);
		sprintf(totalscoreCount, "%d", totalscore);
		iShowBMP(0, 0, "background\\levelpage1.bmp");
		iText(320, 265, word, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(446, 565, currentscore, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(302, 318, wordcount, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(301, 395, levelcount, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(346, 507, totalscoreCount, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}



void iMouse(int button, int state, int mx, int my)
{
	//printf("x=%d ,y=%d\n",mx,my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameLevel == -1 && !instructions && !leaderboard && !levelcross && !levelfailed)
		{
			
			if (mx >= 108 && mx <= 400 && my >= 290 && my <= 336) // means pressing enter
			{
				if (namegiven)
					gameLevel = 0;
			}
			else if(  (mx >= 870 && mx <= 982 && my >= 87 && my <= 131))
			{
				if(musicon)
				{
					PlaySound(0,0,0);
				    musicon=false;
				}
				else 
				{
					PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
					musicon=true;
				}
			}
			else if( !musicon && (mx >= 108 && mx <= 400 && my >= 290 && my <= 336))
			{
				PlaySound(0,0,0);
				musicon=true;
			}
			else if (mx >= 108 && mx <= 460 && my >= 220 && my <= 262) // means pressing instruction
			{
				instructions = true;
			}
			else if (mx >= 108 && mx <= 460 && my >= 149 && my <= 190) // means pressing leaderboard
			{
				leaderboard = true;
			}
			if (mx >= 856 && mx <= 1000 && my >= 0 && my <= 64) // means quit
			{
				newHighScore();
				scorer[0] = '\0';
				gameLevel = -1;
				maxgameLevel = 1;
				namegiven = false;
				wordNum = 1;
				flag = 0;
				totalscore = 0;
			}
		}
		else if (gameLevel == 0 && !instructions)
		{

			if (pow((mx - 961), 2) + pow((my - 33), 2) - 37 * 37 <= 0) // means pressing back button
			{
				gameLevel = -1;
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					if (mx >= levelIcon[i].x && mx <= levelIcon[i].x + 180 && my >= levelIcon[i].y && my <= levelIcon[i].y + 180) // means chosing level
					{
						
						if (maxgameLevel == i + 1)
						{
							
							if (flag == 0)
								levelscore = 0;
							gameLevel = i + 1;
							
							maxgameLevel = gameLevel;
							musicon = true;
						}
					}
				}
			}
		}
		else if (instructions)
		{

			if (pow((mx - 965), 2) + pow((my - 31), 2) - 30 * 30 <= 0) // means back
			{
				instructions = false;
				gameLevel = -1;
			}
		}
		else if (leaderboard)
		{
			if (pow((mx - 969), 2) + pow((my - 31), 2) - 31 * 31 <= 0) // means back
			{
				leaderboard = false;
				gameLevel = -1;
			}
		}
		else if (levelcross)
		{
			if (mx >= 352 && mx <= 678 && my >= 0 && my <= 80) // means next level
			{
				if (gameLevel == 10)
				{
					finalpage = true;
					levelscore = 0;
					mispelledCount = 0;
					levelcross = false;
					PlaySound("music\\levelcrossSound.wav", NULL, SND_ASYNC);
				}

				else
				{
					PlaySound("music\\levelcrossSound.wav", NULL, SND_ASYNC);
					gameLevel++;
					maxgameLevel = gameLevel;
					levelscore = 0;
					for (int i = 0; i < mispelledCount; i++)
					{
						mispelled[i][0] = NULL;
					}
					mispelledCount = 0;

					levelcross = false;
				}
			}
			if (mx >= 856 && mx <= 1000 && my >= 0 && my <= 64)  //means pressing quit
			{
				
				newHighScore();
				scorer[0] = '\0';
				gameLevel = -1;
				maxgameLevel = 1;
				namegiven = false;
				for (int i = 0; i < mispelledCount; i++)
				{
					mispelled[i][0] = NULL;
				}
				mispelledCount = 0;
				levelcross = false;
				flag = 0;
				totalscore = 0;
				//if(musicon)
				PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if (levelfailed)
		{
			if (mx >= 352 && mx <= 678 && my >= 0 && my <= 80) // means same level
			{

				PlaySound("music\\levelfailSound.wav", NULL, SND_ASYNC);

				totalscore -= levelscore;
				levelscore = 0;

				levelfailed = false;
				mispelledCount = 0;
			}

			if (mx >= 856 && mx <= 1000 && my >= 0 && my <= 64)
			{
				
				newHighScore();
				scorer[0] = '\0';
				gameLevel = -1;
				maxgameLevel = 1;
				namegiven = false;
				levelfailed = false;
				flag = 0;
				totalscore = 0;
				//if(musicon)
				PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if (finalpage)
		{
			if (mx >= 856 && mx <= 1000 && my >= 0 && my <= 64) // means quit button
			{
				newHighScore();
				scorer[0] = '\0';
				gameLevel = -1;
				maxgameLevel = 1;
				namegiven = false;
				for (int i = 0; i < mispelledCount; i++)
				{
					mispelled[i][0] = NULL;
				}
				mispelledCount = 0;
				levelcross = false;
				flag = 0;
				totalscore = 0;
				//if(musicon)
				PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
				finalpage = false;
			}
		}
		else if (gameLevel > 0)
		{

			if (gameLevel == 1)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{
					
					musicon = false;
					wordplay = true;
					PlaySound(music1[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 2)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music2[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 3)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music3[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 4)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music4[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 5)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music5[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 6)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music6[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 7)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music7[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 8)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music8[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 9)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music9[wordNum - 1], NULL, SND_ASYNC);
				}
			}
			else if (gameLevel == 10)
			{
				if (pow((mx - 157), 2) + pow((my - 164), 2) - 84 * 84 <= 0) // means pressing play sound
				{

					musicon = false;
					wordplay = true;
					PlaySound(music10[wordNum - 1], NULL, SND_ASYNC);
				}
			}

			if (pow((mx - 969), 2) + pow((my - 31), 2) - 31 * 31 <= 0) // means pressing back button
			{
				gameLevel = -1;
				flag = 1;
				//if(musicon)
				PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (mx >= 347 && mx <= 532 && my >= 109 && my <= 210) // means pass
			{
				if (gameLevel == 1)
				{
					strcpy(mispelled[mispelledCount], word1[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 2)
				{
					strcpy(mispelled[mispelledCount], word2[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 3)
				{
					strcpy(mispelled[mispelledCount], word3[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 4)
				{
					strcpy(mispelled[mispelledCount], word4[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 5)
				{
					strcpy(mispelled[mispelledCount], word5[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 6)
				{
					strcpy(mispelled[mispelledCount], word6[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 7)
				{
					strcpy(mispelled[mispelledCount], word7[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 8)
				{
					strcpy(mispelled[mispelledCount], word8[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 9)
				{
					strcpy(mispelled[mispelledCount], word9[wordNum - 1]);
					mispelledCount++;
				}
				else if (gameLevel == 10)
				{
					strcpy(mispelled[mispelledCount], word10[wordNum - 1]);
					mispelledCount++;
				}
				wordplay = false;
				idx = 0;
				word[idx] = '\0';
				wordNum++;
				if (wordNum > 10)
				{
					
					wordNum = 1;

					if (levelscore >= 60)
					{
						PlaySound("music\\levelcrossSound.wav", NULL, SND_ASYNC);
						levelcross = true;
					}

					else
					{
						PlaySound("music\\levelfailSound.wav", NULL, SND_ASYNC);
						levelfailed = true;
					}
				}
			}
		}
	}
}

void iKeyboard(unsigned char key)
{

	if (gameLevel == -1 && !namegiven)
	{
		if ((key == 13 || key == ' ') && idx != 0)
		{
			namegiven = true;
			idx = 0;
		}
		else if (key != '\b' && key != 13)
		{
			scorer[idx] = key;
			idx++;
			scorer[idx] = '\0';
		}
		else if (key == 8 && idx > 0)
		{
			idx--;
			scorer[idx] = '\0';
		}
	}

	if (wordplay)
	{

		if (key != '\b' && key != 13 && key != ' ')
		{
			word[idx] = tolower(key);
			idx++;
			word[idx] = '\0';
		}
		else if (key == 8 && idx > 0)
		{
			idx--;
			word[idx] = '\0';
		}
		else if (key == 13 && idx != 0)
		{

			ifGamePlayed = 1;

			wordplay = false;
			int temp;
			if (gameLevel == 1)
			{
				temp = strcmp(word, word1[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word1[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 2)
			{
				temp = strcmp(word, word2[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word2[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 3)
			{
				temp = strcmp(word, word3[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word3[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 4)
			{
				temp = strcmp(word, word4[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word4[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 5)
			{
				temp = strcmp(word, word5[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word5[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 6)
			{
				temp = strcmp(word, word6[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word6[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 7)
			{
				temp = strcmp(word, word7[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word7[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 8)
			{
				temp = strcmp(word, word8[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word8[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 9)
			{
				temp = strcmp(word, word9[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word9[wordNum - 1]);
					mispelledCount++;
				}
			}
			else if (gameLevel == 10)
			{
				temp = strcmp(word, word10[wordNum - 1]);
				if (temp != 0)
				{
					strcpy(mispelled[mispelledCount], word10[wordNum - 1]);
					mispelledCount++;
				}
			}

			wordNum++;

			if (temp == 0)
			{

				idx = 0;
				word[idx] = '\0';
				totalscore += 10;
				levelscore += 10;
				PlaySound("music\\correctsound.wav", NULL, SND_ASYNC);
				
			}
			else if (levelscore > 2 && totalscore > 2)
			{
				idx = 0;
				word[idx] = '\0';
				totalscore -= 3;
				levelscore -= 3;
				PlaySound("music\\wrongsound.wav", NULL, SND_ASYNC);
			}
			else if (levelscore < 3 && totalscore > 2)
			{
				idx = 0;
				word[idx] = '\0';
				totalscore -= 3;
				levelscore = 0;
				PlaySound("music\\wrongsound.wav", NULL, SND_ASYNC);
			}
			else if (levelscore < 3 && totalscore < 3)
			{
				idx = 0;
				word[idx] = '\0';
				totalscore = 0;
				levelscore = 0;
				PlaySound("music\\wrongsound.wav", NULL, SND_ASYNC);
			}

			if (wordNum > 10)
			{
				wordNum = 1;

				if (levelscore >= 60)
				{
					PlaySound("music\\levelcrossSound.wav", NULL, SND_ASYNC);
					levelcross = true;
				}

				else
				{
					PlaySound("music\\levelfailSound.wav", NULL, SND_ASYNC);
					levelfailed = true;
				}
			}
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
}

void iMouseMove(int mx, int my)
{

}

void setLevelIconCordinate()
{
	for (int i = 0; i < 10; i++)
	{
		levelIcon[i].x = 10 + 200 * i; // levelIcon's px 200*200
		if (i <= 4)
			levelIcon[i].y = 340;
		else
		{
			levelIcon[i].x = 10 + 200 * (i - 5);
			levelIcon[i].y = 80;
		}
	}
}

int main()
{
	setLevelIconCordinate();
	if (musicon)
		PlaySound("music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(screenheight, screenwidth, "SPELLING MASTER");

	return 0;
}

void readscore()
{

	FILE *fp;
	fp = fopen("Score.txt", "r");
	char showname[5][30], showscore[5][5];
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s %d\n", highscore[i].name, &highscore[i].score);
	}
	for (int i = 0; i < 5; i++)
	{
		sprintf(showname[i], "%s", highscore[i].name);
		
		sprintf(showscore[i], "%d", highscore[i].score);
	}
	fclose(fp);
	for (int i = 0; i < 5; i++)
	{
		iSetColor(0, 255, 255);
		iText(168, 368 - 64 * i, showname[i], GLUT_BITMAP_HELVETICA_18);
		iText(733, 368 - 64 * i, showscore[i], GLUT_BITMAP_HELVETICA_18);
	}
}

void newHighScore()
{
	
	ifGamePlayed = 0;
	FILE *fp;
	fp = fopen("Score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s %d\n", highscore[i].name, &highscore[i].score);
	}

	int t;
	char n[30];

	if (totalscore > highscore[4].score)
	{
		highscore[4].score = totalscore;
		strcpy(highscore[4].name, scorer);
	}

	for (int i = 0; i < 5; i++)
	{

		for (int k = 0; k < 5 - i - 1; k++)
		{

			if (highscore[k].score < highscore[k + 1].score)
			{

				t = highscore[k].score;
				highscore[k].score = highscore[k + 1].score;
				highscore[k + 1].score = t;
				strcpy(n, highscore[k].name);
				strcpy(highscore[k].name, highscore[k + 1].name);
				strcpy(highscore[k + 1].name, n);
			}
		}
	}
	fclose(fp);
	FILE *fip;
	fip = fopen("Score.txt", "w");
	for (int i = 0; i < 5; i++)
	{
		fprintf(fip, "%s %d\n", highscore[i].name, highscore[i].score);
	}
	fclose(fip);
}
