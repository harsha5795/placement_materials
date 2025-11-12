#define ll long long
//p[i] --> using this i as centre we can have a palindrome, this p[i]
//         is the length from centre to an end in the palindrome 

class Solution {
public:
    string longestPalindrome(string s) {
        ll n = s.size();
        string t;
        for(ll i=0; i<2*n+1; i++){
            if(i%2==0) t.push_back('#');
            else t.push_back(s[(i-1)/2]);
        }
        vector<ll>p(2*n+1, 1);


        ll l=0,r=0;
        for(ll i=0; i<2*n+1; i++){
           if(r<i){
              l = r = i;
           } 
           p[i] = min(p[l+r-i], r-i+1);
           ll len = p[i];
           while(i+len<2*n+1 && i-len>=0 && t[i+len]==t[i-len]){
              len++;
              p[i]++;
           }
           if(i+p[i]-1>r){
              l = i-p[i]+1;
              r = i+p[i]-1;
           }
        }
        

        ll ans=1, centre=0;
        for(ll i=0; i<2*n+1; i++){
            if(p[i]-1>ans){
                centre = i;
                ans = p[i]-1;
            }
        }
        return s.substr((centre-ans)/2, ans);

    }
};