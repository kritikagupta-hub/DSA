# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        node_list = []
        res = float(inf)
        def traverse(node: Optional[TreeNode]):
            if not node:
                return
            traverse(node.left)
            node_list.append(node.val)
            traverse(node.right)
        traverse(root)
        for i in range(len(node_list)-1):
            distance = abs(node_list[i+1]-node_list[i])
            res = min(res, distance)
        return res
        