class Solution {
  public:
  // dfs traversal of node
     void dfsHelper(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &ans){
     //mark visited as true if node is visited after traversal
        visited[node]=1;
        //pushing visited node in ans
        ans.push_back(node);
        // if not visited then dfs call will done
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        //making visited array
        vector<int> visited(V,0);
        vector<int> ans;
        dfsHelper(0,adj,visited, ans);
        return ans;
        
    }
};