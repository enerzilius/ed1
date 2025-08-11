#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

float factorial(int n){
    if(n <= 0) return 1;
    return n*factorial(n-1);
}

float exponential(int n, int exp){
    if(exp == 0) return 1;

    if(exp > 0) return n*exponential(n, exp-1);
    return 1/(n*exponential(n, -exp-1));
}

int MDC(int a, int b){
    if(b == 0) return a;
    return MDC(b, a%b);
}

void permute(string& s, int n){
    if(n <= 0) return;
    cout<<s<<endl;
    swap(s[n], s[n-1]);
    return permute(s, n-1);
}

void string_permutation(string str, int n){
    if(n >= str.size()) return;
    permute(str, str.size()-1);
    return string_permutation(str, n+1);
}

void print_conjunto(vector<int> subset, int n){
    if(n == subset.size()) return;
    cout<<subset[n]<<" ";
    return print_conjunto(subset, ++n);
}

void backtracking(vector<int> vec, vector<int> sub, int n) {
    if(n == vec.size()){
        cout<<"{ ";
        print_conjunto(sub, 0);
        cout<<"} ";

        return;
    } 
    
    backtracking(vec, sub, n+1);
    sub.push_back(vec[n]);
    backtracking(vec, sub, n+1);
}

int binary(vector<int> vec, int target, int left, int right){
    if(left > right) return -1;

    int mid = left+(right-left)/2;

    if(vec[mid] == target) return mid;

    if(vec[mid] < target) return binary(vec, target, mid+1, right);
    else return binary(vec, target, left, mid-1); 
}

int sum_alg(int n){
    if(n == 0) return 0; 

    return n%10 + sum_alg(n/10);
}

void invert_string(string& s, int left, int right){
    if(left >= right) return;

    swap(s[left], s[right]);
    return invert_string(s, ++left, --right);
}

int combinacao(int n, int k){
    return factorial(n)/(factorial(n-k)*factorial(k));
}

bool palyndrome_str(string s, int left, int right){
    if(left >= right) return true;
    if(s[left] != s[right]) return false;
    return palyndrome_str(s, ++left, --right);
}

int main(){
    cout<<exponential(-3,3)<<endl;
    cout<<"--------------"<<endl;
    cout<<MDC(16,8)<<endl;
    cout<<"--------------"<<endl;
    string txt = "aed";
    string_permutation(txt, 0); 
    cout<<"--------------"<<endl;
    vector<int> vec = {1, 2, 3};
    vector<int> aux;
    backtracking(vec, aux, 0);
    cout<<endl;
    cout<<"--------------"<<endl;
    vector<int> v = { 1, 2, 3, 4, 5, 10, 11, 34, 37};
    cout<<binary(v, 4, 0, v.size()-1)<<endl;
    cout<<"--------------"<<endl;
    cout<<sum_alg(123455)<<endl;
    cout<<"--------------"<<endl;
    invert_string(txt, 0, txt.size()-1);
    cout<<txt<<endl;
    cout<<"--------------"<<endl;
    cout<<combinacao(4, 2)<<endl;
    cout<<"--------------"<<endl;
    string s = "araraa";
    cout<<palyndrome_str(s, 0, s.size()-1)<<endl;

    return 0;
}