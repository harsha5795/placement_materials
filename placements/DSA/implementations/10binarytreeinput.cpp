#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node *root){
    if(root==NULL)
      return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* constructtree(int *a, int n){
    Node *root = new Node(a[0]);
    queue <Node*> q;
    q.push(root);
    int ptr=1;

    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        
        if(node==NULL)
           continue;
        
        if(a[ptr]==-1)
          node->left = NULL;
        else
          node->left = new Node(a[ptr]);  //add constrain ptr<n if needed
        ptr++;

        if(a[ptr]==-1)
          node->right = NULL;
        else
          node->right = new Node(a[ptr]);
        ptr++;

        q.push(node->left);
        q.push(node->right);
    }
    return root;

}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
      cin >> a[i];
    Node *root = constructtree(a, n);
    preorder(root);
    // ex inputs:
    // 11
    // 3 9 20 -1 -1 15 7 -1 -1 -1 -1
    // 17
    // 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 10 11 -1 -1 -1
}