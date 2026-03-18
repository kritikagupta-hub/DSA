class Solution {
  public:
  
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &dfsVisited) {
        visited[node] = 1;
        dfsVisited[node] = 1;
        
        for(auto neighbour : adj[node]) {
            
            // if not visited
            if(!visited[neighbour]) {
                if(dfs(neighbour, adj, visited, dfsVisited)) {
                    return true;
                }
            }
            // if already in DFS stack → cycle
            else if(dfsVisited[neighbour]) {
                return true;
            }
        }
        
        dfsVisited[node] = 0; // backtrack
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // create adjacency list
        vector<int> adj[V];
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V, 0);
        vector<int> dfsVisited(V, 0);
        
        // handle disconnected graph
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, dfsVisited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};