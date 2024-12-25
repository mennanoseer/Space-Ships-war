#include <GL/glut.h>
#include "text_utils.h"

void displayRasterText(float x, float y, float z, const char* stringToDisplay) {
	glRasterPos3f(x, y, z);
	for (const char* c = stringToDisplay; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
