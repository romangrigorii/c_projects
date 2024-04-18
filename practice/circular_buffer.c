#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 5

typedef struct BUFFER {
    char * buf;
    int pos;
} BUFFER;

void buf_put(BUFFER *buf, char c){
    *(buf->buf + buf->pos) = c;
    if (++(buf->pos) == BUF_SIZE){
        buf->pos = 0;
    }
}

void buf_print(BUFFER *buf){
    int q = buf->pos;
    do {       
        putc(*(buf->buf + q),stdout);
        if (++q == BUF_SIZE){
            q = 0;
        }
    } while (q!=(buf->pos));
    putc('\n',stdout);
}

void buf_init(BUFFER *buf){
    buf->buf =  malloc(sizeof(char)*(BUF_SIZE+1));
    buf->pos = 0;
    for(int q = 0; q<BUF_SIZE; q++){
        *(buf->buf + q) = '0';
    }
    *buf->buf = '\0';
}

int main(){
    char c; 
    BUFFER buf;
    
    buf_init(&buf);
    while((c = getc(stdin)) != '\n'){
        buf_put(&buf, c);
    }
    buf_print(&buf);
}