//refer word for better understanding

#include <bits/stdc++.h>
using namespace std;

class Disjointset{
    public:
    vector<int>size;
    vector<int>parent;

    Disjointset(int n){
        size.resize(n+1, 1); 
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
           parent[i] = i;
    }
     
    int findUParent(int node){
        if(parent[node]==node)
           return node;
        return parent[node] = findUParent(parent[node]);  
        //path compression so that avg time complexity is lesser than O(logn)
    }

    void unionBysize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_u == ulp_v)
           return;
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;  //smaller gets attached to larger
            size[ulp_v] = size[ulp_v]+size[ulp_u];
        }
        else if(size[ulp_v]<=size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u]+size[ulp_v];
        }
    }
};

int main(){
    Disjointset ds(10);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(1,4);
    ds.unionBysize(5,6);
    ds.unionBysize(6,7);

    if(ds.findUParent(2)==ds.findUParent(4))
       cout << "2 and 4 belongs to same component" << "\n";
    else 
       cout << "2 and 4 does not belongs to same component" << "\n";
    
    if(ds.findUParent(1)==ds.findUParent(5))
       cout << "1 and 5 belongs to same component" << "\n";
    else 
       cout << "1 and 5 does not belongs to same component" << "\n";
    
}


