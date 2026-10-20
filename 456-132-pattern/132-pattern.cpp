class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n= nums.size();
        stack<int>st;
        int sec = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<sec){
                return true;
            }
            while(!st.empty()&& nums[i]>st.top()){
                sec=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};