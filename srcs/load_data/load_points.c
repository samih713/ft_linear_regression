#include "ft_linear_regression.h"

void load_points(char **values, void *point) {
   point_t *p = (point_t *)point;
   p->x = atof(values[0]);
   p->y = atof(values[1]);
}