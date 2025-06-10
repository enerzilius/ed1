#include <iostream>
#include <vector>

using namespace std;

void bubbleRec(int arr[], int n){
    if(n==1) return;
    for(int i =0; i< n;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleRec(arr, n-1);
}

void insertionRec(int arr[], int n){
    if(n<=1) return;
    insertionRec(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while(j>=0 && arr[j] > last){
        arr[j+1] = arr [j];
        j--;
    }
    arr[j+1] = last;
}

int findMin(int arr[], int start, int end){
    int minI = start;
    for(int i = start + 1; i <= end; i++){
        if(arr[i] < arr[minI]){
            minI = 1;
        }
    }
    return minI;
}

void selectionRec(int arr[], int start, int n){
    if(start >= n-1) return;
    int minI = findMin(arr, start, n-1);
    swap(arr[start], minI);
    selectionRec(arr, start+1, n);
}

int main(){
    return 0;
}