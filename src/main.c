// The main function of this MazLap
#include <raylib.h>

// local liberaries
#include "maze/maze.h"



int main(void)
{
Cell test;

test.top = 1;


    float playerX = 100;
    float playerY = 100;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "MazLap");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_LEFT))
            playerX -=30;
        if (IsKeyPressed(KEY_RIGHT))
            playerX +=30;
        if (IsKeyPressed(KEY_UP))
            playerY -=30;
        if (IsKeyPressed(KEY_DOWN))
            playerY +=30;

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
        DrawRectangle((int)playerX, (int)playerY,30,30, BLUE);
        EndDrawing();

        drawMaze();
        drawCell(test,0,0);
    }
    CloseWindow();

    return 0;
}