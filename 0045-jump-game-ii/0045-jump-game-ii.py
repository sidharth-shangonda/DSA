class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        far = 0
        curFar = far
        jump = 0
        for i in range(0,n):
            far = max(far, i + nums[i])
            if curFar == i:
                jump += 1
                curFar = far
                if(far >= n - 1):
                    return jump
        return jump