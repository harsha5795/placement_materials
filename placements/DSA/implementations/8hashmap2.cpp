#include <bits/stdc++.h>
using namespace std;

//hash value of abc = (31^2)*(1) + (31^1)*(2) + (31^0)*(c)
//i choose 31 because it is a prime


//make sure to write const string &s everywhere
//study rehash properly i.e v.clear(), elements=0

int lamda = 3;

class Node{
    public:
    string s;
    int val;
    Node *next;

    Node(const string &s, int val){
        this->s = s;
        this->val = val;
        this->next = NULL;
    }
};


class hashmap{
    private:
    vector<Node*>v;
    int N;   //size of array
    int elements=0;
    
    public:
    hashmap(int N){
       this->N = N;
       v.resize(N, NULL);
    }
    
    int hashfunction(const string &s){
        int n = s.size();
        int hashvalue = 0;
        for(int i=0; i<n; i++){
            hashvalue = (hashvalue*31 + (s[i]-'a'+1))%N;
        }
        return hashvalue;
    }


    void rehash(){
        vector<Node*> old = v;
        N = 2*N;
        v.clear();
        elements = 0;
        v.resize(N, NULL);
        
        for(auto it : old){
            Node *temp = it;
            while(temp!=NULL){
                insertkey(temp->s, temp->val);
                temp = temp->next;
            }
        }
    }

    
    void insertkey(const string &s, int val){     
        int hashval = hashfunction(s);
        Node *head = v[hashval];
        
        Node *temp = head;
        while(temp!=NULL){
            if(temp->s == s){
                temp->val = val;
                return;
            }
            temp = temp->next;
        }
        
        elements++;
        Node *newnode = new Node(s, val);
        newnode->next = head;
        v[hashval] = newnode;

        if(elements/N>=lamda){
            rehash();
        }
    }
    
    
    int getvalue(const string &s){
        int hashval = hashfunction(s);
        Node *head = v[hashval];
        
        Node *temp = head;
        while(temp!=NULL){
            if(temp->s == s)
               return temp->val;
            temp = temp->next;
        }
        return -1;
    }


    void deletekey(const string &s){
        int hashval = hashfunction(s);
        Node *head = v[hashval];

        if(head==NULL)
            return;
        if(head->s == s){
            v[hashval] = head->next;
            delete head;
            return;
        }

        Node *prev = head;
        Node *curr = head->next;
        while(curr!=NULL){
            if(curr->s == s){
                prev->next = curr->next;
                delete curr;
            }
            prev = curr;
            curr = curr->next;
        }
        
    }


};



int main(){
    hashmap mp(5);  //initial bucket size

    mp.insertkey("harsha", 1);
    mp.insertkey("sreeja", 2);
    mp.insertkey("sreenu", 3);
    mp.insertkey("satya", 4);

    cout << mp.getvalue("satya") << "\n";
    mp.deletekey("satya");
    cout << mp.getvalue("satya") << "\n";
    cout << mp.getvalue("hjvjk") << "\n";

}