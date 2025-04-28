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
bool ListSeq::addSorted(int elem) {
  if(isFull()) return false;
  int i;
  for (i = size; i > 0 && data[i-1] >= elem; --i) {
    data[i] = data[i - 1];
  }
  data[i] = elem;
  size++;
  return true;
  
}

int ListSeq::list_get_available() {
  return capacity - size;
}

void ListSeq::list_clear() {
  size = 0;
}

void ListSeq::list_remove_last(int n) {
  if(n > size) return;
  size -= n;
}

void ListSeq::list_print_reverse() {
  for (int i = size-1; i>= 0; i--)
  {
    cout << data[i] << " ";
  }
  cout << endl;
}

void ListSeq::list_add(int n, int* vet) {
  if (size + n > capacity) return;

  for (int i = 0; i < n; i++)
  {
    this->add(vet[i]);
  }
}

bool ListSeq::list_is_sorted() {
  for(int i = 0; i < size-1; i++) {
    if(data[i] > data[i+1]) {
      return false;
    }
  }
  return true;
}

void ListSeq::list_reverse() {
  if(this->isEmpty()) return;
  ListSeq* temp = new ListSeq(size); 
  for (int i = size-1; i >= 0; i--)
  {
    temp->data[size-1-i] = data[i];
  }
  for (int i = 0; i < size-1; i++)
  {
    data[i] = temp->data[i];
  }
  
}

int ListSeq::list_equal(ListSeq* list) {
  if(size != list->size) return false;
  for (int i = 0; i < size; i++)
  {
    if(data[i] != list->data[i]) return false;
  }
  return true;
  
}

ListSeq* ListSeq::list_from_vector(int n, int* vet) {
  ListSeq* list = new ListSeq(n);
  list->capacity = n;
  for (int i = 0; i < n; i++)
  {
    list->add(vet[i]);
  }
  list->size = n;
  return list;
}

ListSeq* ListSeq::list_copy() {
  ListSeq* list = new ListSeq(size);
  list->capacity = size;
  for (int i = 0; i < size; i++)
  {
    list->add(this->data[i]);
  }
  list->size = size;  
  return list;
}

int ListSeq::list_concat(ListSeq* list2) {
  if(size+1 >= capacity) return 0;
  int i = 0;
  while(size+i < capacity && i < list2->size) {
    data[size+i] = list2->data[i];
    i++;
  }
  size += i;
  return i;
}