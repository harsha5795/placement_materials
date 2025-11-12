#include <bits/stdc++.h>
using namespace std;

class Queue{
    
    public:
    int capacity;
    int size;
    int *arr;
    int front; 
    int back;
    
    
    Queue(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        front = -1;
        back = -1;
    }
    
    void push(int el){
        if(size==capacity){
            cout << "no space to push " << el << "\n";
            return;
        }
        if(size==0){
            front = 0;
            back = 0;
            arr[back] = el;
        }
        else{
            back = (back+1)%capacity;
            arr[back] = el;
        }
        size++;
    }
    
    void pop(){
        if(size==0){
            cout << "no element to pop" << "\n";
            return;
        }
        front = (front+1)%capacity;
        size--;
        if(size==0){
            front = -1;
            back = -1;
        }
    }
    
    int front_element(){
        if(size==0){
            return -1;
        }
        return arr[front];
    }
    
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    q.pop();
    q.push(7);
    cout << q.front_element();
    
}