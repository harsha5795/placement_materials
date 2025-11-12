#include <bits/stdc++.h>
using namespace std;


void heapify(int i, int *arr, int size){
    int largest = i;
    
    int left = 2*i+1;
    if(left<size && arr[left]>arr[largest])
      largest =  left;
    int right = 2*i+2;
    if(right<size && arr[right]>arr[largest])
      largest = right;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(largest, arr, size);
    } 
}


void heapsort(int *arr, int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(i, arr, n);
    }
    for(int size=n-1; size>=0; size--){
        swap(arr[0], arr[size]);
        heapify(0, arr, size);
    }
}


void print(int *arr, int n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
       cin >> arr[i];
    heapsort(arr,n);
    print(arr,n);
}