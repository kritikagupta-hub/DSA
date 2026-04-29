class Solution {
public:
    char findTheDifference(string s, string t) {
       int count1 = 0;
       int count2 = 0;
       for(int i=0;i<s.size();i++){
         count1 += s[i]-'a';
       }     
        for(int i=0;i<t.size();i++){
         count2 += t[i]-'a';
       }   

       return 'a' + (count2-count1);
    }
};