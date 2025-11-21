class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> a;
        for(int i =0;i<nums.size();i++){
            int val = nums[i];
            // sliding window concept 
            // if jo val h vo already map m h that means duplicate h to true return hoga and phir check hoga ki kya range choti ho gai k se agr choti ho gai to oviously duplicate h usme return true 
            if( a.find(val) != a.end() && i-a[val] <= k){
                return true;
            }
            // agr nhi h to uss value ko map m dall do
            a[val] = i;
        }
        return false;
    }
};