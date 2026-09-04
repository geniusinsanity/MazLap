// The main function of this MazLap
#include <raylib.h>

// local liberaries
#include "maze/maze.h"



int main(void)
{


    float playerX = 10;
    float playerY = 10;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "MazLap");
    
    mazInit(); 
    generateMaze(0,0);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_LEFT))
            playerX -=40;
        if (IsKeyPressed(KEY_RIGHT))
            playerX +=40;
        if (IsKeyPressed(KEY_UP))
            playerY -=40;
        if (IsKeyPressed(KEY_DOWN))
            playerY +=40;

        if (playerX > (GetScreenWidth() -30))
            playerX = GetScreenWidth() -30;
        if (playerX < 0)
            playerX = 0;
        if (playerY > (GetScreenHeight() -30))
            playerY = GetScreenHeight() -30;
        if (playerY < 0)
            playerY = 0;

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        drawMaze();

        
        DrawRectangle((int)playerX, (int)playerY,30,30, BLUE);

        EndDrawing();

    }
    CloseWindow();

    return 0;
}