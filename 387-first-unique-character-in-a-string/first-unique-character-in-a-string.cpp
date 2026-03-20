class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0; i<s.size();i++){
            if(freq[s[i] - 'a'] == 1){
                return i;
        }
    }
        return -1;
        /*for(int i=0;i<s.size();i++){
            int c =0;
            for(int j =0;j<s.size();j++){
                if(s[i]==s[j]){
                    c++;
                }
            }
            if(c==1){
                return i;
            }
        }
        return -1;
        */
        

    }
};