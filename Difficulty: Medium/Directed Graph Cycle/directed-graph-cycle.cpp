class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        //find all indegeree
        vector<int> indegree(V,0);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        
        //0 will push into quque;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
        
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
        }
        if(count==V){
            return false;
        }
        else{
            return true;
        }
        
    }
};