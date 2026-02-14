/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode* root, long long currSum, int targetSum,
               unordered_map<long long,int> &mp, int &count) {
        
        if(root == NULL) return;
        
        currSum += root->val;   // now safe
        
        if(currSum == targetSum) 
            count++;
        
        if(mp.find(currSum - targetSum) != mp.end()) {
            count += mp[currSum - targetSum];
        }
        
        mp[currSum]++;
        
        solve(root->left, currSum, targetSum, mp, count);
        solve(root->right, currSum, targetSum, mp, count);
        
        mp[currSum]--;   // backtrack
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        int count = 0;
        solve(root, 0LL, targetSum, mp, count);
        return count;
    }
};

