class Solution {
public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0;
        long long sum = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                return {left + 1, right + 1};
            }
        }

        return {-1};
    }
};