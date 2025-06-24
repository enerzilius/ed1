#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>


using namespace std;

int sum(vector<int>& vec, int n)
{
    if(n >= vec.size()) return 0;
    if(n == vec.size()-1) return vec[n];
    if(n % 2 != 0) sum(vec, n+1);
    return vec[n] + sum(vec, n+2);

}

int product(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return 1;
    return *it * product(lst, ++it);
}

int min(vector<int>& vec, int n){
    if(n >= vec.size()) return vec[0];
    if(n == vec.size()-1) return vec[n];
    int in = min(vec, n+1);
    return (vec[n]<in?vec[n]:in);
}

int minLst(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return lst.back();
    int curr = *it;
    int in = minLst(lst, ++it);
    return (curr<in?curr:in);
}

bool find(vector<int>& vec, int n, int elem){
    if(n >= vec.size()) return false;
    if(vec[n] == elem) return true;
    return find(vec, n+1, elem);
}

int count(vector<int>& vec, int n, int elem){
    if(n >= vec.size()) return 0;
    if(n == vec.size()-1) return vec[n] == elem? 1:0;
    return (vec[n] == elem? 1:0)+(count(vec, n+1, elem)); 
}

void reverse(vector<int>& vec, int first, int last) {
    if(first >= last) return;

    swap(vec[first], vec[last]);
    reverse(vec, ++first, --last);
}

void reverseList(list<int>& lst, list<int>::iterator first, list<int>::iterator last){
    if(first==last||first == --last) return;

    int temp = *first;
    *first = *last;
    *last = temp;

    reverseList(lst, ++first, last);
}

bool palindrome(string& str, int first, int last) {
    if(first>=last) return true;

    if(str[first] != str[last]) return false;
    return palindrome(str, ++first, --last);
}

bool palindromeList(list<int>& lst, list<int>::iterator first, list<int>::iterator last) {
    if(first == last || first == --last) return true;

    if(*first != *last) return false;
    return palindromeList(lst, ++first, last);
}


int main(){
    vector<int> vec = {4, 2, 3, -1, 4, 1, 4};
    cout<<"Soma do valor dos indices pares de um vetor: "<<sum(vec, 0)<<endl;

    list<int> lst = { 5, 3, 4, 2};
    list<int>::iterator it = lst.begin();
    cout<<"Produto de uma lista: "<<product(lst, it)<<endl;

    cout<<"Menor do vetor: "<<min(vec, 0)<<endl;

    it = lst.begin();
    cout<<"Menor da lista: "<<minLst(lst, it)<<endl;
    cout<<(find(vec, 0, 2)?"Encontrado":"Não encontrado")<<endl;

    cout<<"Número de vezes que 4 aparece: "<<count(vec, 0, 4)<<endl;

    reverse(vec, 0, vec.size()-1);
    cout<<"Vetor invertido: ";
    for(int e : vec){
        cout<<e<<" ";
    }
    cout<<endl;

    it = lst.begin();
    list<int>::iterator itLast = lst.end();
    reverseList(lst, it, itLast);
    cout<<"Lista invertida: ";
    for(int e : lst){
        cout<<e<<" ";
    }   
    cout<<endl;

    string str = "araraa";
    cout<<(palindrome(str, 0, str.size()-1)?"Palindromo":"Não palindromo")<<endl;

    list<int> palindromo = {1, 2, 2, 1};
    it = palindromo.begin();
    itLast = palindromo.end();
    cout<<(palindromeList(palindromo, it, itLast)?"Palindromo":"Não palindromo")<<endl;


    return 0;
}