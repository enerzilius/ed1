#include <iostream>
#include <algorithm>
#include <cstdio>
#include "listaEnc.hpp"

using namespace std;

LinkedList::LinkedList() { 
    this->head = nullptr;
};

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr; // optional but good practice
}

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
    return this->head == nullptr;
};
void LinkedList::push_back(int key){
    Node* node = this->head;
    while(node->next){
        node = node->next;
    }
    node->next = new Node{key, nullptr};
};
bool LinkedList::pop_back() {
    Node* node = this->head;
    while(node->next->next){
        node = node->next;
    }
    if(!node) return false;
    node->next = nullptr;   
    delete node->next;
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
    if (!pos) return false;

    Node* aux = this->head;
    while (aux)
    {
        if(aux == pos) break;
        aux = aux->next;
    }
    if(!aux) return false;
    Node* novo = new Node{key, aux->next};
    aux->next = novo;
    return true;
};

bool LinkedList::remove_after(Node* pos){
    Node* node = this->head;
    while(node){
        if(node == pos) break;
        node = node->next;
    }
    if(!node || !node->next) return false;
    Node* temp = node->next;
    node->next = temp->next;
    delete temp;
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
    if (pos >= this->size()) return false;
    if(pos == 0) return this->pop_front();

    Node* antes = this->head;
    for (int i = 0; i < pos-1; i++)
    {
        antes = antes->next;
    }

    if(!antes) return false;
    Node* temp = antes->next;
    antes->next = temp->next;
    delete temp;
    
    return true;
};

bool LinkedList::remove_key(int key) {
    Node* node = this->head;
    while(node){
        if(node->next->key == key) break;
        node = node->next;
    }
    if(!node) return false;

    Node* temp = node->next;
    node->next = temp->next;
    delete temp;
    
    return true;
};
bool LinkedList::insert_sorted(int key) {
    Node* aux = this->head;
    if(key < aux->key || aux == nullptr) return this->push_front(key);    
    while(aux->next && key >= aux->next->key)
    {
        aux = aux->next;
    }
    Node* novo = new Node{key, aux->next};
    aux->next = novo;
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

void LinkedList::print_last(){
    Node* node = this->head;
    while(node->next){
        node = node->next;
    }
    cout<<node->key<<endl;
}

bool LinkedList::is_sorted(){
    if(!this->head) return false;
    Node* node = this->head;
    while(node->next){
        if(node->key > node->next->key) return false;
        node = node->next;
    }
    return true;
}

LinkedList* LinkedList::deep_copy(LinkedList* list) {
    LinkedList* new_list = new LinkedList();
    Node* node = list->head;
    while(node){
        new_list->push_back(node->key);
        node = node->next;
    }
    cout<<new_list->size()<<endl;
    return new_list;
}
