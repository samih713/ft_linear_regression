#include "ft_linear_regression.h"





int main()
{
    // start window
    InitWindow(WINDOW_W, WINDOW_H, TITLE);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawPlotArea();
        DrawMenu();
        EndDrawing();
    }

    // close window
    CloseWindow();
    return 0;
}