class Solution:
     def calculateSpan(self, arr: list[int]) -> list[int]:
        s = [(10**5 + 1, -1)]
        ans = []
        for i, a in enumerate(arr):
            while s[-1][0] <= a:
                s.pop()
            ans.append(i - s[-1][1])
            s.append((a, i))
        return ans
