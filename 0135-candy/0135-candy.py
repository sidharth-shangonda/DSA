class Solution:
    def candy(self, ratings: list[int]) -> int:
        n : int = len(ratings)
        lr = [1] * n
        rl = [1] * n
        for i in range(1,n):
            if ratings[i-1] < ratings[i]:
                lr[i] = lr[i-1] + 1
        for i in range(n-2,-1,-1):
            if ratings[i] > ratings[ i + 1]:
                rl[i] = rl[i+1] + 1
            lr[i] = max(lr[i],rl[i])
        ans = 0
        for i in range(0,n):
            ans += lr[i]
        return ans