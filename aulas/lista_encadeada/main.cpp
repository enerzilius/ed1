#include <iostream>
#include <algorithm>
#include "listaEnc.hpp"

using namespace std;

int main() {
    LinkedList *ls = new LinkedList();
    if (ls->empty()){
        cout<<"Lista vazia\n";
    }else{
        cout<<"tem alguma coisa\n";
    }
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

    ls->remove(2);
    ls->print();

    ls->insert_after(20, ls->find(11));
    ls->print();

    ls->remove_key(11);
    ls->print();

    ls->push_back(30);
    ls->print();
    ls->pop_back();
    ls->print();

    ls->remove_after(ls->find(13));
    ls->print();

    ls->print_last();
    if(ls->is_sorted()){
        cout<<"Ordenado\n";
    }else cout<<"Não ordenado\n";

    ls->insert_sorted(9);
    ls->print();
    ls->~LinkedList();
    if(ls){
        cout<<"Existe\n";
        ls->print();
    }else cout<<"Não existe\n";

    return 0;
}