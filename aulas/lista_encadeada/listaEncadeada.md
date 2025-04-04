# Lista Encadeada
- Encadeamento de nós que armazenam dados
- - acesso sequencial
  - não permite acesso aleatório
  - bom para inserir/remover em qualquer parte da lista, mão precisa ficar movendo as coisas
  - std::forward_list | aponta só pra frente
  - std::List é a lista duplamente encadeada | aponta pros elementos pra frente e em volta
 
 ``` c++
class Node {
public:
    int key;
    Node* next;
};

class LinkedList {
private:
    Node* head;
}

head -> |3| -> |8| -> |2| -> |5| -> __ (nullptr)
```

## Vantagens da lista encadeada:
- Redimensionamento
- Inserção/remoção no meio e no ínicio
  
##Estratégias avançadas
- Emprego de sentinela
  - Elemento "coringa" como primeiro da lista (meio feio)
``` c++
head -> | * | -> __
```
