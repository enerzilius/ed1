#include <iostream>
#include <algorithm>

using namespace std;

struct LinkedList {
    Node* head;
    Node* tail;
};

struct Node {
    int key;
    Node* next;
};

class Node {
public:
    int key;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList(); // método destrutor
    bool push_front(int key);
    bool pop_front();
    int get(int pos);
    void print();
    int size();
    bool empty();
    void push_back(int key);
    bool pop_back();
    Node* find(int key);
    bool insert_after(int key, Node* pos);
    bool remove_after(Node* pos);
    bool insert(int key, int pos);
    bool remove(int pos);
    bool remove(int key);
    bool insert_sorted(int key);
    int size();
    bool equals(LinkedList* list);
};