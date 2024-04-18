// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

#include <iostream> // for cout + endl
#include <vector> // for vector
#include <set> // for set 
#include <map> // for map
#include <cstring> // for memset

#define BUFF_SIZE 128

using namespace std;

bool is_unique(std::string in ){
    set<char> mp;
    for (auto q: in){
        if (mp.find(q) != mp.end()) return false;
        mp.insert(q);
    }
    return true;
}

bool is_unique(const char * in){ // this is a C implemenation
    bool present[128];
    memset(present, 0, sizeof(bool)*BUFF_SIZE);
    for (int ii = 0; in[ii]!= '\0' && ii<128; ii++){
        if  (present[in[ii]]){
            return false;           
        }
        present[in[ii]] = true;        
    }
    return true;
}

int main(){
    string a("helo");
    cout << a << " is" << (is_unique(a) ? " " : " not ") << "unique" << endl;
    cout << a << " is" << (is_unique(&a[0]) ? " " : " not ") << "unique" << endl;
    return 0;
}