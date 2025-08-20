#include "ft_linear_regression.h"

void DrawButton(const char *text, Vector2 pos, Vector2 size)
{
    static const int FontSize = 25;

    Rectangle Button = {
        .x = pos.x,
        .y = pos.y,
        .width = size.x,
        .height = size.y};
    DrawRectangleRec(Button, BUTTON_COLOR);
    DrawRectangleLinesEx(Button, 3, BLACK);
    // Measure text
    int TextW = MeasureText(text, FontSize);
    int TextH = FontSize;
    // get centered position
    float textX = pos.x + (size.x - TextW) / 2.0f;
    float textY = pos.y + (size.y - TextH) / 2.0f;
    // Draw it
    DrawText(text, textX, textY, FontSize, WHITE);
}
