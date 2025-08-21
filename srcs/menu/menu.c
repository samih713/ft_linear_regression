#include "ft_linear_regression.h"

MENU_ACTION action = MENU_NONE;

void DrawMenu()
{
    // load csv button
    Rectangle LoadCSV = {
        .x = BUTTON_X,
        .y = WINDOW_H * 0.03,
        .width = BUTTON_SIZE.x,
        .height = BUTTON_SIZE.y};
    DrawButton("Load CSV", LoadCSV);

    // load run lr button
    Rectangle RunLR = {
        .x = BUTTON_X,
        .y = WINDOW_H * 0.03 + BUTTON_SIZE.y + BUTTON_H_GAP,
        .width = BUTTON_SIZE.x,
        .height = BUTTON_SIZE.y};
    DrawButton("Run LR", RunLR);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (CheckCollisionPointRec(GetMousePosition(), LoadCSV))
            action = MENU_LOAD_CSV;
        else if (CheckCollisionPointRec(GetMousePosition(), RunLR))
            action = MENU_RUN_LR;
    }
}