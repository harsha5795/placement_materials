
#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    int *harr;
    int size;
    int capacity;
    
    MinHeap(int cap){
        size = 0;
        capacity = cap;
        harr = new int[capacity];
    }
    
    void decreasekey(int ind, int *harr){
        int par = (ind-1)/2;
        while(par>=0 && harr[par]>harr[ind]){
            swap(harr[par], harr[ind]);
            ind = par;
            par = (par-1)/2;
        }
    }
    
    void minHeapify(int i, int *harr, int size){
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<size && harr[left]<harr[smallest])
           smallest = left;
        if(right<size && harr[right]<harr[smallest])
           smallest = right;
        if(smallest!=i){
            swap(harr[i], harr[smallest]);
            minHeapify(smallest, harr, size);
        }
    }
    
    void insertKey(int key){
        if(size==capacity){
            cout << "no space to insert" << "\n";
            return;
        }
        harr[size] = key;
        size++;
        decreasekey(size-1, harr);
    }
    
    void deleteKey(int ind){
        if(size==0){
            cout << "no element to delete" << "\n";
            return;
        }
        harr[ind] = INT_MIN;
        decreasekey(ind, harr);
        extractMin();
    }
    
    int extractMin(){
        if(size==0)
          return -1;
        int el = harr[0];
        harr[0] = harr[size-1];
        size--;
        minHeapify(0, harr, size);
        return el;
    }
    
    int printMin(){
        if(size==0)
          return -1;
        return harr[0];
    }
};



int main()
{
   MinHeap minheap(10);
   minheap.insertKey(4);
   minheap.insertKey(2);
   cout << minheap.extractMin() << "\n";
   minheap.insertKey(6);
   minheap.deleteKey(0);
   cout << minheap.extractMin() << "\n";
   cout << minheap.extractMin() << "\n";
      
}