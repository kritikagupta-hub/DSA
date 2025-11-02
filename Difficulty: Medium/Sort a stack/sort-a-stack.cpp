class Solution {
  public:
    void(sortInsert(stack<int> &st,int num)){
        if(st.empty() || (!st.empty() && st.top() < num)){
            st.push(num);
            return;
        }
        int n = st.top();
        st.pop();
        
        sortInsert(st,num);
        
        st.push(n);
    }
    
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();
        
        sortStack(st);
        
        sortInsert(st,num);
        
    }
};
