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
    if(n == 1) return sum(vec, n+1);
    if(n == 0) return sum(vec, n+2);

    return vec[n] + vec[n-2] + sum(vec, n+2);
}

int product(list<int>& lst, list<int>::iterator it){
    if (it == lst.end()) return 1; 
    int current = *it;
    return *it  * product(lst, ++it);
}

int min(vector<int>& vec, int n){
    if (n >= vec.size() - 1) return vec[vec.size() - 1];
    int minRest = min(vec, n + 1);
    return (vec[n] < minRest) ? vec[n] : minRest;
}

int minLst(list<int>& lst, list<int>::iterator it){
    if (it == lst.end()) return lst.back();
    int minRest = minLst(lst, ++it);
    return (*it < minRest) ? *it : minRest;
}

bool find(vector<int>& vec, int n, int elem){
    if (n >= vec.size()) return false;
    if(vec[n] == elem) return true;
    return find(vec, n+1, elem);
}

int count(vector<int>& vec, int n, int elem){
    if (n >= vec.size()) return 0;
    if(vec[n] == elem) return 1 + count(vec, n+1, elem);
    return count(vec, n+1, elem);
}

void reverse(vector<int>& vec, int first, int last) {
    if (first >= last) return;

    int temp = vec[first];
    vec[first] = vec[last];
    vec[last] = temp;
    
    reverse(vec, first + 1, last - 1);
}

void reverseList(list<int>& lst, list<int>::iterator first, list<int>::iterator last){
    if (first == last) return;

    --last;
    if (first == last) return;

    int temp = *first;
    *first = *last;
    *last = temp;
    
    reverseList(lst, ++first, last);
}

bool palindrome(string& str, int first, int last) {
    if (first >= last) {
        return true;
    }
    if (str[first] != str[last]) {
        return false;
    }
    return palindrome(str, first + 1, last - 1);
}

bool palindromeList(list<int>& lst, list<int>::iterator first, list<int>::iterator last) {
    if (first == last) {
        return true;
    }
    --last;
    
    if (first == last) {
        return true;
    }
    
    if (*first != *last) {
        return false;
    }
    
    ++first;
    return palindromeList(lst, first, last);
}


int main(){
    vector<int> vec = {4, 2, 3, 4, 4};
    cout<<"Soma de um vetor: "<<sum(vec, 0)<<endl;

    list<int> lst = { 2, 3, 4, 2};
    list<int>::iterator it = lst.begin();
    cout<<"Produto de uma lista: "<<product(lst, it)<<endl;
    cout<<"Menor do vetor: "<<min(vec, 0)<<endl;
    it = lst.begin();
    cout<<"Menor da lista: "<<minLst(lst, it)<<endl;
    cout<<(find(vec, 0, 10)?"Encontrado":"Não encontrado")<<endl;

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

    string str = "arara";
    cout<<(palindrome(str, 0, str.size()-1)?"Palindromo":"Não palindromo")<<endl;

    list<int> palindromo = {1, 2, 2, 3};
    it = palindromo.begin();
    itLast = palindromo.end();
    cout<<(palindromeList(palindromo, it, itLast)?"Palindromo":"Não palindromo")<<endl;


    return 0;
}