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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;  // base case
        // curr no. m jb ek digit aur ayegi to multipy by 10 krna pdega digit add krne k liye to curr ko multipy kia 10 se uske bad usme add kr di node val .
        current = current * 10 + node->val;

        // If it's a leaf node, return the number formed so far
        if (!node->left && !node->right)
            return current;

        // Otherwise, keep traversing
        return dfs(node->left, current) + dfs(node->right, current);
    }
};
