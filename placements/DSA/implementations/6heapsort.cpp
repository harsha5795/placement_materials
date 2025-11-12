
#include <bits/stdc++.h>
using namespace std;

void maxheapify(int i, int *arr, int n){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]>arr[largest])
       largest = left;
    if(right<n && arr[right]>arr[largest])
       largest = right;
       
    if(largest != i){
        swap(arr[i], arr[largest]);
        maxheapify(largest, arr, n);
    }
}


void heapsort(int *arr, int n){
    
    //building max heap (Time Complexity = O(n))
    for(int i=n/2-1; i>=0; i--)
       maxheapify(i, arr, n);
       
    for(int size=n-1; size>=0; size--){
        swap(arr[0], arr[size]);
        maxheapify(0, arr, size);
    }
}

void print(int *arr, int n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
      cin >> arr[i];
    
    heapsort(arr, n);
    print(arr, n);
}