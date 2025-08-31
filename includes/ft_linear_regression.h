#ifndef FT_LINEAR_REGRESSION
#define FT_LINEAR_REGRESSION

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h> // -- remove
#include <assert.h>
#include <float.h>
#include <math.h>

#include "raylib.h"
#include "tinyfiledialogs.h"
#include "load_csv.h"
#include "matrix.h"

#define TODO(thing) (assert(false && (thing)))

typedef enum
{
    MENU_NONE = -1,
    MENU_LOAD_CSV,
    MENU_RUN_LR
} MENU_ACTION;
// initial state
extern MENU_ACTION action;

typedef struct
{
    float x;
    float y;
} point_t;

typedef struct
{
    point_t *points;
    point_t *std_points;
    float min_x, max_x;
    float min_y, max_y;
    size_t n_points;
} data_t;

typedef struct
{
    float sx, sy; // scales
    float ox, oy; // offset
} xform_t;

/* -------------------------------------------------------------------------- */
/*                                  CONSTANTS                                 */
/* -------------------------------------------------------------------------- */
/* ----------------------------------- UI ----------------------------------- */
#define TITLE "ft_linear_regression"
/* --------------------------------- WINDOW --------------------------------- */
#define WINDOW_W 800
#define WINDOW_H 600
/* --------------------------------- BUTTON --------------------------------- */
#define BUTTON_COLOR (Fade(WHITE, 0.5))
#define BUTTON_X (WINDOW_W * 0.75)
#define BUTTON_SIZE ((Vector2){.x = WINDOW_W * .23, .y = WINDOW_H * .08})
#define BUTTON_H_GAP (WINDOW_H * 0.03)
/* ---------------------------------- PLOT ---------------------------------- */
#define PAD 40.0f
#define POINT_COLOR (Fade(RED, 0.9))
#define POINT_SIZE 4
/* -------------------------------- LOAD DATA ------------------------------- */
#define MAX_POINTS 256
/* -------------------------------------------------------------------------- */
/*                                    MENU                                    */
/* -------------------------------------------------------------------------- */
void DrawMenu();
/* --------------------------------- BUTTON --------------------------------- */
void DrawButton(const char *tex, Rectangle button);
/* -------------------------------------------------------------------------- */
/*                                    PLOT                                    */
/* -------------------------------------------------------------------------- */
void plot(data_t t);
void draw_axis(data_t t);
/* ------------------------------- PLOT UTILS ------------------------------- */
float clamp(float value, float min, float max);
Vector2 data_to_window(data_t t, point_t p);
/* --------------------------- LINEAR REGRESSSION --------------------------- */
void standardize_points(data_t *data);
/* -------------------------------------------------------------------------- */
/*                                  LOAD DATA                                 */
/* -------------------------------------------------------------------------- */
bool load_data(data_t *data);
void load_points(char **values, void *points);

#endif // FT_LINEAR_REGRESSION