#include "ft_linear_regression.h"

void DrawMenu()
{
    // load csv button
    Vector2 LCSVPosition = {.x = BUTTON_X,
                            .y = WINDOW_H * 0.03};
    DrawButton("Load CSV", LCSVPosition, BUTTON_SIZE);
}