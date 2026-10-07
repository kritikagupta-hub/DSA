class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                if(st.size()>1){
                    ans+='(';
                }
            }
            else{
                if(st.size()>=2){
                    ans+=')';
                }
                st.pop();
            }
        }
        return ans;
    }
};