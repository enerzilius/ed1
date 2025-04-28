#include <iostream>

using namespace std;

class ListSeq {

public:
    int size = 0;   // controla as ocupações
    int capacity;   // define a capacidade da lista
    int* data;      // endereço (aponta) do vetor da lista
    // construtor que cria a instância da lista
    ListSeq(int _capacity);
    // Libera a memória alocada para o vetor
    void destroy();
    // realoca vetor 
    void resize();
    // imprime conteúdo da lista
    void print();
    // retorna posição do elemento ou -1
    int find(int elem);
    // obtém o elemento na posição passada
    int get(int pos);
    // lista vazia?
    bool isEmpty();
    // lista cheia?
    bool isFull();
    // insere elemento no final
    bool add(int elem);
    // remove elemento do final
    void remove();
    // insere elemento na posição especificada
    void insert(int elem, int pos);
    // remove elemento na posição especificada
    void removeAt(int pos);
    // insere elemento em ordem crescente
    bool addSorted(int elem);
    int list_get_available();
    void list_clear();
    void list_remove_last(int n);
    void list_print_reverse();
    void list_add(int n, int* vet);
    bool list_is_sorted();
    void list_reverse();
    int list_equal(ListSeq* outra);
    ListSeq* list_from_vector(int n, int* vet);
    ListSeq* list_copy();
    int list_concat(ListSeq* list2);
};