#include "ft_linear_regression.h"

int main()
{
    // start window
    InitWindow(WINDOW_W, WINDOW_H, TITLE);

    SetTargetFPS(60);
    const char *csv_path = tinyfd_openFileDialog(
        "CSV file",
        ".",
        0,
        NULL,
        NULL,
        0
    );
    printf("%s\n", csv_path);
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