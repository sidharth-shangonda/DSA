class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        mp = {}
        for i in nums:
            if i in mp:
                return True
            mp[i]=1
        return False