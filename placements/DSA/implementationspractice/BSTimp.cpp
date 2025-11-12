#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};


class BST{
    public:
    Node *root;

    BST(){
        root = NULL;
    }

    void insertnode(int key){
        if(root==NULL){
            Node *newnode = new Node(key);
            root = newnode;
        }

        Node *prev = root;
        Node *curr = root;
        while(curr!=NULL){
            prev = curr;
            if(key < curr->key)
              curr = curr->left;
            else
              curr = curr->right; 
        }

        if(key < prev->key)
          prev->left = new Node(key);
        else
          prev->right = new Node(key); 
    }
    

    int getrightmini(Node *root){
        Node *curr = root->right;
        while(curr->left!=NULL){
           curr = curr->left;
        }
        return curr->key;
    }


    Node* deletenodehelper(Node *root, int key){
        if(root==NULL)
           return NULL;
        
        if(key<root->key){
            root->left = deletenodehelper(root->left, key);
            return root;
        }
        else if(key>root->key){
            root->right = deletenodehelper(root->right, key);
            return root;
        }
        else{
            if(root->left==NULL){
                Node *curr = root->right;
                delete root;
                return curr;
            }
            else if(root->right==NULL){
                Node *curr = root->left;
                delete root;
                return curr;
            }
            else{
                int rightmini = getrightmini(root);
                root->key = rightmini;
                root->right = deletenodehelper(root->right, rightmini);
                return root;
            }
        }
        return root;//for formality
    }


    void deletenode(int key){
        deletenodehelper(root, key);
    }
};



int main(){
    BST bst;
    bst.insertnode(6);
    bst.insertnode(3);
    bst.insertnode(7);
    bst.insertnode(2);
    bst.insertnode(8);
    bst.insertnode(1);
    bst.insertnode(9);
    bst.deletenode(6);
    bst.deletenode(8);

}