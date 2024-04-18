#include <stdio.h>
#include <math.h>
#include <string.h>


struct Basic {
  int a;
  int b;
};

int main() {

    struct Basic new;
    new.a = 100;
    new.b = 50;

    FILE* output = fopen("C:/Users/Roman/Desktop/Work/Coding and Analytics/L2C/C/structs/Data.dat","wb");
    fwrite(&new,sizeof(new),1,output);
    fclose(output);

    return 0;
}
