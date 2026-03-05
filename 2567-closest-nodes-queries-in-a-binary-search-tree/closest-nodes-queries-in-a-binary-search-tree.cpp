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
    void solve(TreeNode* root,vector<int>&temp){
        if(!root) return;

        solve(root->left,temp);
        temp.push_back(root->val);
        solve(root->right,temp);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        vector<vector<int>>ans;
        vector<int>temp;

        solve(root,temp);

        for(int &q:queries){
            auto x=lower_bound(begin(temp),end(temp),q);
            auto y=upper_bound(begin(temp),end(temp),q);

            int minVal=-1,maxVal=-1;

            if(x!=temp.end()) maxVal=*x;

            if(x!=temp.end() && *x==q) minVal=maxVal;
            else if(x!=temp.begin()) minVal=*(prev(x));

            ans.push_back({minVal,maxVal});
        }
        return ans;
    }
};