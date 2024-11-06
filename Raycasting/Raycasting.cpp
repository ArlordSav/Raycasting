#include "constants.h"
#include "raycasting.h"
#include "worldMap.h"
#include <cmath>

Color Buffer[screenWidth][screenHeight];

Image Tex[6];

double cameraX;
Vector2 rayDir;

Vector2 map;

Vector2 sideDist;

Vector2 deltaDist;

double perpWallDist;

Vector2 step;

bool hit;
bool side;

//drawing variables

int lineHeight;

int drawStart;
int drawEnd;



Vector2 pos;
Vector2 dir;
Vector2 plane;

double wallX; //where exactly the wall was hit
int texX;
int texY;
double Step;
double texPos;
int texNum;

Color colour;

float Distance(float x1, float y1, float x2, float y2) {
    return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

void raycast() {
    
    for (int x = 0; x < w; x++) {

        cameraX = 2 * x / (double)w - 1;
        rayDir.x = dir.x + plane.x * cameraX;
        rayDir.y = dir.y + plane.y * cameraX;

        map.x = int(pos.x);
        map.y = int(pos.y);


        deltaDist.x = (rayDir.x == 0) ? 1e30 : std::abs(1 / rayDir.x);
        deltaDist.y = (rayDir.y == 0) ? 1e30 : std::abs(1 / rayDir.y);



        hit = 0;
        side;

        if (rayDir.x < 0) {
            step.x = -1;
            sideDist.x = (pos.x - map.x) * deltaDist.x;
        }
        else {
            step.x = 1;
            sideDist.x = (map.x + 1.0 - pos.x) * deltaDist.x;
        }
        if (rayDir.y < 0) {
            step.y = -1;
            sideDist.y = (pos.y - map.y) * deltaDist.y;
        }
        else {
            step.y = 1;
            sideDist.y = (map.y + 1.0 - pos.y) * deltaDist.y;
        }

        while (hit == 0) {

            if (sideDist.x < sideDist.y) {
                sideDist.x += deltaDist.x;
                map.x += step.x;
                side = 0;
            }
            else {
                sideDist.y += deltaDist.y;
                map.y += step.y;
                side = 1;
            }
            if (worldMap[(int)map.x][(int)map.y] != 0)
            {
                hit = 1;
            }
            
        }

        if (side == 0) perpWallDist = (sideDist.x - deltaDist.x);
        else          perpWallDist = (sideDist.y - deltaDist.y);

        lineHeight = (int)(h / perpWallDist);

        drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) drawStart = 0;
        drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) drawEnd = h - 1;
        /*
        switch (worldMap[int(map.x)][int(map.y)])
        {
        case 1:  colour = RED;    break; //red
        case 2:  colour = GREEN;  break; //green
        case 3:  colour = BLUE;   break; //blue
        case 4:  colour = WHITE;  break; //white
        default: colour = YELLOW; break; //yellow
        }*/

        //give x and y sides different brightness
        if (side == 1) { colour.r /= 2; colour.g /= 2; colour.b /= 2; }

        //draw the pixels of the stripe as a vertical line
        
        
        
        
        
        
        if (side == 0) wallX = pos.y + perpWallDist * rayDir.y;
        else          wallX = pos.x + perpWallDist * rayDir.x;
        wallX -= floor((wallX));
        //calculate value of wallX
        texX = int(wallX * double(texWidth));
        if (side == 0 && rayDir.x > 0) texX = texWidth - texX - 1;
        if (side == 1 && rayDir.y < 0) texX = texWidth - texX - 1;

        // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
        // How much to increase the texture coordinate per screen pixel
        Step = 1.0 * texHeight / lineHeight;
        // Starting texture coordinate
        texPos = (drawStart - h / 2 + lineHeight / 2) * Step;

        texNum = worldMap[int(map.x)][int(map.y)] - 1;

        for (int y = drawStart; y < drawEnd; y++)
        {
            // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            texY = (int)texPos & (texHeight - 1);
            texPos += Step;

            colour = GetImageColor(Tex[texNum], texX, texY);
                        
            if (side == 1) { colour.r /= 1.5; colour.g /= 1.5; colour.b /= 1.5; }
            
            
            DrawPixel(x, y, colour);
            //Buffer[x][y] = colour;
        }


    }


}
