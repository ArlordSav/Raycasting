#ifndef INPUT_H
#define INPUT_H

extern double InputframeTime;
extern double moveSpeed; //the constant value is in squares/second
extern double rotSpeed; //the constant value is in radians/second

extern double olddirX;
extern double oldPlaneX;

void input();
#endif //INPUT_H