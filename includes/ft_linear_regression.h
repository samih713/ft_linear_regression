#ifndef FT_LINEAR_REGRESSION
#define FT_LINEAR_REGRESSION

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h> // -- remove
#include <assert.h>
#include "raylib.h"
#include "tinyfiledialogs.h"
#include "load_csv.h"

#define TODO(thing) (assert(false && (thing)))

typedef enum
{
    MENU_NONE = -1,
    MENU_LOAD_CSV,
    MENU_RUN_LR
} MENU_ACTION;
// initial state
extern MENU_ACTION action;

typedef struct point_s
{
    float milage;
    float price;
} point_t;

extern size_t n_points;

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
void DrawAxis();
void DrawPoints(point_t *points, size_t n_points);
void standardize_points(point_t *points, size_t n_points);
/* -------------------------------------------------------------------------- */
/*                                  LOAD DATA                                 */
/* -------------------------------------------------------------------------- */
bool load_data(RenderTexture2D *canvas);
void load_points(char **values, void *points);

#endif // FT_LINEAR_REGRESSION