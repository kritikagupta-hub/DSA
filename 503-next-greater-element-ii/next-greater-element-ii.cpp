class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>res(n,-1);
        st.push(nums[n-1]);
        for(int i=2*n-1;i>=0;i--){
            int currentNum = nums[i % n];
            while(!st.empty()&& st.top()<=currentNum){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                  res[i]=st.top();  
                }
            }
            st.push(currentNum);
        }
        return res;
    }
};