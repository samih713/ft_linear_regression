#include "ft_linear_regression.h"

bool load_data(RenderTexture2D *canvas)
{
    static point_t points[MAX_POINTS];
    size_t n_points = 0;
    // set csv config
    config_t c = {.n_cols = 2, .e_size = sizeof(point_t), .del = ',', .first_row = true};
    // get csv path
    const char *CSVPath = tinyfd_openFileDialog("CSV file", ".", 0, NULL, NULL, 0);
    if (!CSVPath)
        return false;
    FILE *f = load_csv(CSVPath);
    n_points = read_csv(f, c, points, MAX_POINTS, load_points);
    // draw the points
    if (n_points)
    {
        BeginTextureMode(*canvas);
        ClearBackground(BLACK);
        DrawPoints(points, n_points);
        EndTextureMode();
        return true;
    }
    return false;
}