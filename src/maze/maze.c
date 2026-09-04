#include "maze.h"
#include <raylib.h>

static Cell grid[ROWS][COLS] ;

// التعديل: رسم الحيطان كخطوط بيضاء رقيقة (Lines) بسُمك 2px بدلاً من مستطيلات 10px
// هذا التعديل يقضي على مشكل الفراغ (10px gap) ويجعل المتاهة متصلة ومطابقة لفيديوهات الـ Maze Generation
void drawCell(Cell cell, int x, int y)
{
    // التعديل: زيادة سُمك الحيط إلى 4.0f باش يولي باين مليح وواضح في الشاشة
    float thickness = 4.0f; // سُمك الخط الأبيض للحيطان

    // رسم الحيط العلوي: خط أفقي من (x, y) إلى (x + CELL_SIZE, y)
    if (cell.top)
        DrawLineEx((Vector2){(float)x, (float)y}, (Vector2){(float)(x + CELL_SIZE), (float)y}, thickness, WHITE);

    // رسم الحيط الأيمن: خط عمودي من (x + CELL_SIZE, y) إلى (x + CELL_SIZE, y + CELL_SIZE)
    if (cell.right)
        DrawLineEx((Vector2){(float)(x + CELL_SIZE), (float)y}, (Vector2){(float)(x + CELL_SIZE), (float)(y + CELL_SIZE)}, thickness, WHITE);

    // رسم الحيط السفلي: خط أفقي من (x, y + CELL_SIZE) إلى (x + CELL_SIZE, y + CELL_SIZE)
    if (cell.bottom)
        DrawLineEx((Vector2){(float)x, (float)(y + CELL_SIZE)}, (Vector2){(float)(x + CELL_SIZE), (float)(y + CELL_SIZE)}, thickness, WHITE);

    // رسم الحيط الأيسر: خط عمودي من (x, y) إلى (x, y + CELL_SIZE)
    if (cell.left)
        DrawLineEx((Vector2){(float)x, (float)y}, (Vector2){(float)x, (float)(y + CELL_SIZE)}, thickness, WHITE);
}

// التعديل: حساب إحداثيات كل خلية مباشرة بـ (col * CELL_SIZE) و (row * CELL_SIZE)
// بدون إنقاص WALL_SIZE لأن الحيطان أصبحت خطوطاً رقيقة ولا تؤثر على أبعاد الشبكة
void drawMaze(void){
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int posX = col * CELL_SIZE;
            int posY = row * CELL_SIZE;
            drawCell(grid[row][col], posX, posY);
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
