// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: if implementing in Java, please use a character array so that you can
// perform this operation in place.)

#include <iostream> // for cout + endl
#include <vector> // for vector
#include <set> // for set 
#include <map> // for map
#include <cstring> // for memset
#include <iostream>
#include <string>

using namespace std;

void urlfy(string& s){
    for (size_t ii = 0; ii < s.size(); ii++){
        if (s[ii] == ' '){            
            s.replace(ii, 1, "");
            s.insert(ii,"%20");
        }
    }
}

void urlfy(char ** s, char * r, int n){ // we pass the char array by reference
    int num_spaces = 0;
    int clen = 0;
    for (int ii = 0; (*s)[ii] != '\0'; ii++){
        num_spaces += ((*s)[ii] == ' ');
        clen++;
    }
    char * ss = (char *) malloc(sizeof(char)*(clen + 1 + (num_spaces*(n-1))));
    int kk = 0, ii, jj;
    for (ii = 0; ii < clen; ii++){
        if ((*s)[ii] == ' '){
            for (jj = 0; jj < n; jj ++){
                ss[ii + jj + kk] = r[jj];
            }
            kk+=(n-1);
        } else {
            ss[ii+kk] = (*s)[ii];
        }
    }    
    ss[(clen + num_spaces*(n-1))] = '\0';
    *s = ss;
}


// main takeaway here is that in order to modify a point to char array we have to pass a pointer to it (**char)
// otherwise we won't be able to modify the adress located at *char

int main(){
    string s1 = "Hello World, put stuff in my spaces";
    string s2(s1);
    char *s = &s2[0];
    string to_place = "%20";
    urlfy(s1);
    urlfy(&s, &to_place[0], 3);
    cout << s1 << endl;
    cout << s << endl;
    free(s);
    return 0;
}