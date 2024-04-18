// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.

#include <iostream> // for cout + endl
#include <vector> // for vector
#include <set> // for set 
#include <map> // for map
#include <cstring> // for memset
#include <algorithm> // for sort 

#define BUF_SIZE 256
using namespace std;
bool is_permuation(string s1, string s2){
    if (s1.size()!=s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1.compare(s2) == 0;
}

bool is_permutation(char * s1, char * s2){
    int exists[BUF_SIZE];
    for (int ii = 0; ii < BUF_SIZE && ii!='\0'; ii++){
        exists[s1[ii]]++;
    }
    for (int ii = 0; ii < BUF_SIZE && s1[ii]!='\0'; ii++){
        exists[s2[ii]]--;
        if (exists[s2[ii]]<0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "HELLO";
    string s2 = "LLOEH";
    string s3 = "LLOE";
    string s4 = "FABRW";
    std::cout << is_permuation(s1,s2) << " " << is_permuation(s1,s3) << " " << is_permuation(s1,s4) << endl;
    std::cout << is_permuation(s1.c_str(),s2.c_str()) << " " << is_permuation(s1.c_str(),s3.c_str()) << " " << is_permuation(s1.c_str(),s4.c_str()) << endl;
    return 0;
}