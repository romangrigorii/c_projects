// Palindrome Permutation: Given a string, write a function to check if it is a permutation of
// a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
// permutation is a rearrangement of letters. The palindrome does not need to be limited to just
// dictionary words.
// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat'; "atc o eta·; etc.)

#include <iostream> // for cout + endl
#include <vector> // for vector
#include <set> // for set 
#include <map> // for map
#include <cstring> // for memset
#include <iostream>
#include <string>

using namespace std;
bool palindrome(string s1){
    int jj = s1.size()-1;
    int ii = 0;
    while (ii < s1.size()){
        while (s1[jj] == ' '){
            --jj;
        }
        if (s1[ii] != ' '){
            if (s1[ii]!=s1[jj--]) return false;
        }
        ii++;        
    }
    return true;
}

bool palindrome_permut(string s1){
    int32_t mask = 0;
    for (char c: s1){        
        if (c != ' '){
            mask ^= (1<<c); // this toggles a bit in location c
        }
    }
    return (mask & (mask - 1)) == 0; // check if exactly one bit is set to 1
}

int main(){
    string s1 = "missim";
    string s2 = "helle";
    string s3 = "taco cat";
    string s4 = "hell";
    cout << palindrome(s1) << " " << palindrome(s2) << " " << palindrome(s3) << " " << palindrome(s4) << endl;
    cout << palindrome_permut(s1) << " " << palindrome_permut(s2) << " " << palindrome_permut(s3) << " " << palindrome_permut(s4) << endl;
}