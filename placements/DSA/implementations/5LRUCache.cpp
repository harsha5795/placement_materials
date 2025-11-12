#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    
    Node(int key, int value){
        this->key = key;
        this->value = value;
    }
};

class LRUCache{
    public:
    Node *head;
    Node *tail;
    int capacity;
    int size;
    unordered_map<int, Node*>mp;  //{key, address}
    
    LRUCache(int cap){
        capacity = cap;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);  //to decrease edge cases
        head->next = tail;  //dont forget these 2 lines
        tail->prev = head;
    }
    
    void deletenode(Node *temp){
        Node *prevnode = temp->prev;
        Node *nextnode = temp->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    
    void addnode(Node *temp){
        Node *prevnode = head;
        Node *nextnode = head->next;
        prevnode->next = temp;
        temp->prev = prevnode;
        temp->next = nextnode;
        nextnode->prev = temp;
    }
    
    int get(int key){
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *temp = mp[key];
        deletenode(temp);
        addnode(temp);
        return temp->value;
    }
    
    void put(int key, int val){
        if(mp.find(key)!=mp.end()){
            Node *temp = mp[key];
            temp->value = val;
            deletenode(temp);
            addnode(temp);
        }
        else{
            if(size<capacity){
                Node *temp = new Node(key, val);
                addnode(temp);
                mp[key] = temp;
                size++;
            }
            else{
                Node *dptr = tail->prev;
                deletenode(dptr);
                mp.erase(dptr->key);
                delete(dptr);
                
                Node *newnode = new Node(key, val);
                addnode(newnode);
                mp[key] = newnode;
            }
        }
    }
};



int main()
{
    LRUCache lrucache(2);
    lrucache.put(1, 1); // cache is {1=1}
    lrucache.put(2, 2); // cache is {1=1, 2=2}
    cout << lrucache.get(1) << "\n";    // return 1
    lrucache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lrucache.get(2) << "\n";    // returns -1 (not found)
    lrucache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lrucache.get(1) << "\n";    // return -1 (not found)
    cout << lrucache.get(3) << "\n";    // return 3
    cout << lrucache.get(4) << "\n";    // return 4
    
}