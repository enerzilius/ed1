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


int main(){
    vector<int> vec = {4, 2, 3, 4};
    cout<<"Soma de um vetor: "<<sum(vec, 0)<<endl;

    list<int> lst = { 2, 3, 4, 2};
    list<int>::iterator it = lst.begin();
    cout<<"Produto de uma lista: "<<product(lst, it)<<endl;
    cout<<"Menor do vetor: "<<min(vec, 0)<<endl;
    it = lst.begin();
    cout<<"Menor da lista: "<<minLst(lst, it)<<endl;


    return 0;
}