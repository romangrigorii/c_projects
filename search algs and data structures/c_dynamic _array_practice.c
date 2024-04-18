#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// we pass a pointer to array in order to modify it
int * add_to_arr(int ** arr, int element, int * size){
    int * a = (int*) malloc((1+*size)*sizeof(int));
    memcpy(a, *arr, *size * sizeof(int));
    *(a + *size) = element;
    free(*arr);
    ++*size;
    *arr = a;
}

int main(void ){
    int size = 0;
    int * arr = NULL;
    int * ptr = arr;
    for (int ii = 0; ii < 10; ii++){
        add_to_arr(&ptr, ii, &size);
    }
    for (int jj = 0; jj<size; jj++){
        printf("%d ", *(ptr + jj));
    }
    printf("\n");
    free(ptr);
    return 0;
}