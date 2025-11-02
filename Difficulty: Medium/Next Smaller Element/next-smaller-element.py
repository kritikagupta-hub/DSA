class Solution:
    def nextSmallerEle(self, arr):
        n = len(arr)
        stack = [-1]
        ans = [0] * n

        for i in range(n - 1, -1, -1):
            curr = arr[i]

            while stack[-1] >= curr:
                stack.pop()

            ans[i] = stack[-1]
            stack.append(curr)

        return ans
