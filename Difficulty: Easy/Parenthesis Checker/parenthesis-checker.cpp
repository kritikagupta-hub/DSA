class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;

        for (char c : s) {
            // Opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else { // Closing brackets
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};