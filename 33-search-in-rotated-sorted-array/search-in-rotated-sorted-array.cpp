class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int guess = low + (high - low) / 2;
            if (nums[guess]==target)
                return guess;
            if (nums[low]<=nums[guess]) {
                if (target>=nums[low] && target<nums[guess]) {
                    high=guess - 1;
                } else {
                    low=guess + 1;
                }
            }
            else {
                if (target>nums[guess] && target<=nums[high]) {
                    low=guess + 1;
                }
                else {
                    high=guess - 1;
                }
            }
        }
        return -1;
    }
};