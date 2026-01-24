#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());

        int start = 0, end = numbers.size() - 1;
        int maxPair = 0;

        while (start < end) {
            int pairSum = numbers[start] + numbers[end];
            maxPair = max(maxPair, pairSum);
            start++;
            end--;
        }

        return maxPair;
    }
};

// Example usage:
// vector<int> nums = {3,5,2,3};
// Solution sol;
// cout << sol.minPairSum(nums) << endl;  // Output: 7