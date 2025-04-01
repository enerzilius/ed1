#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

// construtor que cria a instância da lista
ListSeq::ListSeq(int _capacity) {
  data = new int[_capacity];
  capacity = _capacity;
}

// Libera a memória alocada para o vetor
void ListSeq::destroy() {}

// realoca vetor 
bool ListSeq::resize() {
  return true;
}

// imprime conteúdo da lista
void ListSeq::print() {
  for (int i=0; i<size; i++)
    cout << data[i] << " ";
  cout << endl;
}

// retorna posição do elemento ou -1
int ListSeq::find(int elem) {
  return 1;
}

// obtém o elemento na posição argumentada
int ListSeq::get(int pos) {
  return 1;
}

// lista vazia?
bool ListSeq::isEmpty() {
  if (size == 0)
    return true;
  else
    return false;
}

// lista cheia?
bool ListSeq::isFull() {
  if (size == capacity)
    return true;
  else
    return false;
}

// insere elemento no final
bool ListSeq::add(int elem) {
  if (size < capacity) {
    data[size++] = elem;
    return true;
  } else
    return false;
}

// remove elemento do final
bool ListSeq::remove() {
  return true;
}

// insere elemento na posição especificada
void ListSeq::insert(int elem, int pos) {}

// remove elemento na posição especificada
bool ListSeq::removeAt(int pos) {
  return true;
}

// insere elemento em ordem crescente
bool ListSeq::addSorted(int elem) {
  return true;
}