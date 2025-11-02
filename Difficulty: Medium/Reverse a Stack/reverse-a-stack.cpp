class Solution {
  public:
    void insertAtBottom(stack<int> &st,int element){
        // if empty then push the element
        if(st.empty()){
            st.push(element);
            return ;
        }
        // pop the top element and store in num
        int num = st.top();
        st.pop();
        
        // recursive call
        insertAtBottom(st,element);
        
        st.push(num);
    }
    void reverseStack(stack<int> &st) {
        // code 
        // if empty then return 
        if(st.empty()){
            return ;
        }
        //store top element in num and pop
        int num = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st,num);
    }
};