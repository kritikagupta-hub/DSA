class Solution {
    private:
        vector<int> topo(int N, vector<vector<int>> &adj) {
            queue<int> q; 
    	    vector<int> indegree(N, 0); 
    	    for(int i = 0;i<N;i++) {
    	        for(auto it: adj[i]) {
    	            indegree[it]++; 
    	        }
    	    }
    	    
    	    for(int i = 0;i<N;i++) {
    	        if(indegree[i] == 0) {
    	            q.push(i); 
    	        }
    	    }
    	    vector<int> topo;
    	    while(!q.empty()) {
    	        int node = q.front(); 
    	        q.pop(); 
    	        topo.push_back(node);
    	        for(auto it : adj[node]) {
    	            indegree[it]--;
    	            if(indegree[it] == 0) {
    	                q.push(it); 
    	            }
    	        }
    	    }
    	    return topo;
    	}
    
    
    
  public:
    string findOrder(vector<string> &words) {
        // code here
        set<char> st;
        
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++){
                st.insert(words[i][j]);
            }
        }
        
        map<char, int> charToInt;
        map<int, char> intToChar;
        
        int count=0;
        for(auto it=st.begin(); it!= st.end(); it++){
            charToInt.insert({*it, count});
            intToChar.insert({count, *it});
            count++;
        }
        
        int V = charToInt.size();
        
        vector<vector<int>> adj(V);
        
        for(int i=0; i<words.size()-1; i++){
            string s1= words[i];
            string s2 = words[i+1];
            
            int len = min(s1.size(), s2.size());
            
            for(int j=0; j<len; j++){
                if(s1[j]!=s2[j]){
                    adj[charToInt[s1[j]]].push_back(charToInt[s2[j]]);
                    break;
                }
                
                if(j==len-1 && s1.size()>s2.size())
                    return "";
            }
            
        }
        
        vector<int> ans = topo(V,adj);
        
        string temp ="";
        for(int i=0; i<ans.size(); i++){
            char c = intToChar[ans[i]];
            temp += c;
        }
        
        if(ans.size()==V)
            return temp;
        
        return "";
        
        
        
    }
};