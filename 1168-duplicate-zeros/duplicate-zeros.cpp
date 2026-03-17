class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        // Traverse the array from left to right
        for(int i=0; i<n; i++) {

            // If current element is zero, we need to duplicate it
            if(arr[i]==0){

                // Shift all elements one position to the right
                // Start from the end to avoid overwriting values
                for(int j=n-1;j>i;j--){
                    arr[j] = arr[j-1];
                }

                // Skip the next index because the zero is duplicated
                i++;
            }
        }
    }
};