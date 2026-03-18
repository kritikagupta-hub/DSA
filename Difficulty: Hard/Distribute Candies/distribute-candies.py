'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def distCandy(self, root):
        ret=0
        def dfs(cur=root):
            nonlocal ret
            if not cur:
                return 0,0
            la,lb=dfs(cur.left)
            ra,rb=dfs(cur.right)
            candycnt=la+ra+cur.data
            nodecnt=lb+rb+1
            ret+=abs(la-lb)
            ret+=abs(ra-rb)
            return candycnt,nodecnt
        dfs()
        return ret