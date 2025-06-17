#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

using namespace std;

float exponential(int n, int exp){
    if(exp == 0) return 1;

    return n*exponential(n, exp-1);
}

int MDC(int a, int b){
    
}

int main(){
    cout<<exponential(3,3)<<endl;

    return 0;
}