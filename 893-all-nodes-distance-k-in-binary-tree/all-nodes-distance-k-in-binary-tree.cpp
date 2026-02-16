/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void createParentMapping(TreeNode* root,
                             unordered_map<TreeNode*, TreeNode*> &nodeToParent) {
        
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            if(front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        createParentMapping(root, nodeToParent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        int currLevel = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            
            if(currLevel == k) break;
            
            currLevel++;
            
            for(int i = 0; i < size; i++) {
                
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                }
                
                if(front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};
