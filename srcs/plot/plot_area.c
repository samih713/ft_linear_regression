#include "ft_linear_regression.h"

#define POINT_COLOR (Fade(RED, 0.9))
#define POINT_SIZE 4

static void DrawPoint(point_t p)
{
    DrawCircle(p.milage, p.price, POINT_SIZE, POINT_COLOR);
}

void DrawPoints(point_t *points, size_t n_points)
{
    standardize_points(points, n_points);
    for (size_t i = 0; i < n_points; ++i)
    {
        DrawPoint(points[i]);
    }
}
