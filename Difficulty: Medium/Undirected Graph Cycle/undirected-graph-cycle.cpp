class Solution {
  public:

    bool bfsCheck(int src, vector<bool> &visited, vector<vector<int>> &adj) {
        
        vector<int> parent(adj.size(), -1);
        queue<int> q;
        
        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto neighbour : adj[front]) {
                
                if(visited[neighbour] && neighbour != parent[front]) {
                    return true;
                }
                
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // STEP 1: Convert edge list → adjacency list
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        //  STEP 2: Normal BFS cycle detection
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfsCheck(i, visited, adj)) {
                    return true;
                }
            }
        }

        return false;
    }
};