#include <iostream>
#include <algorithm>
#include <cstdio>
#include "circ.hpp"

using namespace std;

int main(){
    CircleList* cl = new CircleList();

    cl->push_front(1);
    cl->push_front(2);
    cl->push_front(3);
    cl->push_front(33);
    cout<<cl->get(2)<<endl;
    // cl->print();
}