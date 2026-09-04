#ifndef MAZE_H
#define MAZE_H

//define colloms and rows of the map

#define COLS 7
#define ROWS 7
// التعديل: حجم كل خلية في المتاهة
// تم حذف WALL_SIZE نهائياً لأن الحيطان أصبحت خطوطاً رقيقة لا تأخذ مساحة
#define CELL_SIZE 40


typedef struct
{
    int top;
    int right;
    int bottom;
    int left;
    int visited;
} Cell;

void drawMaze(void);
void drawCell(Cell cell, int x, int y);
void mazInit(void);
void generateMaze(int row, int col);
#endif