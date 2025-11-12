#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


class BST{
    public:
    TreeNode *root;

    BST(){
        this->root = NULL;
    }


    void traverse(TreeNode *root){
        if(root==NULL)
           return;
        traverse(root->left);
        cout << root->val << " ";
        traverse(root->right);
    }
    void print(){
        traverse(root);
    }


    void insert(int key){
        if(root==NULL){
            root = new TreeNode(key);
            return;
        }

        TreeNode *curr = root;
        TreeNode *prev = NULL;
        while(curr!=NULL){
            prev = curr;
            if(curr->val < key)
              curr = curr->right;
            else 
              curr = curr->left;
        }
        
        if(prev->val < key)
           prev->right = new TreeNode(key);
        else
           prev->left = new TreeNode(key);
    }
    
    
    int getmin(TreeNode* root){
        TreeNode* curr = root;
        while(curr->left!=NULL)
           curr = curr->left;
        return curr->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==NULL)
           return NULL;
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }
        else{
            //only 1 child
            if(root->left==NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else{ //2 child 
                int rightmin = getmin(root->right);
                root->val = rightmin;
                root->right = deleteNode(root->right, rightmin);
                return root;
            }
        }
        return root;//for formality
    }

    void deletekey(int key){
        root = deleteNode(root, key);
    }
};

int main(){

    BST bst;
    bst.insert(6);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(8);
    bst.insert(1);
    bst.insert(9);
    bst.deletekey(6);
    bst.deletekey(8);

    bst.print();
}