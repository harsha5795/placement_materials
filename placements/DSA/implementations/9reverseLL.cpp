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

Node* reverse(Node *head){
    Node *curr = head;
    Node *next = head;
    Node *prev = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printLL(Node *temp){
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    int n;
    cin >> n; 
    int arr[n];
    for(int i=0; i<n; i++)
      cin >> arr[i];
    
    Node *head = new Node(-1);
    Node *tail = head;
    for(int i=0; i<n; i++){
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    head = head->next;

    head = reverse(head);
    printLL(head);
}