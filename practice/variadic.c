#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>

/* This code deonstrates the use of variadic functionality */

int add_impl(int ignore,...){
    int out = 0;
    va_list args;
    va_start(args,ignore);
    int q = va_arg(args, int);
    for (;q != 0; q = va_arg(args, int)){
        out += q;
    }
    return out;
}

#define ADD(...) add_impl(0,__VA_ARGS__)

int main(){
    printf("%d\n", ADD(5,3,6,3,6,8,0));
    return 0;
}