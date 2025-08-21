#define LOAD_CSV_H_IMPLEMENTATION
#include "load_csv.h"
#include "ft_linear_regression.h"
#include <fcntl.h>

typedef struct point_s {
    float milage;
    float price;
} point_t;

void load_points(char **values, void *points) {
   point_t *p = (point_t *)points;
   p->milage = atof(values[0]);
   p->price = atof(values[1]);
}

void load_data(const char *data_path) {
    point_t points[30];
    config_t c = {.n_cols=2, .e_size=sizeof(point_t), .del=',', .first_row=true};
    FILE *f = load_csv(data_path);
    // FILE *log = fopen("sanity_check.txt", "w");
    size_t n = read_csv(f, c, points, 30, load_points);
    for (size_t i = 0; i < n; ++i) {
        // fprintf(log,"[%f, %f]\n", points[i].milage, points[i].price);
        printf("[%.2f, %.2f]\n", points[i].milage, points[i].price);
    }
}

int main()
{
// start window
#if defined(__MAC__)
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
#endif
    InitWindow(WINDOW_W, WINDOW_H, TITLE);

    SetTargetFPS(20);

    Button_e function = -1;
    char *csv_path;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawPlotArea();
        DrawMenu(&function);
        switch (function)
        {
        case LOADCSV:
            csv_path = tinyfd_openFileDialog(
                "CSV file",
                ".",
                0,
                NULL,
                NULL,
                0);
            load_data(csv_path);
            break;
        default:
            break;
        }
        function = NOSTATE;
        EndDrawing();
    }

    // close window
    CloseWindow();
    return 0;
}