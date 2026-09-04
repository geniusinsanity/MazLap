#include "maze.h"
#include <raylib.h>

static Cell grid[ROWS][COLS] ;

int posX,posY,i,j;

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
    for(i = 0; i<ROWS ; i++){

        for (j = 0; j < COLS; j++)
        {
            posX = j*(CELL_SIZE - WALL_SIZE);
            posY = i *(CELL_SIZE -WALL_SIZE);
            drawCell(grid[i][j],posX,posY);
        }
    }
}

void mazInit(void){

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            grid[r][c] = (Cell){1 ,1 ,1 ,1};
        }
        
    }
    
}