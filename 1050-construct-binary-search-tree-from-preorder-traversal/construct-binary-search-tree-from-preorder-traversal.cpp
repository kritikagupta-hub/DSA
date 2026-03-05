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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* BST(vector<int>& preorder,int& index,int lower,int upper){

    if(index==preorder.size()||preorder[index]<lower||preorder[index]>upper)
     return NULL;

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = BST(preorder,index,lower,root->val);
    root->right = BST(preorder,index,root->val,upper);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
          int index = 0;
        return BST(preorder,index,INT_MIN,INT_MAX);
        //return BST(preorder,0,INT_MIN,INT_MAX); ->cannot pass 0 directly to a   reference variable int& index in BST. You need to pass a variable initialized to 0.
    }
};