class Solution:
    def hIndex(self, citations: list[int]) -> int:
        if len(citations) ==0:
            return 0
        citations.sort()
        i : int = len(citations) - 1
        while i>=0 and citations[i] > len (citations) - i - 1 :
            i -= 1
        return len(citations) - i -1 