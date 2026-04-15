// User function Template for C++
//Back-end complete function Template for C++
class Solution {
  public:
    vector<int> zigZagMatrix(vector<vector<int>> &mat) {
        // Your code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int>res;
        
        for(int i=0;i<m+n-1;i++){
            vector<int>temp;
            int r,c;
            if(i<m){
                r=0;
                c=i;
            }
            else{
                r=i-m+1;
                c=m-1;
            }
            while(r<n && c>=0){
                temp.push_back(mat[r][c]);
                r++;
                c--;
            }
            if(i%2==0){
                reverse(temp.begin(),temp.end());
            }
            for(int j=0;j<temp.size();j++){
                res.push_back(temp[j]);
            }
        }
        return res;
        
    }
};