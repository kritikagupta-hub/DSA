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
    pair<bool,int> isBalancedFast(TreeNode* root){
        if(root == NULL){
            return make_pair(true, 0);
        }

        auto left  = isBalancedFast(root->left);
        auto right = isBalancedFast(root->right);

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        ans.first  = left.first && right.first && diff;

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};

