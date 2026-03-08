class Solution {
  public:
  // 
    /*vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> ans;
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                ans.push_back(mat[i][j]);  
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }*/
    // approch 2 
    //by using min heap then pushing first element into a min heap off all 
    //then finding a minimum elemnt of all array and pusing it into heap
    vector<int> mergeArrays(vector<vector<int>> &arr) {
        
        int K = arr.size();
        vector<int> ans;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // push first element of each array
        for(int i = 0; i < K; i++){
            pq.push({arr[i][0], {i, 0}});
        }

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int value = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            ans.push_back(value);

            if(col + 1 < arr[row].size()){
                pq.push({arr[row][col + 1], {row, col + 1}});
            }
        }

        return ans;
    }

};
