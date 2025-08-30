#include "ft_linear_regression.h"

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