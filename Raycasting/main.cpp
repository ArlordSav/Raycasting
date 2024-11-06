#include "raylib.h"
#include <cmath>
#include <iostream>


#include "constants.h"
#include "worldMap.h"
#include "raycasting.h"
#include "input.h"





void DrawBuffer(int W,int H,Color Buf[screenWidth][screenHeight]) {
    
    for (int i= 1; i < W; i++) {
        for (int j= 1; j < H; j++) {
            if (Buf[i][j].r == 0 && Buf[i][j].g == 0 && Buf[i][j].b == 0) { continue; }
            DrawPixel(i, j, Buf[i][j]);
        }
    }
}



void input();

int main(){
    
    InitWindow(screenWidth, screenHeight, "raycasting ong fr fr");
    //ToggleFullscreen();
    
    Tex[0] = LoadImage("Tex1.png");    
    Tex[1] = LoadImage("Tex2.png");
    Tex[2] = LoadImage("Tex3.png");
    Tex[3] = LoadImage("Tex4.png");
    Tex[4] = LoadImage("Tex5.png");  
    Tex[5] = LoadImage("Tex6.png");
    
    pos = { 10,10 };
    dir = { -1, 0 };
    plane = { 0,0.70 };
    
    
    while (!WindowShouldClose()) {
        
        input();
        //for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) Buffer[j][i] = BLACK;
        //raycast();
        
        BeginDrawing();
        ClearBackground({0,0,0,0});
        DrawRectangle(0, screenHeight / 2, screenWidth, screenHeight / 2, DARKGRAY);
        //DrawBuffer(screenWidth, screenHeight, Buffer);
        raycast();
        DrawFPS(0, 0);
        
        EndDrawing();
        
        
    }
    UnloadImage(Tex[0]);
    UnloadImage(Tex[1]);
    UnloadImage(Tex[2]);
    UnloadImage(Tex[3]);
    UnloadImage(Tex[4]);
    CloseWindow();        
    
    return 0;
}

