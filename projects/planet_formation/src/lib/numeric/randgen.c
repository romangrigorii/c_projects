#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randgen.h"
#include <errno.h>

void rand_vec(double v[], double st, double en, int n, int seed){
    srand(seed);
    if (en<=st){
        perror("st must be < en ");
        exit(1);
    }
    for (int i = 0; i<n; i++){
        v[i] = ((double) rand())/RAND_MAX*(en-st) + st;
    }
}

void zeros(double v[], int n){
    for (int i = 0; i<n; i++){
        *(v+i)= 0.0;
    }
}
