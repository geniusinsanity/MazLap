// The main function of this MazLap
#include <raylib.h>

// local liberaries
#include "maze/maze.h"



int main(void)
{


    // التعديل: موقع اللاعب الأولي في بداية المتاهة (0, 0)
    float playerX = 0;
    float playerY = 0;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(800, 600, "MazLap");
    SetTargetFPS(60);
    
    mazInit(); 
    generateMaze(0,0);
    while (!WindowShouldClose())
    {
        // التعديل: حركة اللاعب أصبحت تقفز بالضبط بقيمة CELL_SIZE (40px) بدون أي خلل في المحاذاة
        if (IsKeyPressed(KEY_LEFT))
            playerX -= CELL_SIZE;
        if (IsKeyPressed(KEY_RIGHT))
            playerX += CELL_SIZE;
        if (IsKeyPressed(KEY_UP))
            playerY -= CELL_SIZE;
        if (IsKeyPressed(KEY_DOWN))
            playerY += CELL_SIZE;

        // حدود الشاشة
        if (playerX > (GetScreenWidth() - CELL_SIZE))
            playerX = GetScreenWidth() - CELL_SIZE;
        if (playerX < 0)
            playerX = 0;
        if (playerY > (GetScreenHeight() - CELL_SIZE))
            playerY = GetScreenHeight() - CELL_SIZE;
        if (playerY < 0)
            playerY = 0;

        BeginDrawing();
        
        ClearBackground(BLACK);
        
        // التعديل: رسم اللاعب بحجم الخلية كاملاً (CELL_SIZE x CELL_SIZE) بدون أي هامش للتخلص نهائياً من الفراغ (0px Gap)
        // نلاحظ رسم اللاعب قبل المتاهة لكي تترسم الخطوط البيضاء للحيطان فوقه وتظهر الحدود واضحة
        DrawRectangle((int)playerX, (int)playerY, CELL_SIZE, CELL_SIZE, BLUE);

        // رسم حيطان المتاهة فوق اللاعب
        drawMaze();

        EndDrawing();

    }
    CloseWindow();

    return 0;
}