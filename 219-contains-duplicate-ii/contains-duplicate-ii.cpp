class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> a;
        for(int i =0;i<nums.size();i++){
            int val = nums[i];
            if( a.find(val) != a.end() && i-a[val] <= k){
                return true;
            }
            a[val] = i;
        }
        return false;
    }
};