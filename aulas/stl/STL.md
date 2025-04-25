# Standart Template Library
- Lista Sequencial: vector
- Lista encadeada: forward_list
- Lista duplamente encadeada: list
- Pilha: stack
- Fila: queue
---
## Vector
```c++
int main() {
    vector<int> vec1 = {2,3,4,5}; // inicializa nop estilo array
    vector<int> vec2;             // possível inicializar vazio
    vector<int> copy = vec1;      // copia profunda

    for (int = 1; 1 <= 6; i++){
        vec1.push_back(i*10);
    }
    vec1.pop_back();

    for (int e: vec1){
        cout<<e<<' ';
    }
    cout<<endl;
    return 0;
}
```