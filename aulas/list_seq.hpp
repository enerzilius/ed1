#include <iostream>

using namespace std; // ! equivalente a from math import * 

class ListSeq {
public: 
    int size = 0; 
    int capacity;
    int* data;

    // ? Operações de criação e acesso
    ListSeq(int _capacity);
    void destroy();
    void resize();
    void print();
    void find(int elem);
    void get(int pos);
    bool isEmpty();
    bool isFull();

    // ? Operações de modificação
    bool add(int elem);
    bool remove();
    void insert(int elem, int pos);
    void removeAt(int pos);
    bool addSorted(int elem);

};
