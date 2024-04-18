#include <cstdio>
#include <cstring>


int main(void){
    int c[26];
    char arr[] = "aabcccccaa";
    memset(c, 0, sizeof(c));
    for (int ii = 0; ii < sizeof(arr)/sizeof(arr[0]); ii++){
        c[arr[ii]- 'a']+=1;
    }
}