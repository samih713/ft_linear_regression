#include "ft_linear_regression.h"

void DrawPlotArea()
{
    Rectangle PlotArea = {
        .x = WINDOW_W * 0.02,
        .y = WINDOW_H * 0.02,
        .width = WINDOW_W * 0.70,
        .height = WINDOW_H * 0.95,
    };
    DrawRectangleRec(PlotArea, Fade(BLACK, 0.8));
}