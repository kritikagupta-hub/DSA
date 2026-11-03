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
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* solve(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int pos = mp[rootVal];
        root->left = solve(preorder, start, pos - 1);
        root->right = solve(preorder, pos + 1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        preIndex = 0;
        return solve(preorder, 0, inorder.size() - 1);
    }
};
