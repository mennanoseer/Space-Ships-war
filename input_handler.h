#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

void keyPressed(unsigned char key, int x, int y);
void refresh();
void keyReleased(unsigned char key, int x, int y);
void mouseClick(int buttonPressed, int state, int x, int y);
void passiveMotionFunc(int x, int y);

#endif
