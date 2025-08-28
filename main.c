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
    SetTargetFPS(20);

    Camera2D camera = {0};
    camera.target = (Vector2){0,0};
    camera.zoom = 1;

    point_t *points;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(DARKGRAY);
        DrawPlotArea();
        DrawMenu();
        switch (action)
        {
        case MENU_LOAD_CSV:
            points = load_data();
            action = MENU_NONE;
            break;
        case MENU_RUN_LR:
            run_lr(points);
            action = MENU_NONE;
            break;
        default:
            break;
        }

        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}