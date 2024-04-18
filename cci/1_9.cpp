#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>


// checks if the two are rverse of each other
using namespace std;
int main(){
    string s1 = "waterbottle";
    string s2 = "elttobretaw";
    string cp(s2.rbegin(),s2.rend());
    cout << (s1 == cp) << endl;
}