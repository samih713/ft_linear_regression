#include "ft_linear_regression.h"

void plot(data_t t)
{
    for (size_t i = 0; i < t.n_points; ++i)
    {
        Vector2 p = data_to_window(t, t.points[i]);
        DrawCircle(p.x, p.y, POINT_SIZE, POINT_COLOR);
    }
}