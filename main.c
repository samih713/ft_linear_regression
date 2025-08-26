#define LOAD_CSV_H_IMPLEMENTATION

#include "ft_linear_regression.h"
#include <dlfcn.h>

typedef int (*f_ptr)(int, int);

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

void recompile()
{
    static const char *compile = "cc -c -fPIC add.c && cc -shared add.o -o libdyn.so";
    system(compile);
}

void *get_symbol(const char *shared_path, const char *sym)
{
    static void *handle;
    if (handle)
    {
        dlclose(handle);
        handle = NULL;
    }
    recompile();
    // handle = dlmopen(LM_ID_NEWLM, shared_path, RTLD_NOW);
    handle = dlopen(shared_path, RTLD_NOW);
    if (!handle)
    {
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    return dlsym(handle, sym);
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
        DrawMenu(&action);
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