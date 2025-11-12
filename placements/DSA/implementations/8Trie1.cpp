#include <bits/stdc++.h>
using namespace std;

//each node will have 1 parent
//So each node is defined by its parent's alphabet which was pointing it
//for easy insertion just think that we are inserting "a"
class TrieNode{
    public:
    TrieNode* links[26];
    bool isend;

    TrieNode(){
        for(int i=0; i<26; i++)
            links[i] = NULL;
        isend = false;
    }
};


class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(const string &s){
        int n = s.size();
        TrieNode *temp = root;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a'] == NULL){
                temp->links[ch-'a'] = new TrieNode();
                temp = temp->links[ch-'a'];
            }
            else{
                temp = temp->links[ch-'a'];
            }
        }
        temp->isend = true;
    }


    bool search(const string &s){
        int n = s.size();
        TrieNode *temp = root;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a']==NULL)
                return false;
            temp = temp->links[ch-'a'];
        }    
        return (temp->isend);
    }


    bool isprefix(const string &s){
        int n = s.size();
        TrieNode *temp = root;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a'] == NULL)
                return false;
            temp = temp->links[ch-'a'];
        }
        return true;
    }

};


int main(){

    Trie t;
    t.insert("apple");
    t.insert("apps");
    t.insert("apxl");
    t.insert("bac");
    t.insert("bat");

    cout << t.search("apps") << "\n";
    cout << t.search("apx") << "\n";
    cout << t.search("bac") << "\n";
    cout << t.search("ball") << "\n";
    
    cout << t.isprefix("ap") << "\n";
    cout << t.isprefix("jnhbgbjk") << "\n";

}