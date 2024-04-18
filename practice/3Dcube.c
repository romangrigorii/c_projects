#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define WIDTH 12
#define BUFFER_SIZE 50
#define PRINT_BUFFER 50

float A = 0.0, B = 0.0, C = 0.0;  // these are angles around thee major axes : x, y, z

char cube_buffer[PRINT_BUFFER][PRINT_BUFFER/2];
float z_buffer[PRINT_BUFFER][PRINT_BUFFER/2];
int xp, yp, zp, xx, yy;
float x,y,z, ooz;

// returns new x position of a rotated vector 
float xpos(float x, float y, float z, float rotx, float roty, float rotz){
    return x*cos(rotx)*cos(roty) + y*(sin(rotx)*sin(roty)*cos(rotz) - cos(rotx)*sin(rotz)) + z*(cos(rotx)*sin(roty)*cos(rotz) + sin(rotx)*sin(rotz));
}

float ypos(float x, float y, float z, float rotx, float roty, float rotz){
    return x*(cos(roty)*sin(rotz)) + y*(sin(rotx)*sin(roty)*sin(rotz) + cos(rotx)*cos(rotz)) + z*(cos(rotx)*sin(roty)*sin(rotz) - sin(rotx)*cos(rotz));
}

float zpos(float x, float y, float z, float rotx, float roty, float rotz){
    return -x*sin(roty) + y*sin(rotx)*cos(roty) + z*cos(rotx)*cos(roty);
}

float reset(){
    for (int i = 0; i<BUFFER_SIZE*BUFFER_SIZE/2; i++){
        *(cube_buffer[0] + i) = ' ';
    }
}

void print(){
    for (int i = 0; i<BUFFER_SIZE*BUFFER_SIZE/2; i++){
        putc(*(cube_buffer[0] + i), stdout);
        if (i%BUFFER_SIZE==0) printf("\n");
    }
}

void surfaceset(float x, float y, float z, float xang, float yang, float zang, char c){
    zp = zpos(x,y,z,xang,yang,zang);
    yp = ypos(x,y,z,xang,yang,zang);
    xp = xpos(x,y,z,xang,yang,zang);
    xx = BUFFER_SIZE/2+xp;
    yy = BUFFER_SIZE/4+yp/2;
    
    if (zp > z_buffer[xx][yy]){
        z_buffer[xx][yy] = zp;
        cube_buffer[xx][yy] = c;
    }
}


int main(){
    int c = 0;    
    float dd = 1.0;
    reset();
    A+=.03;
    B+=.04;
    C+=.05;
    for(;;){
        system("cls");
        reset();
        z = WIDTH;
        for(y=-WIDTH+dd;y<WIDTH;y+=dd){
            for(x=-WIDTH;x<WIDTH;x+=dd){
                surfaceset(x,y,z,A,B,C,'o');
            }
        }
        z = -WIDTH;
        for(y=-WIDTH+dd;y<WIDTH;y+=dd){
            for(x=-WIDTH;x<WIDTH;x+=dd){
                surfaceset(-x,-y,z,A,B,C,'o');
            }
        }

        x = WIDTH;
        for(y=-WIDTH+dd;y<WIDTH;y+=dd){
            for(z=-WIDTH;z<WIDTH;z+=dd){
                surfaceset(x,y,z,A,B,C,'.');
            }
        }
        x = -WIDTH;
        for(y=-WIDTH+dd;y<WIDTH;y+=dd){
            for(z=-WIDTH;z<WIDTH;z+=dd){
                surfaceset(x,-y,-z,A,B,C,'.');
            }
        }
        y = WIDTH;
        for(x=-WIDTH+dd;x<WIDTH;x+=dd){
            for(z=-WIDTH;z<WIDTH;z+=dd){
                surfaceset(x,y,z,A,B,C,'x');
            }
        }
        y = -WIDTH;
        for(x=-WIDTH+dd;x<WIDTH;x+=dd){
            for(z=-WIDTH;z<WIDTH;z+=dd){
                surfaceset(-x,y,-z,A,B,C,'x');
            }
        }
        print();
        
        Sleep(1000);
    }

    printf("Hey %lf\n", dd);
    return 0;
}