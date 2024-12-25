#ifdef _WIN32
	#include<windows.h>
#endif
#define M_PI 3.14159265358979323846

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

#include "constants.h"
#include "spaceship_functions.h" 
#include "text_utils.h"
#include "shape_utils.h"
#include "screen_utils.h"
//#include "diplay_utils.h"
#include "game_logic.h"
#include "input_handler.h"

#define GL_SILENCE_DEPRECATION
GLfloat backgroundColor[] = { 0.0, 0.0, 0.0 }; // Default: black
GLfloat fontColor[] = { 1.0, 0.0, 0.0 }; // Default: red
bool laserHit1 = false;
bool laserHit2 = false;
int cnt = 0;
GLint m_viewport[4];
bool mButtonPressed = false;
float mouseX, mouseY;
enum view {INTRO, MENU, INSTRUCTIONS, GAME, GAMEOVER};
view viewPage = INTRO; // initial value
bool keyStates[256] = {false};
bool direction[4] = {false};
bool laser1Dir[2] = {false};
bool laser2Dir[2] = {false};

int alienLife1 = 100;
int alienLife2 = 100;
bool gameOver = false;
float xOne = 500, yOne = 0;
float xTwo = 500, yTwo = 0;
bool laser1 = false, laser2 = false;
GLfloat a[][2]={0,-50, 70,-50, 70,70, -70,70};


void init() {
	glClearColor(173.0f / 255.0f, 216.0f / 255.0f, 100.0f / 255.0f, 0);  // Set background color
	glColor3f(fontColor[0], fontColor[1], fontColor[2]);  // Set text color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1200, 1200, -700, 700);  // Set the coordinate system for the 2D viewport
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	//glClearColor(, 0 , 0, 1);
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);

	switch (viewPage)
	{
		case INTRO:
			introScreen();
			break;
		case MENU:
			startScreenDisplay();
			break;
		case INSTRUCTIONS:
			instructionsScreenDisplay();
			break;
		case GAME:
			gameScreenDisplay();
			//reset scaling values
			glScalef(1/2 ,1/2 ,0);
			break;
		case GAMEOVER:
			displayGameOverMessage();
			//startScreenDisplay();
			break;
	}

	glFlush();
	glLoadIdentity();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	backgroundColor[0] = 0.0f; backgroundColor[1] = 0.0f; backgroundColor[2] = 0.0f;  // Black background
	fontColor[0] = 1.0f; fontColor[1] = 1.0f; fontColor[2] = 1.0f;  // White text

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Space Ship Wars");
    init();
    //glutReshapeFunc(reshape);
	glutIdleFunc(refresh);
    glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	glutMouseFunc(mouseClick);
	glutPassiveMotionFunc(passiveMotionFunc);
	glGetIntegerv(GL_VIEWPORT ,m_viewport);
    glutDisplayFunc(display);
    glutMainLoop();
}