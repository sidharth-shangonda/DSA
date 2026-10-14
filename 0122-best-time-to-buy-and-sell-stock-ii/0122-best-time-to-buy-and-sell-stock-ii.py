class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n : int = len(prices)
        buy : int = prices[0]
        profit : int = 0
        for i in range(1,n):
            if buy > prices[i]:
                buy = prices[i]
            profit += (prices[i] - buy)
            buy = prices[i]
        return profit