class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // Push operators and '('
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            }
            else if (ch == ')') {
                bool isRedundant = true;

                // Check if there’s any operator inside the brackets
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        isRedundant = false;
                    st.pop();
                }

                // Pop the opening '('
                if (!st.empty()) st.pop();

                // If redundant, return true
                if (isRedundant) return true;
            }
        }
        return false;
    }
};


