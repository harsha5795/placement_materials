
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

class Queue{
    public:
    Node *front;
    Node *back;
    int size;
    
    Queue(){
        front = NULL;
        back = NULL;
        size = 0;
    }
    
    void push(int x){
        if(size==0){
            Node *temp = new Node(x);
            front = back = temp;
        }
        else{
            Node *temp = new Node(x);
            back->next = temp;
            back = temp;
        }
        size++;
    }
    
    void pop(){
        if(size==0){
            cout << "no element to pop" << "\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        temp->next = NULL;
        free(temp);
        size--;
        if(size==0){
            front = back = NULL;
        }
    }
    
    int return_front(){
        if(size==0){
            return -1;
        }
        return front->data;
    }
};

int main()
{
      Queue q;
      q.push(1);
      q.push(2);
      q.push(3);
      q.pop();
      q.pop();
      q.pop();
      q.pop();
      cout << q.return_front() << "\n";
   
}