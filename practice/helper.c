#include <stdio.h>

// stlen will return the length of a string 
int stlen(char * st){
    int i = 0;
    for (i = 0;*(st)!='\0';i++,st++);
    return i;
}


// matmult multiples two matrices together
void matmult(int M, int N, int P, int A[M][P], int B[P][N], int C[M][N]){
  for(int m = 0; m<M; m++){
    for(int n = 0; n<N ; n++){
      C[m][n] = 0;
      for(int p = 0; p<P ;p++)
        C[m][n] += A[m][p]*B[p][n];

    }
  }
}

// given number of rows R, columns C, and the matrix mat, printmat will print out the matrix in a beautiful way
void printmat(int R, int C, int mat[R][C]){
  for(int r=0;r<R;r++){
    for(int c=0;c<C;c++){
      if (c)
        if (c<(C-1))
          printf(" %d", mat[r][c]);
        else
          printf(" %d|", mat[r][c]);
      else
        if (C==1)
          printf("|%d|", mat[r][c]);
        else
          printf("|%d", mat[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}
