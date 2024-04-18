// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.

#include <iostream> // for cout + endl
#include <vector> // for vector
#include <set> // for set 
#include <map> // for map
#include <cstring> // for memset
#include <iostream>
#include <string>

using namespace std;

bool replace_one_or_zero(string s1, string s2){
    int off = 0;
    for (int ii = 0; ii<s1.size(); ii++){
        off += s1[ii]!=s2[ii];
        if (off>1){
            return false;
        }
    }
    return true;
}

bool insert_one(string s1, string s2){
    int i1 = 0, i2 = 0, skip = 0;
    while (i2 <= s2.size()){
        if (s2[i2]!=s1[i1]){
            if (skip){
                return false;
            } else {
                skip = 1;
                i2++;
            }
        } else {
            i1++;
            i2++;
        }
    }
    return true;
}

bool one_away(string s1, string s2){
    auto l1 = s1.size();
    auto l2 = s2.size();
    if (l1 == l2) {
        return replace_one_or_zero(s1,s2);
    } else {
        if (l1+1 == l2) {
            return insert_one(s1,s2);
        } else if (l1 == l2 + 1) {
            return insert_one(s2,s1);
        } else {
            return false;
        }
    }
}


int main(){
    string s1 = "pale";
    string s2 = "ple";
    string s3 = "pales";
    string s4 = "bale";
    string s5 = "bake";


    cout << s1 << " is" << (one_away(s1,s2) ? " " : " not ") << "one away from " << s2 << endl;
    cout << s3 << " is" << (one_away(s3,s1) ? " " : " not ") << "one away from " << s1 << endl;    
    cout << s3 << " is" << (one_away(s3,s4) ? " " : " not ") << "one away from " << s4 << endl;
    cout << s1 << " is" << (one_away(s1,s5) ? " " : " not ") << "one away from " << s5 << endl;
}