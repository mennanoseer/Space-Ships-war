#include <GL/glut.h>
#include <cmath>
#include "shape_utils.h"

#define M_PI 3.14159265358979323846

void drawRoundedRectangle(float x1, float y1, float x2, float y2, float radius) {
	int num_segments = 20; // Number of segments for the curve
	float angle_step = M_PI / 2 / num_segments;

	// Draw four corners of the rounded rectangle
	for (int i = 0; i < 4; i++) {
		float angle_offset = i * M_PI / 2;
		glBegin(GL_POLYGON);
		for (int j = 0; j < num_segments; j++) {
			float angle = angle_offset + j * angle_step;
			glVertex2f(x1 + radius + (x2 - x1 - 2 * radius) * (i % 2),
				y1 + radius + (y2 - y1 - 2 * radius) * (i / 2));
		}
		glEnd();
	}

	// Draw the main body of the button (rectangle with straight edges)
	glBegin(GL_POLYGON);
	glVertex2f(x1 + radius, y1);  // Bottom-left
	glVertex2f(x2 - radius, y1);  // Bottom-right
	glVertex2f(x2 - radius, y2);  // Top-right
	glVertex2f(x1 + radius, y2);  // Top-left
	glEnd();
}

void drawIntroSpaceship(float x, float y) {
	// Main body (central hull of the spaceship)
	glColor3f(0.6f, 0.6f, 0.6f);  // Light gray color
	glBegin(GL_POLYGON);  // Body
	glVertex2f(x, y);  // Tip of the spaceship
	glVertex2f(x - 40, y - 80);  // Left bottom
	glVertex2f(x - 20, y - 120);  // Left wing bottom
	glVertex2f(x + 20, y - 120);  // Right wing bottom
	glVertex2f(x + 40, y - 80);  // Right bottom
	glEnd();

	// Cockpit (front part of the spaceship)
	glColor3f(0.0f, 0.2f, 0.7f);  // Blue cockpit
	glBegin(GL_QUADS);
	glVertex2f(x - 10, y + 20);  // Bottom left of the cockpit
	glVertex2f(x + 10, y + 20);  // Bottom right of the cockpit
	glVertex2f(x + 10, y + 60);  // Top right of the cockpit
	glVertex2f(x - 10, y + 60);  // Top left of the cockpit
	glEnd();

	// Engines (two exhausts)
	glColor3f(0.0f, 0.0f, 0.0f);  // Light gray for engine
	glBegin(GL_QUADS);
	glVertex2f(x - 35, y - 120);  // Left exhaust start
	glVertex2f(x - 25, y - 140);  // Left exhaust end
	glVertex2f(x - 25, y - 140);  // Left exhaust right
	glVertex2f(x - 35, y - 160);  // Left exhaust bottom
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(x + 25, y - 120);  // Right exhaust start
	glVertex2f(x + 35, y - 140);  // Right exhaust end
	glVertex2f(x + 35, y - 140);  // Right exhaust right
	glVertex2f(x + 25, y - 160);  // Right exhaust bottom
	glEnd();

	// Left wing details
	glColor3f(0.3f, 0.3f, 0.3f);  // Darker gray for wing
	glBegin(GL_TRIANGLES);
	glVertex2f(x - 40, y - 80);  // Left wing top
	glVertex2f(x - 70, y - 100);  // Left wing bottom left
	glVertex2f(x - 20, y - 120);  // Left wing bottom right
	glEnd();

	// Right wing details
	glBegin(GL_TRIANGLES);
	glVertex2f(x + 40, y - 80);  // Right wing top
	glVertex2f(x + 70, y - 100);  // Right wing bottom right
	glVertex2f(x + 20, y - 120);  // Right wing bottom left
	glEnd();
}
