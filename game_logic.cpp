#include <GL/glut.h>
#include <cstdio>
#include "constants.h"
#include "spaceship_functions.h"
#include "shape_utils.h"
#include "game_logic.h"
#include "view.h"
#include "screen_utils.h"

extern int alienLife1, alienLife2;
extern bool laserHit1, laserHit2;
extern bool laser1, laser2, direction[], laser1Dir[], laser2Dir[];
extern float xOne, yOne, xTwo, yTwo;
extern bool gameOver;
extern int cnt;
extern view viewPage;
extern bool keyStates[256];

// rendering the game screen and updating the game state during each frame
void gameScreenDisplay()
{
    cnt++;
    if (cnt == 100)
    {
        // cooldown mechanism for laser hits to ensure fair gameplay and avoid rapid consecutive hits
        cnt = 0;
        laserHit1 = false;
        laserHit2 = false;
    }
    DisplayHealthBar1();
    DisplayHealthBar2();
    glScalef(2, 2, 0); // scaling the game screen to fit the window
    if (alienLife1 > 0)
    {
        SpaceshipCreate(xOne, yOne, true);
        if (laser1)
        {
            DrawLaser(xOne, yOne, laser1Dir);
            checkLaserContact(xOne, yOne, laser1Dir, -xTwo, yTwo, true);
        }
    }
    else
    {
        viewPage = GAMEOVER;
    }

    if (alienLife2 > 0)
    {
        glPushMatrix();
        glScalef(-1, 1, 1); // flipping the spaceship to face the other player
        SpaceshipCreate(xTwo, yTwo, false);
        if (laser2)
        {
            DrawLaser(xTwo, yTwo, laser2Dir);
            checkLaserContact(xTwo, yTwo, laser2Dir, -xOne, yOne, false);
        }
        glPopMatrix();
    }
    else
    {
        viewPage = GAMEOVER;
    }

    if (viewPage == GAMEOVER)
    {
        xOne = xTwo = 500; // resetting the spaceship positions
        yOne = yTwo = 0;
    }
}

void checkLaserContact(int x, int y, bool dir[], int xp, int yp, bool player1)
{
    int xend = -XMAX, yend = y; // end point of the laser
    xp += 8; // adjust spaceship position to match collision bounds
    yp += 8; 
    // setting the end point of the laser based on the direction
    if (dir[0]) yend = YMAX; // up
    else if (dir[1]) yend = -YMAX; // down

    // Here we find out if the laser(line) intersects with spaceship(circle)
    // by solving the equations for the same and finding the discriminant of the
    // quadratic equation obtained
    // laser equation and collision detection
    float m = (float)(yend - y) / (float)(xend - x); 
    float k = y - m * x; // y-intercept
    
    int r = 50; // radius of the spaceship
    // the equation of the circle is (x - xp)^2 + (y - yp)^2 = r^2
    // The laser’s path is a straight line, so we want to check if
    // the laser intersects this circle by solving for the intersection
    // of the line and the circle, which results in a quadratic equation.
    // using the generalized form for the line-circle intersection:
    float a = 1 + m * m;
    float b = 2 * xp - 2 * m * (k - yp);
    float c = xp * xp + (k - yp) * (k - yp) - r * r;

    float d = (b * b - 4 * a * c); // discriminant 
    printf("\nDiscriminant: %f x: %d, y: %d, xp: %d, yp: %d\n", d, x, y, xp, yp);
    if (d >= 0) // non-negative discriminant means intersection
    {
        if (player1 && !laserHit1) // if player 1's laser hits player 2
        {
            alienLife1 -= 5;
            laserHit1 = true;
        }
        else if (!player1 && !laserHit2)
        {
            alienLife2 -= 5;
            laserHit2 = true;
        }
        //printf("%d %d\n", alienLife1, alienLife2);
    }
}

void keyOperations() {
    // enter key to start the game
	if(keyStates[13] == true && viewPage == INTRO) {
		viewPage = MENU;
		printf("view value changed to %d\n", viewPage);
		printf("enter key pressed\n");
	}

    if (viewPage == GAMEOVER && keyStates[13]) 
    {
        viewPage = MENU;
    }

    if(viewPage == GAME) {
        // reset laser directions
		laser1Dir[0] = laser1Dir[1] = false;
		laser2Dir[0] = laser2Dir[1] = false;

		if(keyStates['c'] == true) {
			laser2 = true;
			if(keyStates['w'] == true) 	laser2Dir[0] = true; // up
			if(keyStates['s'] == true) 	laser2Dir[1] = true; // down
		}
		else {
			laser2 = false;
			if(keyStates['d'] == true) xTwo-=SPACESHIP_SPEED; //right
			if(keyStates['a'] == true) xTwo+=SPACESHIP_SPEED; //left
			if(keyStates['w'] == true) yTwo+=SPACESHIP_SPEED; //up
			if(keyStates['s'] == true) yTwo-=SPACESHIP_SPEED; //down
		}

		if(keyStates['m'] == true) {
			laser1 = true;
			if(keyStates['i'] == true) laser1Dir[0] = true; // up
			if(keyStates['k'] == true) laser1Dir[1] = true; // down
		}
		else {
			laser1 = false;
			if(keyStates['l'] == true) xOne+=SPACESHIP_SPEED; //right
			if(keyStates['j'] == true) xOne-=SPACESHIP_SPEED; // left
			if(keyStates['i'] == true) yOne+=SPACESHIP_SPEED; // up
			if(keyStates['k'] == true) yOne-=SPACESHIP_SPEED; // down
		}
	}
}