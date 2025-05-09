#include <iostream>
#include <algorithm>
#include <cstdio>
#include "circ.hpp"

using namespace std;

CircleList::CircleList() { 
    this->head = nullptr;
    this->tail = this->head;
};

CircleList::~CircleList() { };

bool CircleList::push_front(int key)  { 
    Node* node = new Node{key, nullptr, nullptr};
    if(!head) {
        node->next = node;
        node->prev = node;
        this->head = node;
        return true;
    }
    node->next = this->head;

    if(this->head->next == this->head){ 
        this->head->next = node;
    }
    
    node->prev = this->head->prev;
    this->head->prev->next = node;
    head->prev = node;
    this->head = node;

    return true;  
};

bool CircleList:: pop_front(){
    if(!this->head) return false;

    Node* node = this->head;
    this->head = node->next;
    delete node;
    return true;
};

int CircleList::get(int pos){
    if (pos >= this->size()) return 0;
    Node* node = this->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }
    return node->key;
}; 

Node* CircleList::getNode(int pos){
    if (pos >= this->size()) return 0;
    Node* node = this->head;
    for (int i = 0; i < pos; i++)
    {
        node = node->next;
    }
    return node;
}; 

void CircleList::print() { 
    Node* aux = this->head;
    cout<<this->size()<<endl;
    for (int i = 0; i < this->size() && aux; i++)
    {
        cout << aux->key << " ";
        aux = aux->next;
    }
    cout << endl;
}

bool CircleList::empty() { 
    return this->head == nullptr;
};
void CircleList::push_back(int key){
    Node* node = this->head;
    while(node->next){
        node = node->next;
    }
    node->next = new Node{key, nullptr};
};
bool CircleList::pop_back() {
    Node* node = this->head;
    while(node->next->next){
        node = node->next;
    }
    if(!node) return false;
    node->next = nullptr;   
    delete node->next;
    return true;
};

Node* CircleList::find(int key) {
    Node *node = this->head;
    for (int i = 0; i < this->size(); i++)
    {
        if(node->key == key) return node;
        node = node->next;
    }
    
    return new Node{-1, nullptr};
};

bool CircleList::insert_after(int key, Node* pos) {
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

bool CircleList::remove_after(Node* pos){
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

bool CircleList::insert(int key, int pos) {
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

bool CircleList::remove(int pos){
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

bool CircleList::remove_key(int key) {
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
bool CircleList::insert_sorted(int key) {
    return true;
};

int CircleList::size() {
    int n = 0;  
    Node* node = this->head;
    while (node)
    {
        node = node->next;
        n++;
    }
    return n;
    
}

bool CircleList::equals(CircleList* list) {
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

void CircleList::print_last(){
    Node* node = this->head;
    while(node->next){
        node = node->next;
    }
    cout<<node->key<<endl;
}

bool CircleList::is_sorted(){
    Node* node = this->head;
    int temp = node->key;
    while(node){
        if(node->key <= temp) return false;
        node->next;
        temp = node->key;
    }
    return true;
}
