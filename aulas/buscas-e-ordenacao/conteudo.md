# Busca e Ordenação
## Algoritmos de Busca
- ### Busca Linear
  - _Brute force_;
  - Procura linearmente um elemento, verificando todas as posições do vetor;
  - *$N$ comparações*;
  - Se não se sabe como os dados foram ordenados, é a melhor opção.
-  ### Busca Binária
   -  Possível em vetores ordenados;
   -  Divide o vetor em dias metadas e só procura o elemento na metade em que pode estar;
   -  *$log_2N$ comparações*.
   -  *Busca Binária com STL:*
```c++
int main() {
    vector <int> v;
    ...
}
```
## Algoritmos de Ordenação
- Pode ser muito custoso;
- Os métodos diferentes podem ser escolhidos para diferentes situações;
- Os 3 que vão ser estudados são $N^2$ (2 laços de repetição)
- ### Selection Sort
  - itera por uma lista, definindo o menor valor da lista e então, o a posição de min é trocada com a do começo da lista;
  - isso é repetido até ter passado por todos os elementos
  - ```c++
    void sel_sort(int* v, int n){
        int min = 0;
        int index = 0;
        for(int i = 0; i < n; i++){
            min = v[i];
            int aux = 0;
            for(int j = i; j < n; j++){
                if(v[j] < min) {
                    ...
                }
            }
        }
    }
    ```
- ### Bubble Sort
  -   
-  ### Insertion Sort
-  Existem outros