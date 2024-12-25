#include "spaceship_functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#define GL_SILENCE_DEPRECATION
#define XMAX 1200
#define YMAX 700
GLint CI = 0;


GLfloat LightColor[][3] = { 0.17, 0.75, 0.58   ,   0.71, 0.11, 0.35,   0.94, 0.55, 0.04 };
GLfloat AlienBody[][2] = { {-4,9}, {-6,0}, {0,0}, {0.5,9}, {0.15,12}, {-14,18}, {-19,10}, {-20,0},{-6,0} };
GLfloat AlienCollar[][2] = { {-9,10.5}, {-6,11}, {-5,12}, {6,18}, {10,20}, {13,23}, {16,30}, {19,39}, {16,38},
						  {10,37}, {-13,39}, {-18,41}, {-20,43}, {-20.5,42}, {-21,30}, {-19.5,23}, {-19,20},
						  {-14,16}, {-15,17},{-13,13},  {-9,10.5} };
GLfloat ALienFace[][2] = { {-6,11}, {-4.5,18}, {0.5,20}, {0.,20.5}, {0.1,19.5}, {1.8,19}, {5,20}, {7,23}, {9,29},
						{6,29.5}, {5,28}, {7,30}, {10,38},{11,38}, {11,40}, {11.5,48}, {10,50.5},{8.5,51}, {6,52},
						{1,51}, {-3,50},{-1,51}, {-3,52}, {-5,52.5}, {-6,52}, {-9,51}, {-10.5,50}, {-12,49}, {-12.5,47},
						{-12,43}, {-13,40}, {-12,38.5}, {-13.5,33},{-15,38},{-14.5,32},  {-14,28}, {-13.5,33}, {-14,28},
						{-13.8,24}, {-13,20}, {-11,19}, {-10.5,12}, {-6,11} };
GLfloat ALienBeak[][2] = { {-6,21.5}, {-6.5,22}, {-9,21}, {-11,20.5}, {-20,20}, {-14,23}, {-9.5,28}, {-7,27}, {-6,26.5},
						{-4.5,23}, {-4,21}, {-6,19.5}, {-8.5,19}, {-10,19.5}, {-11,20.5} };


void DrawAlienBody(bool isPlayer1)
{
	if (isPlayer1)
		glColor3f(0.9, 0.9, 0.86);
	else
		glColor3f(0.3, 0.2, 0.23); //BODY color
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 8; i++)
		glVertex2fv(AlienBody[i]);
	glEnd();

	glColor3f(0, 0, 0);			//BODY Outline
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 8; i++)
		glVertex2fv(AlienBody[i]);
	glEnd();

	glBegin(GL_LINES);                //BODY effect
	glVertex2f(-13, 11);
	glVertex2f(-15, 9);
	glEnd();
}
void DrawAlienCollar(bool isPlayer1)
{
	if (isPlayer1)
		glColor3f(0.9, 0.9, 0.86);
	else
		glColor3f(0.3, 0.2, 0.23); //COLLAR color
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 20; i++)
		glVertex2fv(AlienCollar[i]);
	glEnd();

	glColor3f(0, 0, 0);				//COLLAR outline
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 20; i++)
		glVertex2fv(AlienCollar[i]);
	glEnd();
}
void DrawAlienFace(bool isPlayer1) {
	//FACE
	if (isPlayer1)
		glColor3f(0.1, 0.1, 0);
	else
		glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	for (int i = 0; i <= 42; i++)
		glVertex2fv(ALienFace[i]);
	glEnd();

	glColor3f(0, 0, 0);				//FACE outline
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 42; i++)
		glVertex2fv(ALienFace[i]);
	glEnd();

	glBegin(GL_LINE_STRIP);      //EAR effect
	glVertex2f(3.3, 22);
	glVertex2f(4.4, 23.5);
	glVertex2f(6.3, 26);
	glEnd();
}
void DrawAlienBeak(bool isPlayer1)
{
	if (isPlayer1)
		glColor3f(0.9, 0.9, 0.86);
	else
		glColor3f(0.3, 0.2, 0.23);//BEAK color
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 14; i++)
		glVertex2fv(ALienBeak[i]);
	glEnd();

	glColor3f(0, 0, 0);				//BEAK outline
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 14; i++)
		glVertex2fv(ALienBeak[i]);
	glEnd();
}
void DrawAlienEyes(bool isPlayer1)
{
	if (isPlayer1)
		glColor3f(1, 1, 1);
	else
		glColor3f(0, 0, 0);

	glPushMatrix();
	glRotated(-10, 0, 0, 1);
	glTranslated(-6, 32.5, 0);      //Left eye
	glScalef(2.5, 4, 0);
	glutSolidSphere(1, 20, 30);
	glPopMatrix();

	glPushMatrix();
	glRotated(-1, 0, 0, 1);
	glTranslated(-8, 36, 0);							//Right eye
	glScalef(2.5, 4, 0);
	glutSolidSphere(1, 100, 100);
	glPopMatrix();
}
void DrawAlien(bool isPlayer1)
{
	DrawAlienBody(isPlayer1);
	DrawAlienCollar(isPlayer1);
	DrawAlienFace(isPlayer1);
	DrawAlienBeak(isPlayer1);
	DrawAlienEyes(isPlayer1);
}
void DrawSpaceshipBody(bool isPlayer1)
{
	if (isPlayer1)
		glColor3f(0.3, 0.25, 0.79);			//BASE
	else
		//glColor3f(0.05, 0.24, 0.01);
		glColor3f(0.01, 0.18, 0.48);

	glPushMatrix();
	glScalef(70, 20, 1);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glPushMatrix();							//LIGHTS
	glScalef(3, 3, 1);
	glTranslated(-20, 0, 0);			//1
	glColor3fv(LightColor[(CI + 0) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//2
	glColor3fv(LightColor[(CI + 1) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//3
	glColor3fv(LightColor[(CI + 2) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//4
	glColor3fv(LightColor[(CI + 0) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//5
	glColor3fv(LightColor[(CI + 1) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//6
	glColor3fv(LightColor[(CI + 2) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//7
	glColor3fv(LightColor[(CI + 0) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//8
	glColor3fv(LightColor[(CI + 1) % 3]);
	glutSolidSphere(1.4, 10, 30);
	glTranslated(5, 0, 0);					//9
	glColor3fv(LightColor[(CI + 2) % 3]);
	glutSolidSphere(1.4, 10, 30);

	glPopMatrix();
}
void DrawSteeringWheel()
{
	glPushMatrix();
	glLineWidth(3);
	glColor3f(0.10, 0., 0.10);
	glScalef(7, 4, 1);
	glTranslated(-1.9, 5.5, 0);
	glutWireSphere(1, 8, 8);
	glPopMatrix();

}
void DrawSpaceshipDoom(bool isPlayer1)
{
	glColor4f(0.7, 1, 1, 0.0011);
	//if (isPlayer1)
	//	glColor3f(0.5, 0.35, 0.89);			//BASE
	//else
	//	glColor3f(0.15, 0.34, 0.41);

	glPushMatrix();
	glTranslated(0, 30, 0);
	glScalef(35, 50, 1);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();
}

void DrawLaser(int x, int y, bool dir[]) {
	//glPushMatrix();
	int xend = -XMAX, yend = y;
	if (dir[0])
		yend = YMAX;
	else if (dir[1])
		yend = -YMAX;
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(xend, yend);
	glEnd();
	//glPopMatrix();
}

void SpaceshipCreate(int x, int y, bool isPlayer1) {
	glPushMatrix();
	glTranslated(x, y, 0);
	// if(!checkIfSpaceShipIsSafe() && alienLife1 ){
	// 	alienLife1-=10;
	// 	xStart -= 23;
	// }
	DrawSpaceshipDoom(isPlayer1);
	glPushMatrix();
	glTranslated(4, 19, 0);
	DrawAlien(isPlayer1);
	glPopMatrix();
	DrawSteeringWheel();
	DrawSpaceshipBody(isPlayer1);
	// DrawSpaceShipLazer();
	// if(mButtonPressed) {
	// 	DrawLazerBeam();
	// }
	glEnd();
	glPopMatrix();
}
