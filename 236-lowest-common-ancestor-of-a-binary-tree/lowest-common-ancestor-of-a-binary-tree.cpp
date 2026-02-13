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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL) {
            return NULL;
        }
        
        // If current node is either p or q
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
        // If both sides return non-null, this is LCA
        if (leftAns != NULL && rightAns != NULL) {
            return root;
        }
        
        // Otherwise return the non-null side
        if (leftAns != NULL) {
            return leftAns;
        }
        
        return rightAns;
    }
};
