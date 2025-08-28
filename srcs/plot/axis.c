#include "ft_linear_regression.h"

void DrawAxis()
{
    const Color axis_color = Fade(RED, 0.3);
    static const int R = 400;
    // x-axis
    Vector2 x_begin = {-R, 0};
    Vector2 x_end = {R, 0};
    DrawLineEx(
        x_begin,
        x_end, 2, axis_color);
    // y-axis
    Vector2 y_begin = {0, -R};
    Vector2 y_end = {0, R};
    DrawLineEx(
        y_begin,
        y_end, 2, axis_color);
}
