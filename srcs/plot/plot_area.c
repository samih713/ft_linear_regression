#include "ft_linear_regression.h"
#include <math.h>
#include <float.h>

#define X 0
#define Y 1

void DrawAxis()
{
    // x axis
    float y = WINDOW_H * 0.9;
    Vector2 x_start = {0, y};
    Vector2 x_end = {WINDOW_W, y};
    DrawLineEx(x_start, x_end, 2, RED);
    // y axis
    float x = WINDOW_W * 0.1;
    Vector2 y_start = {x, 0};
    Vector2 y_end = {x, WINDOW_H};
    DrawLineEx(y_start, y_end, 2, RED);
}

void DrawPoint(point_t p)
{
    DrawCircle(p.milage, p.price, 3, RED);
}

void standardize_points(point_t *points)
{
    // Compute mean
    float mean_x = 0.f, mean_y = 0.f;
    for (size_t i = 0; i < n_points; ++i)
    {
        mean_x += points[i].milage;
        mean_y += points[i].price;
    }
    mean_x /= (float)n_points;
    mean_y /= (float)n_points;

    // Compute (population) stdev
    float var_x = 0.f, var_y = 0.f;
    for (size_t i = 0; i < n_points; ++i)
    {
        float dx = points[i].milage - mean_x;
        float dy = points[i].price - mean_y;
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
    float min_x = FLT_MAX, min_y = FLT_MAX;
    float max_x = -FLT_MAX, max_y = -FLT_MAX;
    for (size_t i = 0; i < n_points; ++i)
    {
        float z_x = (points[i].milage - mean_x) / stdev_x;
        float z_y = (points[i].price - mean_y) / stdev_y;
        points[i].milage = z_x;
        points[i].price = z_y;
        if (z_x < min_x)
            min_x = z_x;
        if (z_y < min_y)
            min_y = z_y;
        if (z_x > max_x)
            max_x = z_x;
        if (z_y > max_y)
            max_y = z_y;
    }

    // Shift to make all values non-negative
    float shift_x = (min_x < 0.f) ? -min_x : 0.f;
    float shift_y = (min_y < 0.f) ? -min_y : 0.f;
    for (size_t i = 0; i < n_points; ++i)
    {
        points[i].milage += shift_x;
        points[i].price += shift_y;
    }

    float range_x = (max_x + shift_x);
    float range_y = (max_y + shift_y);
    if (range_x == 0.f)
        range_x = 1.f;
    if (range_y == 0.f)
        range_y = 1.f;

    float usable_w = WINDOW_W * 0.8f;
    float usable_h = WINDOW_H * 0.8f;

    for (size_t i = 0; i < n_points; ++i)
    {
        points[i].milage = WINDOW_W * 0.1f + (points[i].milage / range_x) * usable_w;
        // Invert Y since the screen Y axis grows downward
        float normY = points[i].price / range_y;
        points[i].price = WINDOW_H * 0.9f - normY * usable_h;
    }
}

void DrawPoints(point_t *points)
{
    standardize_points(points);
    for (size_t i = 0; i < n_points; ++i)
    {
        DrawPoint(points[i]);
    }
}
