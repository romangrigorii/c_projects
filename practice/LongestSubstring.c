#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include <math.h>

char * LongestSubstring(char * input){
    int s = 0, sl = 0;
    int e = 0, el = 0;
    int vals = 0, vale = 0;
    int len = 0;
    int q = 0;

    while (input[e] != '\0'){
        vale = input[e] - 'a';
        //printf("%d %d %d %d \n", s, e, q, vale);  
        while (q & (int) pow(2,vale) && e>s){
            vals = input[s] - 'a';
            q -= (int) pow(2,vals);
            s++;
        }
        q += (int) pow(2,vale);
        e++;  
        if (len < (e-s)){
            len = e-s;
            el = e;
            sl = s;
        }
        //printf("%d %d %d %d %d $$ \n", s, e, q, vale, len);      
    }
    char *out = malloc(sizeof(char)*(el-sl+1));    
    s = 0;
    while (sl<el){
        out[s] = input[sl];
        s++;
        sl++;
    }
    out[s] = '\0';
    return out;
}

int lengthOfLongestSubstring(char * input){
    int s = 0, sl = 0;
    int e = 0, el = 0;
    int vals = 0, vale = 0;
    int len = 0;
    int q = 0;
    while (input[e] != '\0'){
        if (input[e] == ' '){
            e++;
            if (len < (e-s)){
                len = e-s;
                el = e;
                sl = s;
            }
        } else {
            vale = input[e] - 'a';
            while (q & (int) pow(2,vale) && e>s){
                vals = input[s] - 'a';
                q -= (int) pow(2,vals);
                s++;
            }
            q += (int) pow(2,vale);
            e++;  
            if (len < (e-s)){
                len = e-s;
                el = e;
                sl = s;
            }
        }
    }
    return len;
}

int main(){
    char * test1 = "abcabcbb";
    char * test2 = "bbbb";
    char * test3 = "pwwkew";
    printf("The longest sustring of %s is %s and is of size %d\n", test1, LongestSubstring(test1), lengthOfLongestSubstring(test1));
    printf("The longest sustring of %s is %s and is of size %d\n", test2, LongestSubstring(test2), lengthOfLongestSubstring(test2));
    printf("The longest sustring of %s is %s and is of size %d\n", test3, LongestSubstring(test3), lengthOfLongestSubstring(test3));
    return 0;
}