#include "ft_linear_regression.h"

// this function maps data space to plot space
static matrix_t data_to_window_matrix(data_t t)
{
    const float range_x = t.max_x - t.min_x;
    const float range_y = t.max_y - t.min_y;
    // find the scaling
    float sx = WINDOW_W / range_x;
    float sy = WINDOW_H / range_y;
    // create the matrix and set it
    /*
    [
        sx     0      -sx*min_x
        0      -sy    H + sy*min_y
        0      0      1
    ]
    */
    matrix_t transform = matrix(3, 3);
    MAT_AT(transform, 0, 0) = sx;
    MAT_AT(transform, 0, 2) = -sx * t.min_x + PAD;
    MAT_AT(transform, 1, 1) = -sy;                       // flip the y
    MAT_AT(transform, 1, 2) = (WINDOW_H - PAD) + sy * t.min_y; // to shift back into window
    MAT_AT(transform, 2, 2) = 1;
    return transform;
}

Vector2 data_to_window(data_t t, point_t p)
{
    static matrix_t *transform = NULL;
    if (!transform)
    {
        transform = malloc(sizeof(matrix_t));
        *transform = data_to_window_matrix(t);
    }
    // 
    matrix_t dp = matrix(3, 1);
    MAT_AT(dp, 0, 0) = p.x;
    MAT_AT(dp, 0, 1) = p.y;
    MAT_AT(dp, 0, 2) = 1;

    matrix_t r = multiply(*transform, dp);
    Vector2 wp = {
        .x = MAT_AT(r, 0, 0),
        .y = MAT_AT(r, 0, 1),
    };
    // free matrices
    free_matrix(&dp);
    free_matrix(&r);
    return wp;
}