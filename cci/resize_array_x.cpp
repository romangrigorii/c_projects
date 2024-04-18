#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int addItem(int **arr, int newElement, int *count, int *bufSize)
{
  if (*count == *bufSize)
  {
     // we've run out of room; extend the buffer
    realloc(*arr, 2 * *bufSize * sizeof *arr);
    int *tmp = &(*arr)[0];
    *arr = tmp;
    *bufSize *= 2;
  }
  (*arr)[(*count)++] = newElement;
}


int main(){
    int arr[] = {1,2,3,4,5};
    int bsize = 5;
    int * ptr = &arr[0];
    int curpos = 5;
    addItem(&ptr, 6, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    addItem(&ptr, 7, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    addItem(&ptr, 8, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    addItem(&ptr, 9, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    addItem(&ptr, 10, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    addItem(&ptr, 11, &curpos, &bsize);
    printf("%d %d\n", curpos, bsize);
    for (int ii = 0; ii < curpos; ii++){
        printf("%d\n", ptr[ii]);
    }
    free(ptr);
}

