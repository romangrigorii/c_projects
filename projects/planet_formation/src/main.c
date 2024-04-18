#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "lib/numeric/randgen.h"
#include "lib/physics/consts.h"
#include "lib/physics/gravitational.h"

int main(){
    double r[num_planets][num_planets];
    double planets[7][num_planets];
    int n = num_planets;
    rand_vec(planets[0],-xdim,xdim,num_planets,101);
    rand_vec(planets[1],-ydim,ydim,num_planets,102); 
    zeros(planets[2],num_planets);
    zeros(planets[3],num_planets);
    zeros(planets[4],num_planets);
    zeros(planets[5],num_planets);
    rand_vec(planets[6],mass_small,mass_large,num_planets,103);
    while (1){
        sim_next(planets, r, 100, n);
        planet_combine(planets, r, &n);
        printp(planets);
    }
    return 0;
}