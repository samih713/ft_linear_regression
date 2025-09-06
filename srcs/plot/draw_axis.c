#include "ft_linear_regression.h"

void draw_axis(Camera2D camera)
{
    float lt = 3.0f * (1/camera.zoom);
    Color lc = BLUE;

    Vector2 x_axis_start = {
        .x = PAD,
        .y = WINDOW_H - PAD};
    Vector2 x_axis_end = {
        .x = WINDOW_W - PAD,
        .y = WINDOW_H - PAD};

    Vector2 y_axis_start = {
        .x = PAD,
        .y = PAD};
    Vector2 y_axis_end = {
        .x = PAD,
        .y = WINDOW_H - PAD};

    x_axis_start = GetScreenToWorld2D(x_axis_start, camera);
    x_axis_end = GetScreenToWorld2D(x_axis_end, camera);
    y_axis_start = GetScreenToWorld2D(y_axis_start, camera);
    y_axis_end = GetScreenToWorld2D(y_axis_end, camera);

    DrawLineEx(y_axis_start, y_axis_end, lt, lc);
    DrawLineEx(x_axis_start, x_axis_end, lt, lc);
}
// void draw_axis(data_t t)
// {
//     float lt = 2.0f;
//     Color lc = BLUE;

//     Vector2 x_axis_start = data_to_window(t, (point_t){
//                                                  .x = t.min_x - t.max_x,
//                                                  .y = 0.0f});
//     Vector2 x_axis_end = data_to_window(t, (point_t){
//                                                .x = t.max_x + t.max_x,
//                                                .y = 0.0f});

//     Vector2 y_axis_start = data_to_window(t, (point_t){
//                                                  .x = 0,
//                                                  .y = t.min_y - t.max_y});
//     Vector2 y_axis_end = data_to_window(t, (point_t){
//                                                .x = 0,
//                                                .y = t.max_y * 2});

//     DrawLineEx(x_axis_start, x_axis_end, lt, lc);
//     DrawLineEx(y_axis_start, y_axis_end, lt, lc);
// }