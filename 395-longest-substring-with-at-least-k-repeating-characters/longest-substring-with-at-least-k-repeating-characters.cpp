class Solution {
public:
    int String(string s, int k){
        if(s.size()<k){
            return 0;
        }
        unordered_map<char,int>f;
        for(char ch:s){
            f[ch]++;
        }
        //for invalid char
        for(int i=0;i<s.size();i++){
            if(f[s[i]]<k){
                int left=String(s.substr(0,i),k);
                int right=String(s.substr(i+1),k);
                return max(left,right);
            }
        }
        return s.size();
    }
    int longestSubstring(string s, int k) {
        return String(s,k);
    }
};