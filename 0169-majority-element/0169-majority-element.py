class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        count : int = 1
        num : int = nums[0]
        for i in range(1 ,len(nums)):
            if count == 0:
                num = nums[i]
            if nums[i] == num:
                count += 1
            else :
                count -= 1
        return num