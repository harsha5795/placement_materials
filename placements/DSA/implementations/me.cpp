#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string str = "";
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
                if(s[i] == mp[s[i]]){
                    str = str+s[i];
                    count++;
                }
                else{
                    str = "";
                    count = 0;
                }
            if(count==2) break;
        }
       cout<<str<<endl;
    }
}