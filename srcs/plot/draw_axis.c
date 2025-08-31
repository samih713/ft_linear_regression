#include "ft_linear_regression.h"

void draw_axis(data_t t)
{
    float lt = 2.0f;
    Color lc = BLUE;

    Vector2 x_axis_start = data_to_window(t, (point_t){
                                                 .x = t.min_x,
                                                 .y = 0.0f});
    Vector2 x_axis_end = data_to_window(t, (point_t){
                                               .x = t.max_x,
                                               .y = 0.0f});

    // Vector2 x_axis_start = {.x=-WINDOW_W, 0};
    // Vector2 x_axis_end = {.x=WINDOW_W, 0};

    Vector2 y_axis_start = data_to_window(t, (point_t){
                                                 .x = 0,
                                                 .y = t.min_y});
    Vector2 y_axis_end = data_to_window(t, (point_t){
                                               .x = 0,
                                               .y = t.max_y});

    DrawLineEx(x_axis_start, x_axis_end, lt, lc);
    DrawLineEx(y_axis_start, y_axis_end, lt, lc);
}