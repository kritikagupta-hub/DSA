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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // nodes[x][y] = list of node values at column x and row y
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q; // node, (x, y)

        if (root == NULL)
            return {};

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int x = temp.second.first;    // horizontal distance
            int y = temp.second.second;   // level

            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        for (auto& col : nodes) {
            vector<int> columnNodes;

            for (auto& level : col.second) {
                for (int val : level.second) {
                    columnNodes.push_back(val);
                }
            }

            ans.push_back(columnNodes);
        }

        return ans;
    }
};
