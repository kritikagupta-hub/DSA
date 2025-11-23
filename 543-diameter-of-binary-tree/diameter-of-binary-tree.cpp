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
    pair<int,int> diameterFast(TreeNode* root){
        if(root == NULL){
            return {0,0};  // {diameter, height}
        }

        auto left = diameterFast(root->left);
        auto right = diameterFast(root->right);

        int leftDiameter = left.first;
        int rightDiameter = right.first;
        int throughRoot = left.second + right.second + 1;

        int diameter = max({leftDiameter, rightDiameter, throughRoot});
        int height = max(left.second, right.second) + 1;

        return {diameter, height};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        return diameterFast(root).first - 1;  // convert nodes → edges
    }
};
