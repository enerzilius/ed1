#include <iostream>
#include <algorithm>
#include <cstdio>
#include "listaEnc.hpp"

using namespace std;

LinkedList::LinkedList() { 
    this->head = nullptr;
};

LinkedList::~LinkedList() { };

bool LinkedList::push_front(int key)  { 
    Node* node = new Node{key, nullptr};
    if(!node) return false;

    node->next = this->head;
    this->head = node; 
    return true;
};

bool LinkedList:: pop_front(){
    if(!this->head) return false;

    Node* node = this->head;
    this->head = node->next;
    delete node;
    return true;
};

int LinkedList::get(int pos){
    if (pos >= this->size()) return 0;
    Node* node = this->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }
    return node->key;
}; 

void LinkedList::print() { 
    Node* aux = this->head;
    for (int i = 0; i < this->size() && aux; i++)
    {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

bool LinkedList::empty() { 
    return true;
};
void LinkedList::push_back(int key){

};
bool LinkedList::pop_back() {
    return true;
};

Node* LinkedList::find(int key) {
    Node *node = this->head;
    for (int i = 0; i < this->size(); i++)
    {
        if(node->key == key) return node;
        node = node->next;
    }
    
    return new Node{-1, nullptr};
};

bool LinkedList::insert_after(int key, Node* pos) {
    // if (pos >= this->size()) return false;
    // if(pos == 0) return this->push_front(key);

    // Node* aux = this->head;
    // for (int i = 0; i < pos && aux; i++)
    // {
    //     aux = aux->next;
    // }
    // if(!aux) return false;
    // Node* novo = new Node{key, aux->next};
    // aux->next = novo;
    return true;
};

bool LinkedList::remove_after(Node* pos){
    return true;
};

bool LinkedList::insert(int key, int pos) {
    if (pos >= this->size()) return false;
    if(pos == 0) return this->push_front(key);

    Node* aux = this->head;
    for (int i = 0; i < pos-1 && aux; i++)
    {
        aux = aux->next;
    }
    if(!aux) return false;
    Node* novo = new Node{key, aux->next};
    aux->next = novo;
    return true;
};

bool LinkedList::remove(int pos){
    return true;
};
bool LinkedList::removeKey(int key) {
    return true;
};
bool LinkedList::insert_sorted(int key) {
    return true;
};

int LinkedList::size() {
    int n = 0;  
    Node* node = this->head;
    while (node)
    {
        node = node->next;
        n++;
    }
    return n;
    
}

bool LinkedList::equals(LinkedList* list) {
    Node* temp = this->head;
    Node* temp2 = list->head;
    while(temp && temp2){
        if(temp->key == temp2->key){
            temp = temp->next;
            temp2 = temp2->next;
        }else{
            return false;
        }
    }
    return true;
}
