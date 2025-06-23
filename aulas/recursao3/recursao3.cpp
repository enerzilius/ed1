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
    return 1/(n*exponential(n, exp*(-1)-1));
}

int MDC(int a, int b){
    if(b == 0) return a;
    return MDC(b, a%b);
}

// void string_permutations(string str, int sub_len, int pos){
//     // if(pos == str.length()-1) return;
//     // for (int i = 0; i < str.length()-1; i++)
//     // {
//     //     for (int j = i; i < str.length()-1; i++)
//     //     {
//     //         swap(str[j], str[j+1]);
//     //     }
//     // }
// }

void backtracking(vector<int> vec) {
    int offset = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i; j < vec.size() - offset; j++) {
            for (int k = 0; k <= offset; k++) {
                cout << vec[j + k] << " ";
            }
            cout << endl; 
        }
        offset += 1;
    }
}


int main(){
    cout<<exponential(3,-3)<<endl;
    cout<<MDC(16,8)<<endl;
    string txt = "aaa";
    // string_permutations(txt, 0, 0); 
    vector<int> vec = {1, 2, 3};
    backtracking(vec);

    return 0;
}