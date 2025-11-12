#include <bits/stdc++.h>
using namespace std;

//also watch longest completestring,  Number of distinct substrings in striver playlist

class TrieNode{
    public:
    TrieNode* links[26];
    int endswith;
    int prefixcount;

    TrieNode(){
        for(int i=0; i<26; i++){
            links[i] = NULL;
        }
        endswith = 0;
        prefixcount = 1;
    }
};

class Trie{
    public:
    TrieNode *root;

    Trie(){
        root = new TrieNode();
    }

    void insert(const string &s){
        int n = s.size();
        TrieNode* temp = root;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a'] == NULL){
                temp->links[ch-'a'] = new TrieNode();
                temp = temp->links[ch-'a'];
            }
            else{
                temp = temp->links[ch-'a'];
                (temp->prefixcount)++;
            }
        }
        (temp->endswith)++;
    }


    int countwordsequalto(const string &s){
        int n = s.size();
        TrieNode *temp = root;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a']==NULL)
               return 0;
            temp = temp->links[ch-'a'];
        }
        return (temp->endswith);
    }

    int countwordsstartswith(const string &s){
        int n = s.size();
        TrieNode *temp = root;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(temp->links[ch-'a']==NULL)
               return 0;
            temp = temp->links[ch-'a'];
        }
        return (temp->prefixcount);
    }
     
};




int main(){

    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
  
    cout << t.countwordsequalto("apple") << "\n";
    cout << t.countwordsequalto("apps") << "\n";
    cout << t.countwordsequalto("app") << "\n";
    cout << t.countwordsequalto("love") << "\n";
    
    cout << t.countwordsstartswith("app") << "\n";
    cout << t.countwordsstartswith("love") << "\n";
}