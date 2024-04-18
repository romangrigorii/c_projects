#include <stdio.h>
#include <stdlib.h>

/* This code demonstrates the use of function pointers */

int sum(int vals[], int num){
    int out = vals[0], q = 1;
    for (;q<num;q++, out+=*++vals){}
    return out;
}

int mul(int vals[], int num){
    int out = vals[0], q=1;
    for (;q<num;q++, out*=(*++vals)){}
    return out;
}

int arithfunc (int f(), int vals[], int num){
    return f(vals, num);
}

int main(){
    int vals[] = {1,2,3,4,5};
    printf("%d\n", arithfunc(&mul, vals,5));
}
