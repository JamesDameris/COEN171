// James Dameris COEN 171 HW 2 tree.cpp
#include <iostream>
#include <cmath>
#include "tree.h"
using namespace std;
int main () {
    hw2::tree<int> t;
    t.insert(15);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(30);
    t.insert(25);

    cout << t.member(15) << endl;
    cout << t.member(5) << endl; 
    cout << t.member(25) << endl;
    cout << t.member(7) << endl;
    cout << t.member(11) << endl;
    cout << t.member(44) << endl;
}