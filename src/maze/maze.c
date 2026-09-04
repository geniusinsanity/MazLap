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
            grid[r][c] = (Cell){1 ,1 ,1 ,1, 0};
        }
        
    }
    
}

void generateMaze(int row ,int col){
    grid[row][col].visited=1;

    int dirs[4]={0,1,2,3};

    for (int i=0; i<4; i++){
        int randIdx = GetRandomValue(0,3);
        int temp = dirs[i];
        dirs[i]=dirs[randIdx];
        dirs[randIdx]=temp;

    }

    for (int i = 0; i < 4; i++)
    {
        int nextRow =row;
        int nextCol=col;

        if (dirs[i]==0) nextRow--;else if (dirs[i]==1) nextCol++;else if (dirs[i]==2) nextRow++;else if (dirs[i]==3) nextCol--;
    
    
    if(nextRow >= 0 && nextRow <ROWS && nextCol >= 0 && nextCol < COLS && !grid[nextRow][nextCol].visited){
        if (dirs[i]==0) {
            grid[row][col].top=0;
            grid[nextRow][nextCol].bottom=0;

        }else if(dirs[i]==1){
            grid[row][col].right=0;
            grid[nextRow][nextCol].left=0;
            
        }else if(dirs[i]==2){
            grid[row][col].bottom=0;
            grid[nextRow][nextCol].top=0;

        }else if(dirs[i]==3){
            grid[row][col].left=0;
            grid[nextRow][nextCol].right=0;

        }
        generateMaze(nextRow,nextCol);
    }
}
}
