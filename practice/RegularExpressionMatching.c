#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// DOES NOT WORK
// https://leetcode.com/problems/regular-expression-matching/


bool isMatch(char s[], char p[]){
    bool nonfirst = false;
    int pcount = 0;
    while ((*s != '\0') && (*p != '\0')){
        if (*s == *p || *s == '.' || *p == '.'){
            s++;
            p++;
            nonfirst = true;
        } else if (*p=='*') {
            if (nonfirst){
                if (*(p-1) == '.'){
                    if (*(p+1) == '\0'){
                        return true;
                    }
                    while (*(p+1) != *s && *s != '\0'){
                        s++;
                    }
                } else {
                    while (*(p-1) == *s && *s != '\0'){
                        s++;
                        pcount++;                               
                    }
                    p++;
                    while (--pcount && *p != '\0' && *p==*(s-1)){
                        p++;
                    }
                    pcount = 0;
                }
            } else {
                p++;
            }
        } else {
            p++;
        }
    }
    return ((*s == '\0') && (*p == '\0'));
}

int main(){
    printf("The words 'aa' and 'a' match: %d \n", isMatch("aa", "a"));
    printf("The words 'aa' and 'a*' match: %d \n", isMatch("aa", "a*"));
    printf("The words 'aaa' and 'a*a' match: %d \n", isMatch("aaa", "a*a"));
    printf("The words 'aaa' and 'ab*a*c*a' match: %d \n", isMatch("aaa", "ab*a*c*a"));
    printf("The words 'aab' and 'c*a*b' match: %d \n", isMatch("aab", "c*a*b"));
    printf("The words 'mississippi' and 'mis*is*p*.' match: %d \n", isMatch("mississippi", "mis*is*p*."));
    printf("The words 'ab' and '.*' match: %d \n", isMatch("ab", ".*"));
    return 0;
}

