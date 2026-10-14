class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n : int = len(prices)
        buy : int = prices[0]
        profit : int = 0
        for i in range(0,n):
            if prices[i] < buy:
                buy = prices[i]
            profit = max(profit, prices[i] - buy)
        return profit