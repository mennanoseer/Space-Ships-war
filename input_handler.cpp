#include <GL/glut.h>
#include "input_handler.h"

extern bool keyStates[256];
extern bool mButtonPressed;
extern float mouseX, mouseY;
extern GLint m_viewport[4];

void keyPressed(unsigned char key, int x, int y){
    keyStates[key] = true;
    glutPostRedisplay();
}

void refresh(){
    glutPostRedisplay();
}

void keyReleased(unsigned char key, int x, int y){
    keyStates[key] = false;
}

void mouseClick(int buttonPressed, int state, int x, int y){

    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}

void passiveMotionFunc(int x, int y){

    // map the mouse coordinates/screen to the world coordinates
    mouseX = float(x) / (m_viewport[2] / 1200.0) - 600.0; 
    mouseY = -(float(y) / (m_viewport[3] / 700.0) - 350.0);

    glutPostRedisplay();
}
