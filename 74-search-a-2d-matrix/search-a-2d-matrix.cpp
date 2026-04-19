class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;

        while(i<n && j>=0){
            if(matrix[i][j]  == target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;*/
        int row=matrix.size();
        int col=matrix[0].size();
        int start = 0;
        int end = (row*col)-1;
        int mid= start + (end-start)/2;

        while(start<=end){
            int element = matrix[mid/col][mid%col];
            if(element==target){
                return true;
            }
            else if(element<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid= start + (end-start)/2;
        }
        return 0;
    }
};