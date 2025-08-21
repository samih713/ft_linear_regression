#include "ft_linear_regression.h"

void DrawMenu(Button_e *function)
{
    // load csv button
    Rectangle LoadCSV = {
        .x = BUTTON_X,
        .y = WINDOW_H * 0.03,
        .width = BUTTON_SIZE.x,
        .height = BUTTON_SIZE.y};
    DrawButton("Load CSV", LoadCSV);
    // 
    if (CheckCollisionPointRec(GetMousePosition(), LoadCSV) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        *function = LOADCSV;
    }
}