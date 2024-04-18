#ifndef GRAVITATIONAL
#define GRAVITATIONAL
#include "consts.h"
void sim_next(double planet_vec[7][num_planets], double r[num_planets][num_planets], double tao, int n);
void planet_combine(double planet_vec[7][num_planets], double r[num_planets][num_planets], int * n);
void printp(double planet_vec[7][num_planets]);

#endif