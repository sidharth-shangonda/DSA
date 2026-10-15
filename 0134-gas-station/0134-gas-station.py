class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        n = len(cost)
        totalCost = 0
        maxCost = 0
        idx = 0
        curCost = 0
        for i in range(0,n):
            temp = gas[i] - cost[i]
            totalCost += temp
            curCost += temp
            if curCost < 0:
                idx = i + 1
                curCost = 0 
        if totalCost < 0:
            return -1
        return idx