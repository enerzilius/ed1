#include <iostream>
#include <algorithm>
#include <cstdio>
#include "dup-enc.hpp"

using namespace std;

int main(){
    DoubleLinked* dl = new DoubleLinked();

    dl->push_front(1);
    dl->push_front(2);
    dl->push_front(2);
    dl->push_front(33);
    dl->print();

    dl->pop_front();
    dl->print();

    cout<<dl->get(2)<<endl;
}