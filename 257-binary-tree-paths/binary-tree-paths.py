# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res, sol = [], []
        def backtrack(node: Optional[TreeNode]):
            if not node:
                return

            sol.append(node.val)
            if not node.left and not node.right:
                res.append(sol[:])
                sol.pop()
                return

            backtrack(node.left)
            backtrack(node.right)
            sol.pop()       

        backtrack(root)
        for i in range(len(res)):
            res[i] = self.change_to_str(res[i])
        return res
    
    @staticmethod
    def change_to_str(arr: list[int]) -> str:
        return '->'.join(map(str, arr))
        