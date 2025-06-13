#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>


using namespace std;

void hanoi(int n, char ori, char dest, char aux){
    if(n==1){
        cout<<"mover um disco de "<<ori<<" para "<<dest<<endl;
        return;
    }

    hanoi(n-1, ori, aux, dest);
    cout<<"mover disco"<<n<<" de "<<ori<<" para "<<dest<<endl;
    hanoi(n-1, aux, dest, ori); 
}

int main(){
    int n = 3;
    hanoi(n,'A', 'B', 'C');

    return 0;
}
