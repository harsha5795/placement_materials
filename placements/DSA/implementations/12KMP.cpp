#include <bits/stdc++.h>
using namespace std;


    
void kmp(string &S, string &pat, vector<int>&ind){
    int n1 = S.size();
    int n2 = pat.size();

    vector<int>longest_PS(n2);
    longest_PS[0] = 0;
    for(int i=1; i<n2; i++){
        int ind = longest_PS[i-1];
        while(ind>0 && pat[ind]!=pat[i]){
            ind = longest_PS[ind-1];
        }
        if(pat[ind]==pat[i])
           longest_PS[i] = ind+1;
        else 
           longest_PS[i] = 0;
    }

    int ptr1=0, ptr2=0;
    for(ptr1=0; ptr1<n1; ptr1++){
        if(ptr2==n2 || S[ptr1]!=pat[ptr2]){
            while(ptr2>0 && S[ptr1]!=pat[ptr2]){
                ptr2 = longest_PS[ptr2-1];
            }
        }
        if(S[ptr1]==pat[ptr2])
            ptr2++;
        if(ptr2==n2){
            ind.push_back(ptr1);
        }
    }
}


int main(){
    string S, pat;
    cin >> S >> pat;
    vector<int>ind;
    kmp(S, pat, ind);
    
    for(auto it : ind)
      cout << it << " ";
}