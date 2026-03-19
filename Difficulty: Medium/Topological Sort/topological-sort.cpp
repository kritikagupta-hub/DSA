class Solution {
public:
    void tpSort(int node, vector<bool> &visited, stack<int> &s,
                unordered_map<int, list<int>> &adj) {
        
        visited[node] = true;
        
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                tpSort(neighbour, visited, s, adj);
            }
        }
        
        s.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        
        int e = edges.size();  // alculate here
        
        // create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, false);
        stack<int> s;

        // call DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                tpSort(i, visited, s, adj);
            }
        }

        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};