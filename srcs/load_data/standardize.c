#include "ft_linear_regression.h"
#include <float.h>
#include <math.h>

void standardize_points(data_t *data)
{
    static point_t std_points[MAX_POINTS];
    data->std_points = std_points;

    size_t n_points = data->n_points;
    point_t *points = data->points;

    // Compute mean
    float mean_x = 0.f, mean_y = 0.f;
    for (size_t i = 0; i < n_points; ++i)
    {
        mean_x += points[i].x;
        mean_y += points[i].y;
    }
    mean_x /= (float)n_points;
    mean_y /= (float)n_points;

    // Compute (population) stdev
    float var_x = 0.f, var_y = 0.f;
    for (size_t i = 0; i < n_points; ++i)
    {
        float dx = points[i].x - mean_x;
        float dy = points[i].y - mean_y;
        var_x += dx * dx;
        var_y += dy * dy;
    }
    float stdev_x = sqrtf(var_x / (float)n_points);
    float stdev_y = sqrtf(var_y / (float)n_points);
    if (stdev_x == 0.f)
        stdev_x = 1.f;
    if (stdev_y == 0.f)
        stdev_y = 1.f;

    // Standardize and find min / max
    data->min_x = FLT_MAX, data->min_y = FLT_MAX;
    data->max_x = -FLT_MAX, data->max_y = -FLT_MAX;
    for (size_t i = 0; i < n_points; ++i)
    {
        float z_x = (points[i].x - mean_x) / stdev_x;
        float z_y = (points[i].y - mean_y) / stdev_y;
        std_points[i].x = z_x;
        std_points[i].y = z_y;
        if (points[i].x < data->min_x)
            data->min_x = points[i].x;
        if (points[i].y < data->min_y)
            data->min_y = points[i].y;
        if (points[i].x > data->max_x)
            data->max_x = points[i].x;
        if (points[i].y > data->max_y)
            data->max_y = points[i].y;
    }
}