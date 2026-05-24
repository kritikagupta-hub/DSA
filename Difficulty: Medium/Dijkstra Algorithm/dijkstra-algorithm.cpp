class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,list<pair<int,int>>> adj;
        
        for(int i=0; i<edges.size() ;i++){
            int u =edges[i][0];
            int v= edges[i][1];
            int w= edges[i][2];
            
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        vector<int> dist(V, INT_MAX);
        
        // set 
        
        set<pair<int,int> > st;
        dist[src] = 0;
        st.insert(make_pair(0,src));
        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDist = top.first;
            int topNode=top.second;
            
            //remove
            st.erase(st.begin());
            
            for(auto neighbour:adj[topNode]){
                if(nodeDist + neighbour.second < dist[neighbour.first]){
                    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                    //if record found tyhen erase
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    dist[neighbour.first]=nodeDist + neighbour.second;
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                     
                }
            }
        }
        return dist;
        
    }
};