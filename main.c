#define LOAD_CSV_H_IMPLEMENTATION

#include "ft_linear_regression.h"

void run_lr()
{
    printf("RUNNING LINEAR REGRESSION ..\n");
}

int main()
{
    // set up data
    data_t data;
    bool data_ready = false;

#if defined(__MAC__)
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
#endif

    InitWindow(WINDOW_W, WINDOW_H, TITLE);
    SetTargetFPS(10);
    // to initially clear the window
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
    

    Camera2D camera = {0};
    camera.target = (Vector2){WINDOW_W / 2, WINDOW_H / 2};
    camera.offset = (Vector2){WINDOW_W / 2, WINDOW_H / 2};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        // panning
        if (IsKeyDown(KEY_RIGHT))
            camera.target.x += 2;
        if (IsKeyDown(KEY_LEFT))
            camera.target.x -= 2;
        if (IsKeyDown(KEY_UP))
            camera.target.y -= 2;
        if (IsKeyDown(KEY_DOWN))
            camera.target.y += 2;
        // zooming
        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        float scale = 0.2f * wheel;
        if (wheel != 0)
        {
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
            camera.offset = GetMousePosition();
            camera.target = mouseWorldPos;
            camera.zoom = clamp(expf(logf(camera.zoom) + scale), 0.125f, 64.0f);
        }
        // reset
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.target = (Vector2){WINDOW_W / 2, WINDOW_H / 2};
            camera.offset = (Vector2){WINDOW_W / 2, WINDOW_H / 2};
            camera.rotation = 0.0f;
        }

        // menu
        switch (action)
        {
        case MENU_LOAD_CSV:
            if (load_data(&data))
                data_ready = true;
            action = MENU_NONE;
            break;
        case MENU_RUN_LR:
            action = MENU_NONE;
            break;
        default:
            break;
        }

        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);

        if (data_ready)
            plot(data);

        draw_axis(camera);
        EndMode2D();
        DrawMenu();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}