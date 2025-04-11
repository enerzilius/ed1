#include <iostream>
#include <algorithm>
#include "listaEnc.hpp"

using namespace std;

int main() {
    LinkedList *ls = new LinkedList();
    ls->push_front(10);
    ls->push_front(11);
    ls->push_front(12);
    ls->push_front(13);
    ls->print();
    cout<<ls->size()<<"\n";

    ls->insert(15,2);
    ls->print();
    cout<<ls->find(15)->key<<"\n";
    cout<<ls->get(1)<<"\n";

    return 0;
}