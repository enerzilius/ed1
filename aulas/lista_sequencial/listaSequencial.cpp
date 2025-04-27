#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main() {
    ListSeq ls(5);
    ls.add(12);
    ls.add(2);
    ls.add(30);
    ls.add(4);
    ls.add(5);
    ls.print();

    if (ls.isFull()) ls.resize();
    ls.add(20);
    ls.print(); 

    ls.remove();
    ls.print();

    ls.removeAt(3);
    ls.print();
    ls.insert(0, 1);
    ls.print();
    if (ls.isFull()) ls.resize();
    ls.addSorted(3);
    ls.print();
    cout<<ls.list_get_available()<<endl;

    ls.list_clear();
    ls.print();
    cout<<ls.list_get_available()<<endl;

    ls.addSorted(3);
    ls.addSorted(0);
    ls.addSorted(4);
    ls.addSorted(29);
    ls.addSorted(21);
    ls.list_remove_last(1);
    ls.print();
    ls.list_print_reverse();

    int* arr = new int[2]{1, 2};
    ls.list_add(2, arr);
    ls.print();

    return 0;
}