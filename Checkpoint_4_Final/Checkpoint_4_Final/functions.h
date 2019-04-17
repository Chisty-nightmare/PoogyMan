#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

# include "iGraphics.h"
#include<string.h>
#include<time.h>
#include<stdio.h>
#include "enemy.h"
#include "fireball.h"
#include <stdlib.h>
int image1; int heart[5];
int poogyLife = 5;
int ed = 5;
int lvl = 1; char lvlarray[20];

int score =0; char scorearray[20]; int savescore;
int tc;
int a1;
int b1;
Enemy enm1(a1, 1000), enm2(a1, 2000), enm3(a1, 3000), enm4(a1, 4000), enm5(a1, 5000);
Fireball fb1(b1, 1000), fb2(b1, 2000), fb3(b1, 3000), fb4(b1, 4000), fb5(b1, 5000);
int sm[5], t = 0;
int  i = 0, a = 150, b = 50;
int poogy[2], bck, nm, bck2,dragon;
int width = 1000;
char str[100], str2[100];
int len;
int xpos = 30, ypos = 80;
int backxpos = -500;
int back2xpos = (backxpos + 2400);
int state = 0, termination1[6] = { 1, 1, 1, 1, 1, 1 }, termination2[6] = { 1, 1, 1, 1, 1, 1 };//terminqtion1 for poogylife decrease and termination2 for scoring
int terminationfb1[6] = { 1, 1, 1, 1, 1, 1 }, terminationfb2[6] = { 1, 1, 1, 1, 1, 1 };
int colt[5];
int fbolt[5];
int menut = 0;

void collision()
{
	iPoint(xpos + 205, 80 + 100);
}

void sortScore()
{
	int k;
	char s[10];
	char hi_name[4][100];
	int hiscore[4];
	FILE *fpp = fopen("highscore.txt", "r");
	for (int loop = 0; loop<3; loop++)
	{
		fscanf(fpp, "%s %d", &hi_name[loop], &hiscore[loop]);
	}
	fclose(fpp);
	strcpy(hi_name[3], str);
	hiscore[3] = score;

	for (int loop = 0; loop<4 - 1; loop++)
	{
		for (int x = 0; x<4 - loop - 1; x++)
		if (hiscore[x]<hiscore[x + 1])
		{
			k = hiscore[x];
			hiscore[x] = hiscore[x + 1];
			hiscore[x + 1] = k;
			strcpy(s, hi_name[x]);
			strcpy(hi_name[x], hi_name[x + 1]);
			strcpy(hi_name[x + 1], s);
		}
	}
	FILE *fpwp = fopen("highscore.txt", "w");
	for (int loop = 0; loop<3; loop++)
	{
		fprintf(fpp, "%s %d\n", hi_name[loop], hiscore[loop]);
	}
	fclose(fpwp);


}



void scene()
{

	iShowImage(0, 0, 1200, 675, sm[t]);
	iShowImage(0, 0, 1200, 675, sm[t]);
	iShowImage(0, 0, 1200, 675, sm[t]);
	iShowImage(0, 0, 1200, 675, sm[t]);
	iShowImage(0, 0, 1200, 675, sm[t]);

}
void EnemyScene()
{
	if (enm1.enemyxpos <= 0)
	{
		enm1.enemyxpos = 4250; termination1[0] = 1; termination2[0] = 1; colt[0] = 0;
	}
	if (enm2.enemyxpos <= 0)
	{
		enm2.enemyxpos = 4500; termination1[1] = 1; termination2[1] = 1; colt[1] = 0;
	}
	if (enm3.enemyxpos <= 0)
	{
		enm3.enemyxpos = 4750; termination1[2] = 1; termination2[2] = 1; colt[2] = 0;
	}
	if (enm4.enemyxpos <= 0)
	{
		enm4.enemyxpos = 5000; termination1[3] = 1; termination2[3] = 1; colt[3] = 0;
	}
	if (enm5.enemyxpos <= 0)
	{
		enm5.enemyxpos = 5250; termination1[4] = 1; termination2[4] = 1; colt[4] = 0;
	}
	enm1.enemyxpos -= ed;
	enm2.enemyxpos -= ed;
	enm3.enemyxpos -= ed;
	enm4.enemyxpos -= ed;
	enm5.enemyxpos -= ed;





	/*if (enemyxpos <= 0)
	enemyxpos = 1000;*/
}
void win()
{
	sortScore();
	poogyLife = 5; score = 0; xpos = 30; lvl = 0;
	iClear();
	iSetColor(255, 255, 255);
	iText(500, 600, "YOU WIN!!", GLUT_BITMAP_TIMES_ROMAN_24);

}
void FireballScene()
{
	/*if (enemyxpos <= 0)
	enemyxpos = 1000;
	else
	enemyxpos = enemyxpos - enemyspeed;*/
	if (fb1.fbxpos <= 0)
	{
		fb1.fbxpos = 4250; terminationfb1[0] = 1; terminationfb2[0] = 1; fbolt[0] = 0;
	}

	fb1.fbxpos=fb1.fbxpos-5;

	/*if (enemyxpos <= 0)
	enemyxpos = 1000;*/
}
/*void saveScore(char *hi_name, int hiscore){




	char hiscoreArray[20];
	_itoa(hiscore, hiscoreArray, 10);

	FILE *fp = fopen("highscore.txt", "a");



	fputs(strcat(hi_name," "), fp);
	fputs(hiscoreArray, fp);
	fputs("\n", fp);


	fclose(fp);

}*/

void gameScene(){

	iShowImage(backxpos, 0, 2400, 675, bck);
	iShowImage(backxpos + 2400, 0, 2400, 675, bck);
	if (!state)
		iShowImage(xpos, ypos, 300, 300, poogy[0]);
	else
		iShowImage(xpos, ypos, 300, 300, poogy[1]);






	if (enm1.CollisionEnemy(xpos + 150) == 0 && termination2[0] == 1 && termination1[0] == 1){
		termination2[0] = 0;
		poogyLife--;
		score = score - 5;

	}

	if (enm2.CollisionEnemy(xpos + 150) == 0 && termination2[1] == 1 && termination1[1] == 1){
		termination2[1] = 0;
		poogyLife--;
		score = score - 5;
	}
	if (enm3.CollisionEnemy(xpos + 150) == 0 && termination2[2] == 1 && termination1[2] == 1){
		termination2[2] = 0;
		poogyLife--;
		score = score - 5;
	}
	if (enm4.CollisionEnemy(xpos + 150) == 0 && termination2[3] == 1 && termination1[3] == 1){
		termination2[3] = 0;
		poogyLife--;
		score = score - 5;
	}
	if (enm5.CollisionEnemy(xpos + 150) == 0 && termination2[4] == 1 && termination1[4] == 1){
		termination2[4] = 0;
		poogyLife--;
		score = score - 5;
	}



	if (enm1.CollisionClub(xpos, state) == 1 && termination1[0] == 1) {
		iShowImage(enm1.enemyxpos, 110, 300, 350, enm1.enImg);
	}
	else{
		if (colt[0] == 0)
		{
			termination1[0] = 0;
			score = score + 20;
			colt[0] = 1;
		}
	}

	if (enm2.CollisionClub(xpos, state) == 1 && termination1[1] == 1) {
		iShowImage(enm2.enemyxpos, 110, 300, 350, enm2.enImg);
	}
	else {
		if (colt[1] == 0)
		{
			termination1[1] = 0;
			score = score + 20;
			colt[1] = 1;
		}
	}
	if (enm3.CollisionClub(xpos, state) == 1 && termination1[2] == 1) {
		iShowImage(enm3.enemyxpos, 110, 300, 350, enm3.enImg);
	}
	else{
		if (colt[2] == 0)
		{
			termination1[2] = 0;
			score = score + 20;
			colt[2] = 1;
		}
	}
	if (enm4.CollisionClub(xpos, state) == 1 && termination1[3] == 1) {
		iShowImage(enm4.enemyxpos, 110, 300, 350, enm4.enImg);
	}
	else{
		if (colt[3] == 0)
		{
			termination1[3] = 0;
			score = score + 20;
			colt[3] = 1;
		}
	}

	if (enm5.CollisionClub(xpos, state) == 1 && termination1[4] == 1) {
		iShowImage(enm5.enemyxpos, 110, 300, 350, enm5.enImg);
	}
	else{
		if (colt[4] == 0)
		{
			termination1[4] = 0;
			score = score + 20;
			colt[4] = 1;
		}
	}







	if (poogyLife == 5)
	{
		iShowImage(100, 600, 30, 30, heart[0]);
		iShowImage(100 + 30, 600, 30, 30, heart[0]);
		iShowImage(100 + 60, 600, 30, 30, heart[0]);
		iShowImage(100 + 90, 600, 30, 30, heart[0]);
		iShowImage(100 + 120, 600, 30, 30, heart[0]);
	}


	if (poogyLife == 4)
	{
		iShowImage(100, 600, 30, 30, heart[0]);
		iShowImage(100 + 30, 600, 30, 30, heart[0]);
		iShowImage(100 + 60, 600, 30, 30, heart[0]);
		iShowImage(100 + 90, 600, 30, 30, heart[0]);
	}


	if (poogyLife == 3)
	{
		iShowImage(100, 600, 30, 30, heart[0]);
		iShowImage(100 + 30, 600, 30, 30, heart[0]);
		iShowImage(100 + 60, 600, 30, 30, heart[0]);
	}


	if (poogyLife == 2)
	{
		iShowImage(100, 600, 30, 30, heart[0]);
		iShowImage(100 + 30, 600, 30, 30, heart[0]);
	}

	if (poogyLife == 1)
	{
		iShowImage(100, 600, 30, 30, heart[0]);

	}

	if (poogyLife <= 0)
	{

		sortScore();
		i = 0; poogyLife = 5; score = 0; xpos = 30; lvl = 0;
	}


	if (score > 170 && score < 270){
		lvl = 2;
	}
	else if (score > 300)
		lvl = 3;

	if (lvl == 2)
		ed = 10;
	if (lvl == 3)
	{
		//iClear();
		//	gameScene();

		//iShowImage(0, 0, 1200, 657, bck);
		//iShowImage(900, 80, 300, 300, dragon);

		ed = 10;

		//iShowImage(fb1.fbxpos, 280, 60, 60, fb1.fbImg);
		if (fb1.CollisionClub(xpos, state) == 1 && terminationfb1[0] == 1) {
			iShowImage(fb1.fbxpos, 110, 300, 350, fb1.fbImg);
		}
		else{
			if (fbolt[0] == 0)
			{
				terminationfb1[0] = 0;
				score = score + 20;
				fbolt[0] = 1;
			}
		}
		if (fb1.CollisionFireball(xpos + 150) == 0 && terminationfb2[0] == 1 && terminationfb1[0] == 1){
			termination2[0] = 0;
			poogyLife--;
			score = score - 5;
		}


	}
	if (score >= 500)
		i=8;



	iSetColor(255, 0, 0);
	iText(40, 608, "LIFE:", GLUT_BITMAP_TIMES_ROMAN_24);

	_itoa(score, scorearray, 10);
	_itoa(lvl, lvlarray, 10);
	iText(1010, 608, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1100, 608, scorearray, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 608, "LEVEL:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(590, 608, lvlarray, GLUT_BITMAP_TIMES_ROMAN_24);


}

void changeState(){

	state = 0;
}


void save(){


	FILE *fp1 = fopen("save.txt", "w");
	fprintf(fp1, "%d %d %d", poogyLife, xpos, score);
	fclose(fp1);
}

void load(){

	FILE *fp2 = fopen("save.txt", "r");
	fscanf(fp2, "%d %d %d", &poogyLife, &xpos, &score);
	fclose(fp2);
}







void nameInfo(){
	iShowImage(0, 0, 1200, 675, nm);
	iSetColor(255, 0, 0);

	iFilledRectangle(400, 300, 400, 60);
	iSetColor(255, 255, 255);
	iText(405, 325, str, GLUT_BITMAP_HELVETICA_18);
	iText(400, 365, "Enter Name", GLUT_BITMAP_HELVETICA_18);
	FILE *fp = fopen("NameInfo.txt", "w");
	fprintf(fp, "%s", str);
	fclose(fp);

}




void showScore()
{

	char hi_name[3][10];
	char hiscore[3][5];
	FILE *fpp = fopen("highscore.txt", "r");
	for (int loop = 0; loop<3; loop++)
	{
		fscanf(fpp, "%s %s", &hi_name[loop], &hiscore[loop]);
	}
	fclose(fpp);
	iClear();
	iSetColor(255, 255, 255);
	iText(400, 620, hi_name[0], GLUT_BITMAP_HELVETICA_18);
	iText(500, 620, hiscore[0], GLUT_BITMAP_HELVETICA_18);
	iText(400, 560, hi_name[1], GLUT_BITMAP_HELVETICA_18);
	iText(500, 560, hiscore[1], GLUT_BITMAP_HELVETICA_18);
	iText(400, 500, hi_name[2], GLUT_BITMAP_HELVETICA_18);
	iText(500, 500, hiscore[2], GLUT_BITMAP_HELVETICA_18);



}
void instruction()
{
	iSetColor(250, 150, 30);
	iFilledRectangle(0, 0, 1200, 675);
	iSetColor(0, 0, 0);
	iText(480, 620, "Instruction", GLUT_BITMAP_HELVETICA_18);

	iText(400, 520, "1.Use left/right to move", GLUT_BITMAP_HELVETICA_18);
	iText(400, 480, "2.press x anywhere to return to menu", GLUT_BITMAP_HELVETICA_18);
	iText(400, 440, "3.press 'Load' to run from the last progress", GLUT_BITMAP_HELVETICA_18);
}
void menu()
{
	iShowImage(0, 0, 1200, 675, image1);
	iSetColor(255, 255, 255);

	iFilledRectangle(90, 365, 150, 50);
	iFilledRectangle(90, 295, 150, 50);
	iFilledRectangle(90, 225, 150, 50);
	iFilledRectangle(90, 155, 150, 50);
	iFilledRectangle(90, 85, 150, 50);
	iSetColor(0, 250, 0);
	iFilledRectangle(1000, 40, 150, 50);
	iFilledRectangle(600, 40, 150, 50);


	iSetColor(0, 0, 0);

	iText(140, 385, "Start", GLUT_BITMAP_HELVETICA_18);
	iText(140, 315, "Load", GLUT_BITMAP_HELVETICA_18);
	iText(127, 245, "Instruction", GLUT_BITMAP_HELVETICA_18);
	iText(130, 175, "HighScore", GLUT_BITMAP_HELVETICA_18);
	iText(140, 105, "Quit", GLUT_BITMAP_HELVETICA_18);
	iText(140, 105, "Quit", GLUT_BITMAP_HELVETICA_18);
	iText(1050, 60, "Story", GLUT_BITMAP_HELVETICA_18);
	iText(650, 60, "Name", GLUT_BITMAP_HELVETICA_18);
	menut = 1;

	//gameScene();
}





#endif // FUNCTIONS_H_INCLUDED
