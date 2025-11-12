//binary tree diameter hackerearth
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

int depth(Node *root, int &diameter){
    if(root==NULL)
       return 0;
    int ldepth = depth(root->left, diameter);
    int rdepth = depth(root->right, diameter);
    diameter = max(diameter, 1 + ldepth + rdepth);
    return 1 + max(ldepth,rdepth);
}

int main() {
    int n, x;
    cin >> n >> x;
    
    int k=n-1;
    vector<pair<string, int>>V;
    while(k--){
        string str;
        cin >> str;
        int val;
        cin >> val;
        V.push_back({str, val});
    }
    sort(V.begin(), V.end());
    

    Node *root = new Node(x);
    for(int p=0; p<n-1; p++){
        string str = V[p].first;
        int val = V[p].second;
        int l=str.size();
        int i=0;
        Node *ptr = root;

        for(i=0; i<=l-2; i++){
            if(str[i]=='L')
              ptr = ptr->left;
            else 
              ptr = ptr->right;
        }
        if(str[i]=='L')
          ptr->left = new Node(val);
        else 
          ptr->right = new Node(val);
    }
    
    int diameter=0;
    depth(root, diameter);
    cout << diameter;
    // 5 1  no of nodes,  root value
    // L
    // 2
    // R
    // 3
    // LL
    // 4
    // LR
    // 5
}