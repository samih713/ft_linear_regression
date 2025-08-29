#include "ft_linear_regression.h"


void DrawButton(const char *text, Rectangle Button)
{
    static const int FontSize = 25;

    DrawRectangleRec(Button, BUTTON_COLOR);
    DrawRectangleLinesEx(Button, 3, DARKGRAY);
    // Measure text
    int TextW = MeasureText(text, FontSize);
    int TextH = FontSize;
    // get centered position
    float textX = Button.x + (Button.width - TextW) / 2.0f;
    float textY = Button.y + (Button.height - TextH) / 2.0f;
    // Draw it
    DrawText(text, textX, textY, FontSize, DARKGRAY);
}
