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

    int* arr = new int[2]{22, 23};
    ls.list_add(2, arr);
    ls.print();

    cout<<(ls.list_is_sorted()?"true":"false")<<endl;

    ls.list_reverse();
    ls.print();

    ListSeq* ls2 = new ListSeq(5);
    ls2->add(12);

    cout<<(ls.list_equal(ls2)?"true":"false")<<endl;

    ListSeq* ls3 = ls.list_from_vector(2, arr);
    ls3->print();

    ListSeq* ls4 = ls.list_copy();
    ls.print();
    ls4->print();

    ls.resize();
    ls.resize();
    ls.resize();
    cout << ls.list_concat(ls4) <<endl;
    ls.print();

    return 0;
}