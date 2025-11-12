#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    int *harr;
    int size;
    int cap;

    MinHeap(int capacity){
        cap = capacity;
        size = 0;
        harr = new int[cap];
    }
    
    void decreasekey(int i){
        int par = (i-1)/2;
        while(i>0 && harr[par]>harr[i]){
            swap(harr[par], harr[i]);
            i = par;
            par = (i-1)/2;
        }
    }

    void insertKey(int el){
        if(size==cap){
            cout << "no space to insert" << "\n";
            return;
        }
        harr[size] = el;
        size++;
        decreasekey(size);
    }
    
    void minheapify(int ind){
        int smallest = ind;
        int left = 2*ind+1;
        if(left<size && harr[left]<harr[smallest])
           smallest = left;
        int right = 2*ind+2;
        if(right<size && harr[right]<harr[smallest])
           smallest = right;
        
        if(smallest!=ind){
            swap(harr[ind], harr[smallest]);
            minheapify(smallest);
        }
    }

    int extractMin(){
        int mini = harr[0];
        harr[0] = harr[size-1];
        size--;
        minheapify(0);
        return mini;
    }
    
    void deleteKey(int ind){
        if(size==0){
            cout << "no element to delete" << "\n";
            return;
        }
        harr[ind] = INT_MIN;
        decreasekey(ind);
        extractMin();
    }
    
};


int main(){
   MinHeap pq(10);
   pq.insertKey(4);
   pq.insertKey(2);
   cout << pq.extractMin() << "\n";
   pq.insertKey(6);
   pq.deleteKey(0);
   cout << pq.extractMin() << "\n";
   cout << pq.extractMin() << "\n";
}