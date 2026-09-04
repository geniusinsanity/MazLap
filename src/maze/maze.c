#include "maze.h"
#include <raylib.h>

static int maze[ROWS][COLS] =
{
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
};

Cell cell =
{
    1,  // top
    1,  // right
    1,  // bottom
    1   // left
};

void drawCell(Cell cell, int x, int y)
{
    if (cell.top)
        DrawRectangle(x, y, CELL_SIZE, WALL_SIZE, GRAY);

    if (cell.right)
        DrawRectangle(x + CELL_SIZE - WALL_SIZE, y, WALL_SIZE, CELL_SIZE, GRAY);

    if (cell.bottom)
        DrawRectangle(x, y + CELL_SIZE - WALL_SIZE, CELL_SIZE, WALL_SIZE, GRAY);

    if (cell.left)
        DrawRectangle(x, y, WALL_SIZE, CELL_SIZE, GRAY);
}


void drawMaze(void){
    for(int i = 0; i<ROWS ; i++){

        for (int j = 0; j < COLS; j++)
        {
            Color color = maze[i][j]==0? BLACK:WHITE;
            DrawRectangle(j*CELL_SIZE , i*CELL_SIZE, CELL_SIZE , CELL_SIZE ,color );
DrawRectangleLinesEx(
                (Rectangle){
                    j * CELL_SIZE,
                    i * CELL_SIZE,
                    CELL_SIZE,
                    CELL_SIZE
                },
                10,
                LIGHTGRAY
            );
            }
        
    }
}