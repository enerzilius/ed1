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

    // ls->~LinkedList();
    // if(ls){
    //     cout<<"Existe\n";
    //     ls->print();
    // }else cout<<"Não existe\n";

    LinkedList *ls2 = new LinkedList();
    ls2->insert_sorted(15);

    ls2->insert_sorted(9);
    ls2->print();
    ls2->insert_sorted(20);
    ls2->insert_sorted(13);
    ls2->print();

    if(ls2->is_sorted()){
        cout<<"Ordenado\n";
    }else cout<<"Não ordenado\n";

    LinkedList* sorted = ls2->deep_copy(ls2);
    sorted->print();
    
    ls = ls->concat(ls2);
    ls->print();

    ls = ls->merge(sorted);
    ls->print();

    return 0;
}