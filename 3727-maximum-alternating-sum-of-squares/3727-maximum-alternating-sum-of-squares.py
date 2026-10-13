class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(0,n):
            if(nums[i] < 0):
                nums[i] *= -1
        nums.sort()
        mid = n // 2
        totalSum = 0
        for i in range(0,mid):
            totalSum -= (nums[i] ** 2)
        for i in range(mid,n):
            totalSum += (nums[i] ** 2)
        return totalSum