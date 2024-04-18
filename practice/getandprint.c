#include <stdio.h>
#include <stdlib.h>

// This page contains different methods of grabbing input from stdin and printing it out

// method 1 to grab input and print it out

// int main(int argc, char* argv[]){
//     printf("%s\n", argv[1]);
//     return 0;
// }

// method 2 to grab input and print it out

// int main(){
//     char c;
//     while ((c = getc(stdin)) != '\n'){
//         putc(c,stdout);
//         //printf("%c", c);
//     }
//     printf("\n");
//     return 0;
// }

// method 3 to grab input and print it out

// int main(){
//     char * out = malloc(2*sizeof(char));
//     int len = 1;
//     while ((*out=getc(stdin)) !='\n'){
//         realloc(out++, ++len);
//     }
//     *out = '\0';
//     out -= len;
//     printf("%s\n", ++out);
// }