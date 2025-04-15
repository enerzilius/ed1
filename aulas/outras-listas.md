# Duplamente Encadeada
### Diferença da encadeada:
- Aponta para as duas direções (prev e next)
- Disponível como std::List
```c++
head --> |3| <-> |8| <-> |2| <-> |5| -->___
```

# Circular
### A simples é pouco utilizada
- Não precisa tratar ponteiro null
- Dificulta colocar no ínicio da lista
- Precisa gerenciar bem o tamanho da lista
- cuidar para não fazer um loop infinito
```c++
start --> |3| --> |8| --> |2| --> |5| |
           ^--------------------------| 
```

# Circular Duplamente encadeada
- para inserir no fim pode-se inserir no anterior do primeiro, sem necessitar de cauda(tail)
- Dificulta colocar no ínicio da lista
- Precisa gerenciar bem o tamanho da lista
- cuidar para não fazer um loop infinito
```c++
start --> |3| <-> |8| <-> |2| <-> |5| 
          ^------------------------^
```
  