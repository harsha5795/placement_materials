
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int capacity;
    int size;
    int *arr;
    int top;
    
    Stack(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        top = -1;
    }
    
    void push(int el){
        if(size==capacity){
            cout << "no space to push";
            return;
        }
        top++;
        arr[top] = el;
        size++;
    }
    
    void pop(){
        if(size==0){
            cout << "no element to pop";
            return;
        }
        top--;
        size--;
    }
    
    int return_top(){
        if(size==0){
            return -1;
        }
        return arr[top];
    }
};


int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.return_top() << "\n";
}