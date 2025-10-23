class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0;i<s.length();i++){
            char ch = s[i];

            // if opening h to stack me push krenge
            // if closing bracket h to stack ke top ko check krenge and pop krenge

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                // for closing bracket
                if(!st.empty()){
                    char top = st.top();
                        if((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[') ){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};