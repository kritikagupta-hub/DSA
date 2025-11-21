class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        l=len(nums)
        d={}
        for x in nums:
            if x not in d:
                d[x]=1
            else:
                return True
        return False          
        