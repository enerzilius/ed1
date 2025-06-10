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

## Merge Sort Recursivo
```c++
void merge(int arr[], int left, int mid, int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];
  for(int i = 0; i < n1; i++) L[i] = arr[left+i];
  for(int j = 0; j < n1; j++) R[j] = arr[mid+1+i];

  int i = 0, j = 0, k = left;
  while(i < n1 && i < n2){
    if(L[i] <= R[j]) arr[k++] = L[i++];
    else arr[k++] = R[j++];
  }
  while(i < n1) arr[k++] = L[i++];
  while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){ 
  if(left >= right) return;
  int mid = (left+right)/2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid+1, right);
  merge(arr, left, mid, right); 
}
```

## Merge Sort Recursivo com vetor
```c++
void merge(vector<int> &v, int left, int mid, int right){
  vector<int> temp;
  int i = left, j = mid+1;
  while (i <= mid & &  j <= right){
    if(v[i] <= v[j]) temp.push_back(v[i++]);
    else temp.push_back(v[j++]);
  }
  while(i <= mid) temp.push_back(v[i++]);
  while(j <= right) temp.push_back(v[j++]);
  for(int k = 0; k <= temp.size(); k++){
    v[left+k] = temp[k];
  }
}
```