#include <stdio.h>
#include <stdlib.h>
// #include "helpers.h"

int longestPalindrome(char * s, int L){
    int l, longest = 0, st = 0, en = 0;
    for (int i = 0; i<L; i++){
        for (l=1;(i-l)>=0 && (i+l)<L && s[i-l]==s[i+l];l++){}
        if (longest<(l-1)*2 + 1){
            longest = (l-1)*2 + 1;
            st = i-l+1;
            en = i+l-1;
        }
        for(l=1;(i-l+1)>=0 &&(i+l)<L && s[i-l+1]==s[i+l];l++){}
        if (longest<(l-1)*2){
            longest = (l-1)*2;
            st = i-l+2;
            en = i+l-1;
        }
    }
    char *out = malloc(sizeof(char)*(longest+1));    
    l = 0;
    while (st<en){
        out[l] = s[st];
        l++;
        st++;
    }
    out[l] = '\0';
    return en-st;
}

int main(){
    char * test1 = "babad";
    char * test2 = "cbbd";
    char * test3 = "bb";
    printf("The longest palindrome of %s is %d\n", test1, longestPalindrome(test1, 5));
    printf("The longest palindrome of %s is %d\n", test2, longestPalindrome(test2, 4));
    printf("The longest palindrome of %s is %d\n", test3, longestPalindrome(test3, 2));
    return 0;
}