#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std; // ! equivalente a from math import * 

ListSeq::ListSeq(int _capacity) {
    capacity = _capacity;
    data = new int[_capacity];
};

bool ListSeq::add(int elem) {
    if (size >= capacity) return false;

    data[size++] = elem;
    return true;
};

bool ListSeq::isEmpty(){
    return size == 0;
}

bool ListSeq::isFull(){
    return size == capacity;
}

void ListSeq::print(){
    for (int i = 0; i < size; i++)
    {
        cout<< data[i] << "/b";
    }
    cout<<"end";
    
}

void resize();
void print();
void find(int elem);
void get(int pos);