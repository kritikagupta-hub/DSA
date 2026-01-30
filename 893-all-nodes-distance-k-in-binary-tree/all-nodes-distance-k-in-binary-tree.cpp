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
unordered_map<TreeNode*, TreeNode*> parent;
unordered_set<TreeNode*> vis;
int k;
vector<int> ans;

void addParent(TreeNode* node, TreeNode* parentNode)
{
    if(!node)
        return;
    parent[node] = parentNode;
    addParent(node->left, node);
    addParent(node->right, node);
}

void DFS(TreeNode* node, int dis)
{
    if(!node || vis.find(node) != vis.end())
        return;
    vis.insert(node);

    if(dis == k)
    {   
        ans.push_back(node->val);
        return;
    }

    DFS(parent[node], dis + 1);
    DFS(node->left, dis + 1);
    DFS(node->right, dis + 1);
}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        addParent(root, NULL);
        DFS(target, 0);
        return ans;
    }
};