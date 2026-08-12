class Solution {
  public:
    int getCount(string s, int k) {
        // code here
        map<char,int>frq;
        for(int i=0;i<s.length();i++){
            if(i==0 || s[i]!=s[i-1]){
                frq[s[i]]++;
            }
        }
        int ans=0;
        for(auto x:frq){
            if(x.second == k){
                ans++;
            }
        }
        return ans;
    }
};