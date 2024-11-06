#include <raylib.h>

#include "worldMap.h"
#include "raycasting.h"
#include "input.h"
#include <cmath>


double moveSpeed; 
double rotSpeed; 
double olddirX;
double oldPlaneX;


void input() {
    
    moveSpeed = GetFrameTime() * 5.0;
    rotSpeed = GetFrameTime() * 3.0;
    
    if (IsKeyPressed(KEY_F)) {
        ToggleFullscreen();
    }

    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        moveSpeed *= 2;
    }
    //move forward if no wall in front of you
    if (IsKeyDown(KEY_W))
    {
        if (worldMap[int(pos.x + dir.x * moveSpeed)][int(pos.y)] == false) pos.x += dir.x * moveSpeed;
        if (worldMap[int(pos.x)][int(pos.y + dir.y * moveSpeed)] == false) pos.y += dir.y * moveSpeed;
    }
    //strafe
    if (IsKeyDown(KEY_A))
    {
        if (worldMap[int(pos.x - plane.x * moveSpeed)][int(pos.y)] == false) pos.x -= plane.x * moveSpeed;
        if (worldMap[int(pos.x)][int(pos.y - plane.y * moveSpeed)] == false) pos.y -= plane.y * moveSpeed;
    }
    //move backwards if no wall behind you
    if (IsKeyDown(KEY_S))
    {
        if (worldMap[int(pos.x - dir.x * moveSpeed)][int(pos.y)] == false) pos.x -= dir.x * moveSpeed;
        if (worldMap[int(pos.x)][int(pos.y - dir.y * moveSpeed)] == false) pos.y -= dir.y * moveSpeed;
    }
    //strafe
    if (IsKeyDown(KEY_D))
    {
        if (worldMap[int(pos.x + plane.x * moveSpeed)][int(pos.y)] == false) pos.x += plane.x * moveSpeed;
        if (worldMap[int(pos.x)][int(pos.y + plane.y * moveSpeed)] == false) pos.y += plane.y * moveSpeed;
    }
    //rotate to the right
    if (IsKeyDown(KEY_RIGHT))
    {
        //both camera direction and camera plane must be rotated
        olddirX = dir.x;
        dir.x = dir.x * cos(-rotSpeed) - dir.y * sin(-rotSpeed);
        dir.y = olddirX * sin(-rotSpeed) + dir.y * cos(-rotSpeed);
        oldPlaneX = plane.x;
        plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
        plane.y = oldPlaneX * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
    }
    //rotate to the left
    if (IsKeyDown(KEY_LEFT))
    {
        //both camera direction and camera plane must be rotated
        olddirX = dir.x;
        dir.x = dir.x * cos(rotSpeed) - dir.y * sin(rotSpeed);
        dir.y = olddirX * sin(rotSpeed) + dir.y * cos(rotSpeed);
        oldPlaneX = plane.x;
        plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
        plane.y = oldPlaneX * sin(rotSpeed) + plane.y * cos(rotSpeed);
    }
}