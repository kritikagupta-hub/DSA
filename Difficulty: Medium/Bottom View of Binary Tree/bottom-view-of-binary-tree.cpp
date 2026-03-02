/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        if(root == NULL) return {};
        
        map<int,int> mp;
        queue<pair<Node*,int>> pq;
        
        pq.push({root,0});
        
        while(!pq.empty()){
            
            Node* Current = pq.front().first;
            int axes = pq.front().second;
            pq.pop();
            
            mp[axes] = Current->data;
            
            if(Current->left)
                pq.push({Current->left, axes-1});
            
            if(Current->right)
                pq.push({Current->right, axes+1});
        }
        
        vector<int> ans;
        
        for(auto it : mp)
            ans.push_back(it.second);
        
        return ans;
    }
};