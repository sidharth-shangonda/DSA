class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        cur_sum=0
        mp = {}
        for i in range(0,len(nums)):
            if (target - nums[i]) in mp:
                return [mp[target-nums[i]],i]
            mp[nums[i]] = i
        return []