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
void ListSeq::destroy() {
    delete[] data; // * apaga (na heap) todos os ponteiros relacionados com  o tipo vetorial ([])
}

// realoca vetor 
void ListSeq::resize() {
  int* _data = new int[++capacity];
  for (int i = 0; i < size; i++)
  {
    _data[i] = data[i];
  } 
  destroy();
  data = _data;
}

// imprime conteúdo da lista
void ListSeq::print() {
  for (int i=0; i<size; i++)
    cout << data[i] << " ";
  cout << endl;
}

// retorna posição do elemento ou -1
int ListSeq::find(int elem) {
  for (int i = 0; i < size; i++)
  {
    if(elem == data[i]) return i;
  }
  return -1;
  
}

// obtém o elemento na posição argumentada
int ListSeq::get(int pos) {
  if(pos > size) return -1;
  return data[pos];
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
void ListSeq::remove() {
  if(isEmpty()) return;
  size--;
}

// insere elemento na posição especificada
void ListSeq::insert(int elem, int pos) {
  int temp = 0;
  int temp2 = 0;
  if (isFull() || pos < 0 || pos > size) return;
  for (int i = size; i > pos; --i) {
    data[i] = data[i - 1];
  }
  data[pos] = elem;
  ++size;
}

// remove elemento na posição especificada
void ListSeq::removeAt(int pos) {
  if(isEmpty() || pos > size) return; 
  if(pos == size-1){
    remove();
    return;
  }

  for (int i = pos; i < size-1; i++)
  {
    for (int i = pos; i < size-1; i++)
    {
      data[i] = data[i+1];
    }
  }
  size--;
}

// insere elemento em ordem crescente
// bool ListSeq::addSorted(int elem) {
//   for (int i = 0; i < size++; i++)
//   {
//     if(elem >= data[i]){
//       data[i];
//     }
//   }
  
// }