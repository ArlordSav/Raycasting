#ifndef RAYCASTING_H
#define RAYCASTING_H


#include <raylib.h>

void raycast();


extern Color Buffer[screenWidth][screenHeight];

extern Image Tex[6];

extern double cameraX;
extern Vector2 rayDir;

extern Vector2 map;

extern Vector2 sideDist;

extern Vector2 deltaDist;

extern double perpWallDist;

extern Vector2 step;

extern bool hit;
extern bool side;

//drawing variables

extern int lineHeight;

extern int drawStart;
extern int drawEnd;



extern Vector2 pos;
extern Vector2 dir;
extern Vector2 plane;

extern double wallX; //where exactly the wall was hit
extern int texX;
extern int texY;
extern double Step;
extern double texPos;
extern int texNum;

extern Color colour;







#endif // RAYCASTING