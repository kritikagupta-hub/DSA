class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        for(int i=0;i<s.size();i++){
            char ch =s[i];
            if(ch== '[')
                open++;
            else if(open>0)
                open--;
            
        }
        return (open+1)/2;
    }
};