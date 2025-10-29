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
    vector<TreeNode*> res; // result vector
    unordered_map<string, int> mp; // map to store serialized subtrees

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }

    string serialize(TreeNode* node) {
        if (!node) return "#"; // base case for null

        // serialize left and right subtree
        string left = serialize(node->left);
        string right = serialize(node->right);

        // create serialization string for current node
        string serial = to_string(node->val) + "," + left + "," + right;

        // check frequency
        if (++mp[serial] == 2) {
            res.push_back(node); // duplicate found
        }

        return serial;
    }
};
