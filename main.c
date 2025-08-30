#define LOAD_CSV_H_IMPLEMENTATION

#include "ft_linear_regression.h"

void run_lr()
{
    printf("RUNNING LINEAR REGRESSION ..\n");
}

int main()
{
#if defined(__MAC__)
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
#endif
    InitWindow(WINDOW_W, WINDOW_H, TITLE);

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
            if (load_data(&canvas))
                canvas_ready = true;
            action = MENU_NONE;
            break;
        case MENU_RUN_LR:
            action = MENU_NONE;
            break;
        default:
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if (canvas_ready)
        {
            DrawTextureRec(canvas.texture, (Rectangle){0, 0, (float)canvas.texture.width, (float)-canvas.texture.height}, (Vector2){0, 0}, WHITE);
            DrawAxis();
            DrawMenu();
        }
        else
        {
            DrawAxis();
            DrawMenu();
        }
        EndDrawing();
    }
    UnloadRenderTexture(canvas);
    CloseWindow();
    return 0;
}