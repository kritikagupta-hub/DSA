class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,0,temp,ans);
        return ans;
    }
    void solve(vector<int> nums,int index, vector<int> &temp,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        //including the no.
        temp.push_back(nums[index]);
        solve(nums,index+1,temp,ans);
        temp.pop_back();

        //excluding the no.
        solve(nums,index+1,temp,ans);
    }
};