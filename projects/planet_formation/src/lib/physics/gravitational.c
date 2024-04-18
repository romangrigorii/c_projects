#include <stdio.h>
#include <stdlib.h>
#include "consts.h"
#include <math.h>
#include "gravitational.h"

void sim_next(double planet_vec[7][num_planets], double r[num_planets][num_planets], double tao, int n){ // planet_vec contains x,y position, x,y velcoity, x,y acceleration, and mass of the planet
    int i = 0, j = 1;
    double xd, yd;
    // printf("done\n");
    for (i = 0; i<n; i++){
        planet_vec[5][i] = 0.0;
        planet_vec[6][i] = 0.0;
        for (j = 0; j<n; j++){
            if (i!=j){
                xd = planet_vec[0][j]-planet_vec[0][i];
                yd = planet_vec[1][j]-planet_vec[1][i];
                r[i][j] = sqrt(xd*xd + yd*yd);
                planet_vec[4][i] += planet_vec[6][j]*GCONSTANT/(pow(r[i][j],3))*xd;
                planet_vec[5][i] += planet_vec[6][j]*GCONSTANT/(pow(r[i][j],3))*yd;
            }
        }
        planet_vec[2][i] += planet_vec[4][i]*tao;
        planet_vec[3][i] += planet_vec[5][i]*tao;
        planet_vec[0][i] += planet_vec[2][i]*tao;
        planet_vec[1][i] += planet_vec[3][i]*tao;
    }
    // printf("done\n");
}

void planet_combine(double planet_vec[7][num_planets], double r[num_planets][num_planets], int *n){ // if planets are within a critical distance we combine them
    int i = 0, j;
    while(i<*n){
        j = i+1;
        while (j<*n){
            if (j<*n && r[i][j] < (planet_vec[6][i] + planet_vec[6][j])/1000){
                planet_vec[6][i]+=planet_vec[6][j];
                (*n)--;
                planet_vec[0][j] = planet_vec[0][*n];
                planet_vec[1][j] = planet_vec[1][*n];
                planet_vec[2][j] = planet_vec[2][*n];
                planet_vec[3][j] = planet_vec[3][*n];
                planet_vec[4][j] = planet_vec[4][*n];
                planet_vec[5][j] = planet_vec[5][*n];
            }
            j++;
        }
        i++;
    }
}

void printp(double plnet_vec[7][num_planets]){
    for (int i = 0; i<num_planets;i++){
        for (int j = 0; j<num_planets; j++){
            if ((plnet_vec[0][i]/2 + xdim)/100>i && (plnet_vec[0][i]/2 + xdim)<(i+1) && (plnet_vec[1][j]/2 + ydim)>j && (plnet_vec[1][j]/2 + ydim)<(j+1)){
                printf(".");
            } else {
                printf(" ");
            }
        }
    }
}
