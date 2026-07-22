class Solution {
public:

    bool canPlace(vector<int>& arr, int k, int dist) {
        int cows = 1;
        int lastPosition = arr[0]; 

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPosition >= dist) {
                
                cows++;
                lastPosition = arr[i];
            }
            if (cows >= k) {
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 1;
        int high = arr.back() - arr.front();

        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(arr, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};