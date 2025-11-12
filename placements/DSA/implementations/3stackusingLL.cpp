#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public:
    int size;
    Node *top;
    
    Stack(){
        size = 0;
        top = NULL;
    }
    
    void push(int x){
        if(size==0){
            top = new Node(x);
        }
        else{
            Node *temp = new Node(x);
            temp->next = top;
            top = temp;
        }
        size++;
    }
    
    void pop(){
        if(size==0){
            cout << "no element to pop" << "\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
        size--;
    }
    
    int return_top(){
        if(size==0){
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.pop();
    s.pop();
    s.pop();
    cout << s.return_top();

}