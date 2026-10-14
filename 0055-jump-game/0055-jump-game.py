class Solution:
    def canJump(self, nums: list[int]) -> bool:
        n : int = len(nums)
        i = 0
        maxIdx = 0
        while i < n:
            if maxIdx < i:
                return False
            maxIdx = max(maxIdx, i + nums[i])
            if(maxIdx >= n-1):
                return True
            i += 1
        return False