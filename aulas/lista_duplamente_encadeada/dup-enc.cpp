#include <iostream>
#include <algorithm>
#include <cstdio>
#include "dup-enc.hpp"

using namespace std;

DoubleLinked::DoubleLinked() { 
    this->head = nullptr;
    this->tail = this->head;
};

DoubleLinked::~DoubleLinked() { 
    Node* node = this->head;
    while (this->head)
    {
        Node* temp = this->head;
        while(temp->next){
            temp = temp->next;
        }
        delete temp;
    }
};

bool DoubleLinked::push_front(int key)  { 
    Node* node = new Node{key, nullptr, nullptr};
    if(!head) {
        this->head = node;
        return true;
    }

    node->next = this->head;
    if(node->next) node->next->prev = node;
    else tail = node;
    this->head = node; 
    return true;
};

bool DoubleLinked:: pop_front(){
    if(!this->head) return false;

    Node* node = this->head;
    this->head = node->next;
    if(!this->head) this->tail = nullptr;
    delete node;
    return true;
};

int DoubleLinked::get(int pos){
    if (pos >= this->size()) return 0;
    Node* node = this->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }
    return node->key;
}; 

void DoubleLinked::print() { 
    Node* aux = this->head;
    for (int i = 0; i < this->size() && aux; i++)
    {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

bool DoubleLinked::empty() { 
    return this->head == nullptr;
};
void DoubleLinked::push_back(int key){
    if(!this->tail) return;

    Node* novo = new Node{key, nullptr, this->tail};
    this->tail->next = novo;
    this->tail = novo;
};
bool DoubleLinked::pop_back() {
    Node* node = this->head;
    while(node->next->next){
        node = node->next;
    }
    if(!node) return false;
    node->next = nullptr;   
    delete node->next;
    return true;
};

Node* DoubleLinked::find(int key) {
    Node *node = this->head;
    for (int i = 0; i < this->size(); i++)
    {
        if(node->key == key) return node;
        node = node->next;
    }
    
    return new Node{-1, nullptr};
};

bool DoubleLinked::insert_after(int key, Node* pos) {
    if (!pos) return false;

    Node* aux = this->head;
    pos->next = aux;
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

bool DoubleLinked::remove_after(Node* pos){
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

bool DoubleLinked::insert(int key, int pos) {
    if (pos >= this->size()) return false;
    if(pos == 0) return this->push_front(key);

    Node* aux = this->head;
    for (int i = 0; i < pos-1 && aux; i++)
    {
        aux = aux->next;
    }
    if(!aux) {
        this->push_back(key);
        return true;
    }
    Node* novo = new Node{key, aux->next, aux};
    aux->next->prev = novo;
    aux->next = novo;
    return true;
};

bool DoubleLinked::remove(int pos){
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

bool DoubleLinked::remove_key(int key) {
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
bool DoubleLinked::insert_sorted(int key) {
    return true;
};

int DoubleLinked::size() {
    int n = 0;  
    Node* node = this->head;
    while (node)
    {
        node = node->next;
        n++;
    }
    return n;
}

bool DoubleLinked::equals(DoubleLinked* list) {
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

void DoubleLinked::print_last(){
    Node* node = this->head;
    while(node->next){
        node = node->next;
    }
    cout<<node->key<<endl;
}

bool DoubleLinked::is_sorted(){
    Node* node = this->head;
    int temp = node->key;
    while(node){
        if(node->key <= temp) return false;
        node->next;
        temp = node->key;
    }
    return true;
}
