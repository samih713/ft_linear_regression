#define LOAD_CSV_H_IMPLEMENTATION

#include "ft_linear_regression.h"

void run_lr(point_t *points)
{
    printf("RUNNING LINEAR REGRESSION ..\n");

    FILE *log = fopen("log.txt", "w");
    for (size_t i = 0; i < n_points; ++i)
    {
        fprintf(log, "[%f-%f]\n", points[i].milage, points[i].price);
        fprintf(stdout, "[%f-%f]\n", points[i].milage, points[i].price);
    }
}

int main()
{
#if defined(__MAC__)
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
#endif
    InitWindow(WINDOW_W, WINDOW_H, TITLE);

    point_t *points;

    RenderTexture2D canvas = LoadRenderTexture(WINDOW_W, WINDOW_H);
    BeginTextureMode(canvas);
    ClearBackground(BLACK);
    EndTextureMode();
    bool canvas_ready = false;

    while (!WindowShouldClose())
    {
        
        switch (action)
        {
        case MENU_LOAD_CSV:
            points = load_data();
            if (points)
                canvas_ready = false;
            action = MENU_NONE;
            break;
        case MENU_RUN_LR:
            BeginTextureMode(canvas);
            ClearBackground(BLACK);
            DrawAxis();
            DrawMenu();
            if (points)
                DrawPoints(points);
            EndTextureMode();
            canvas_ready = true;
            action = MENU_NONE;
            break;
        default:
            break;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        if (!canvas_ready)
        {
            DrawAxis();
            DrawMenu();
        }
        else
        {
            DrawTextureRec(canvas.texture, (Rectangle){0, 0, (float)canvas.texture.width, (float)-canvas.texture.height}, (Vector2){0, 0}, WHITE);
            DrawAxis();
            DrawMenu();
        }
        EndDrawing();
    }
    UnloadRenderTexture(canvas);
    CloseWindow();
    return 0;
}