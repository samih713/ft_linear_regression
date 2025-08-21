#include "ft_linear_regression.h"

size_t n_points = MAX_POINTS;
point_t *load_data()
{
    static point_t points[MAX_POINTS];

    // set csv config
    config_t c = {
        .n_cols = 2,
        .e_size = sizeof(point_t),
        .del = ',',
        .first_row = true};

    // get csv path
    const char *CSVPath = tinyfd_openFileDialog(
        "CSV file",
        ".",
        0,
        NULL,
        NULL,
        0);

    FILE *f = load_csv(CSVPath);
    n_points = read_csv(f, c, points, MAX_POINTS, load_points);
    return (points);
}