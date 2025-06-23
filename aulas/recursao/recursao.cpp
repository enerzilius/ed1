#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <forward_list>


using namespace std;

void print_txt(char* txt, int num){
    if(num == 0) return;

    cout<<txt<<endl;
    return print_txt(txt, num-1);
}

void count50(int current) {
    if (current > 50) {
        return; 
    }
    
    cout << current << " ";
    count50(current + 1);
}

void count(int num) {
    if (num <= 0) {
        return;
    }
    
    cout << "Contagem " << num << ": ";
    count50(0);
    cout << endl;
    
    count(num - 1);
}


void counterToMax(int current, int max) {
    if(current > max) return;
    cout<<current<<" ";
    counterToMax(++current, max);
}

void count_max(int num, int max){
    if(num <= 0) return;
    cout<<"Contegem "<<num<<" a "<<max<<": ";
    counterToMax(0, max);
    cout<<endl;
    count_max(num-1, max);
}

void print_vec(vector<int>& vec, int idx){
    if(idx >= vec.size()){
        cout<<endl;
        return;
    } 
    cout<<vec[idx]<<" ";
    print_vec(vec, ++idx);

}

void print_even(vector<int>& vec, int idx){
    if(idx == vec.size()) --idx; 
    if(idx < 0) return;

    if(idx % 2 == 0) cout<<vec[idx]<<" ";

    print_even(vec, idx-1);
}     

void print_list(list<int> &lst, list<int>::iterator &it) {
    if(*it == lst.back()){
        cout<<*it<<endl;
        return;
    } 

    cout<<*it<<" ";
    print_list(lst, ++it);
}

void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it) {
    if(it == lst.end()) {
        return;
    }
    
    int curr = *it;
    
    print_rev(lst, ++it);
    cout<<curr<<" ";
}

void remove_all(vector<int> &vec) {
}

void print_stack(stack<int> &stk) {
}

void push_to(stack<int> &stk1, stack<int> &stk2) {

    
}

void copyVector(vector<int> &vec1, int idx, vector<int> &vec2){
}

void copy(list<int> &list1, list<int>::iterator &it, list<int> &list2) {
}

int main(){
    print_txt("Omori", 10);

    count(2);

    int max = 14;
    
    count_max(2, max);
    cout<<endl;

    vector<int> vec = {1,3,4,5,6};
    cout<<"Vetor: ";
    print_vec(vec, 0);
    cout<<"Posicoes pares do Vetor: ";
    print_even(vec, vec.size());
    cout<<endl;

    cout<<"Lista: ";
    list<int> lst = {1,10,3,4,5,6};
    list<int>::iterator it = lst.begin();
    print_list(lst, it);

    forward_list<int> fl = {4,5,6,7,8};
    cout<<"Lista encadeada: ";
    for(int e : fl){
        cout<<e<<" ";
    }
    cout<<endl;
    forward_list<int>::iterator fit = fl.begin();
    cout<<"Lista encadeada reversa: ";
    print_rev(fl, fit);
    cout<<endl;

    // remove_all(vec);

    // stack<int> stk;
    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // cout<<"Pilha: ";
    // print_stack(stk);
    // cout<<endl;

    // stack<int> stk2;
    // push_to(stk, stk2);
    // cout<<"Pilha Invertida: ";
    // print_stack(stk2);
    // cout<<endl;

    // vector<int> vec2 = {1,2,3,4,5};
    // vector<int> vec3;

    // copyVector(vec2, 0, vec3);
    // print_vec(vec3, 0);

    // list<int> ls2;
    // list<int>::iterator it2 = lst.begin();
 
    // copy(lst, it2, ls2);
    // it2 = ls2.begin();
    // print_list(ls2, it2);
    
    return 0;
}