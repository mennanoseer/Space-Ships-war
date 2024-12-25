#ifndef SPACESHIP_FUNCTIONS_H
#define SPACESHIP_FUNCTIONS_H

void DrawAlienBody(bool isPlayer1);
void DrawAlienCollar(bool isPlayer1);
void DrawAlienFace(bool isPlayer1);
void DrawAlienBeak(bool isPlayer1);
void DrawAlienEyes(bool isPlayer1);
void DrawAlien(bool isPlayer1);

void DrawSpaceshipBody(bool isPlayer1);
void DrawSteeringWheel();
void DrawSpaceshipDoom(bool isPlayer1);
void DrawLaser(int x, int y, bool dir[]);
void SpaceshipCreate(int x, int y, bool isPlayer1);

#endif 
