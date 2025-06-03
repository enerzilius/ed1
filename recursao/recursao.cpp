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
        return; // Caso base: para quando chegar a 51
    }
    
    cout << current << " ";
    count50(current + 1); // Chamada recursiva incrementando
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
    if (current > max) {
        return;
    }
    
    cout << current << " ";
    counterToMax(current + 1, max);
}

void count_max(int num, int max){
    if (num <= 0) {
        return;
    }
    
    cout << "Contagem " << num << ": ";
    counterToMax(0, max);
    cout << endl;
    
    count_max(num - 1, max);
}

void print_vec(vector<int>& vec, int idx){
    if(idx == vec.size()){
        cout<<endl;
        return;
    } 
    
    if(idx == 0)cout<<"Vetor: ";
    cout<<vec[idx]<<" ";
    print_vec(vec, idx+1);
}

void print_even(vector<int>& vec, int idx){
    if(idx < 0){
        cout<<endl;
        return;
    } 
    if(idx == vec.size()) idx -= 1;


    if(vec[idx] % 2 == 0){
        if(idx == vec.size()-1)cout<<"Pares: ";
        cout<<vec[idx]<<" ";
    } 
    
    print_even(vec, idx-1);
}

void print_list(list<int> &lst, list<int>::iterator &it) {
    if (it == lst.end()) {
        cout<<endl;
        return;
    }

    if(it == lst.begin()) cout<<"Lista: ";
    
    cout << *it << " ";
    ++it;
    print_list(lst, it);
}

void print_rev(forward_list<int> &lst, forward_list<int>::iterator &it) {
    if (it == lst.end()) {
        return;
    }
    
    int current_value = *it;
    ++it;
    
    print_rev(lst, it);
    cout << current_value << " ";
}

int main(){
    print_txt("Omori", 10);

    count(2);

    count_max(3, 5);

    vector<int> vec = {1,3,4,5, 6};
    print_vec(vec, 0);

    print_even(vec, vec.size());

    list<int> lst = {1,10,3,4,5,6};
    list<int>::iterator it = lst.begin();
    print_list(lst, it);

    forward_list<int> fl = {4,5,6,7,8};
    forward_list<int>::iterator fit = fl.begin();
    cout<<"Lista encadeada reversa: ";
    print_rev(fl, fit);
    cout<<endl;

    return 0;
}