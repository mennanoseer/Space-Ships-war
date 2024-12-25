#include <GL/glut.h>
#include <cstdio>
#include "text_utils.h"
#include "shape_utils.h"
#include "screen_utils.h"
#include "view.h"

extern GLfloat backgroundColor[];
extern GLfloat fontColor[];
extern float mouseX, mouseY;
extern bool mButtonPressed;
extern int alienLife1, alienLife2;
extern bool laser1, laser2;
extern bool laser1Dir[2], laser2Dir[2];
extern view viewPage;

void introScreen() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Set different colors for various text
	glColor3f(1.0, 0.0, 0.0);
	displayRasterText(-425, 490, 0.0, "Egypt Japan university of science and technology ");

	glColor3f(0.0, 0.0, 0.0);
	displayRasterText(-50, 385, 0.0, "CSE");

	glColor3f(0.0, 0.0, 1.0);
	displayRasterText(-225, 300, 0.0, "Space Shooter Project");
	drawIntroSpaceship(-8.0, 200.0);

	// Names and IDs
	glColor3f(1.0, 0.0, 0.0);
	displayRasterText(-800, -100, 0.0, "STUDENT NAMES & IDs:");
	glColor3f(0.0, 0.0, 0.0);
	displayRasterText(-800, -200, 0.0, "Menna Noseer                 120210164");
	displayRasterText(-800, -285, 0.0, "Youssef Elamir                 120210179");
	displayRasterText(-800, -370, 0.0, "Abdelrahman Galhom     120210209");

	glColor3f(1.0, 0.0, 0.0);
	displayRasterText(500, -100, 0.0, "Instructor Name");
	glColor3f(0.0, 0.0, 0.0);
	displayRasterText(500, -200, 0.0, "Eng Yasser Roheim");
	glColor3f(0.7, 0.0, 0.5);
	displayRasterText(-300, -550, 0.0, "Press ENTER to start the game");

	glFlush();
	glutSwapBuffers();
}

void startScreenDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
	// Set border color to dark green (RGB: 0, 128, 0)
	glColor3f(0.0f, 0.5f, 0.0f);  // Dark green color
	// Set the border width to make it thicker
	glLineWidth(5);  // Thicker border
	glBegin(GL_LINE_LOOP);  // Border
	glVertex2f(-750, -500);
	glVertex2f(-750, 550);
	glVertex2f(750, 550);
	glVertex2f(750, -500);
	glEnd();
	// Reset line width to default
	glLineWidth(1);

	// Set button color to blue (RGB: 0, 0, 255)
	glColor3f(0.0f, 1.0f, 1.0f);
	drawRoundedRectangle(-200, 300, 200, 400, 20);  // Start Game Button

	// Set Instructions button color to orange (RGB: 255, 165, 0)
	glColor3f(1.0f, 0.647f, 0.0f);  // Orange
	drawRoundedRectangle(-200, 50, 200, 150, 20);  // Instructions Button

	// Set Quit button color to purple (RGB: 128, 0, 128)
	glColor3f(0.501f, 0.0f, 0.501f);  // Purple
	drawRoundedRectangle(-200, -200, 200, -100, 20);  // Quit Button

	// Handle Start Game button hover effect
	if (mouseX >= -100 && mouseX <= 100 && mouseY >= 150 && mouseY <= 200) {
		glColor3f(1, 1, 1);  // Hover effect (Blue) for Start Game
		if (mButtonPressed) {
			alienLife1 = alienLife2 = 100;
			viewPage = GAME;
			mButtonPressed = false;
		}
	}
	else glColor3f(0, 0, 0);  // Default font color (black)

	displayRasterText(-100, 340, 0.4, "Start Game");
	// Handle Instructions button hover effect
	if (mouseX >= -100 && mouseX <= 100 && mouseY >= 30 && mouseY <= 80) {
		glColor3f(1, 1, 1);  // Hover effect (Blue) for Instructions
		if (mButtonPressed) {
			viewPage = INSTRUCTIONS;
			mButtonPressed = false;
		}
	}
	else glColor3f(0, 0, 0);  // Default font color (black)
	
	displayRasterText(-100, 80, 0.4, "Instructions");
	// Handle Quit button hover effect
	if (mouseX >= -100 && mouseX <= 100 && mouseY >= -90 && mouseY <= -40) {
		glColor3f(1, 1, 1);  // Hover effect (Blue) for Quit
		if (mButtonPressed) {
			mButtonPressed = false;
			exit(0);  // Exit the application
		}
	}
	else {
		glColor3f(0, 0, 0);  // Default font color (black)
	}
	displayRasterText(-47, -170, 0.4, "Quit");

	glutSwapBuffers();  // Swap buffers for double buffering
}

// Function to display the start screen (menu)
void backButton() {
	if (mouseX <= -450 && mouseX >= -500 && mouseY >= -275 && mouseY <= -250) {
		glColor3f(0, 0, 1);
		if (mButtonPressed) {
			viewPage = MENU;
			mButtonPressed = false;
			//instructionsGame = false;
			glutPostRedisplay();
		}
	}
	else glColor3f(1, 0, 0);
	displayRasterText(-1000, -550, 0, "Back");
}

void instructionsScreenDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//SetDisplayMode(MENU_SCREEN);
	//colorBackground();
	glColor3f(1, 0, 0);
	displayRasterText(-900, 550, 0.4, "INSTRUCTIONS");
	glColor3f(1, 0, 0);
	displayRasterText(-1000, 400, 0.4, "PLAYER 1");
	displayRasterText(200, 400, 0.4, "PLAYER 2");
	glColor3f(0, 0, 0);
	displayRasterText(-1100, 300, 0.4, "Key 'w' to move up.");
	displayRasterText(-1100, 200, 0.4, "Key 's' to move down.");
	displayRasterText(-1100, 100, 0.4, "Key 'd' to move right.");
	displayRasterText(-1100, 0, 0.4, "Key 'a' to move left.");
	displayRasterText(100, 300, 0.4, "Key 'i' to move up.");
	displayRasterText(100, 200, 0.4, "Key 'k' to move down.");
	displayRasterText(100, 100, 0.4, "Key 'j' to move right.");
	displayRasterText(100, 0, 0.4, "Key 'l' to move left.");
	displayRasterText(-1100, -100, 0.4, "Key 'c' to shoot, Use 'w' and 's' to change direction.");
	displayRasterText(100, -100, 0.4, "Key 'm' to shoot, Use 'i' and 'k' to change direction.");
	//displayRasterText(-1100 ,-100 ,0.4 ,"The packet can be placed only when 's' is pressed before.");
	displayRasterText(-1100, -300, 0.4, "The Objective is to kill your opponent.");
	displayRasterText(-1100, -370, 0.4, "Each time a player gets shot, LIFE decreases by 5 points.");
	backButton();
	//if(previousScreen)
	//	nextScreen = false ,previousScreen = false; //as set by backButton()
}

void DisplayHealthBar1()
{
	char temp1[40];
	glColor3f(0, 0, 0);
	sprintf(temp1, "  LIFE = %d", alienLife1);
	displayRasterText(-1100, 600, 0.4, temp1);
	glColor3f(1, 0, 0);
}

void DisplayHealthBar2()
{
	char temp2[40];
	glColor3f(0, 0, 0);
	sprintf(temp2, "  LIFE = %d", alienLife2);
	displayRasterText(800, 600, 0.4, temp2);
	glColor3f(1, 0, 0);
}

void displayGameOverMessage()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

	// Set color to red and display the main game-over message
	glColor3f(1, 0, 0);
	const char *message;
	if (alienLife1 > 0)
		message = "Game Over! Player 1 won the game";
	else
		message = "Game Over! Player 2 won the game";

	displayRasterText(-200, 50, 0, message); 

	glColor3f(0, 0, 1);
	const char *secondaryMessage = "Press Enter to return to the menu";

	displayRasterText(-200, -200, 0, secondaryMessage); 

	glutSwapBuffers(); 
}
